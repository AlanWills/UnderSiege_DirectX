#include "pch.h"
#include "ScreenManager.h"
#include "BaseObject.h"
#include "RectangleCollider.h"

#include <DirectXMath.h>


//-----------------------------------------------------------------------------------------------------------------------------------
BaseObject::BaseObject(const char* dataAsset, LoadType loadType, BaseObject* parent) :
BaseObject(Vector2(0, 0), Vector2(0, 0), dataAsset, loadType, parent)
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
BaseObject::BaseObject(const Vector2& localPosition, const char* dataAsset, LoadType loadType, BaseObject* parent) :
BaseObject(Vector2(0, 0), localPosition, dataAsset, loadType, parent)
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
BaseObject::BaseObject(const Vector2& size, const Vector2& localPosition, const char* dataAsset, LoadType loadType, BaseObject* parent) :
m_tag(L""),
m_localPosition(localPosition),
m_localRotation(0),
m_dataAsset(dataAsset),
m_loadType(loadType),
m_baseObjectData(nullptr),
m_parent(parent),
m_textureHandler(nullptr),
m_size(size),
m_mouseOver(false),
m_selected(false),
m_collider(nullptr),
m_active(false),
m_visible(false),
m_acceptsInput(false),
m_alive(false),
m_colour(Color(1, 1, 1, 1)),
m_opacity(1.0f)
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
BaseObject::~BaseObject()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseObject::LoadContent(ID3D11Device* device)
{
	m_textureHandler.reset(new Texture2D());

	// If we have set this flag to kNoLoad, we do not want to perform any loading of data or textures
	if (m_loadType == kNoLoad)
	{
		return;
	}

	const char* textureAsset = "";

	if (m_loadType == LoadType::kData)
	{
		m_baseObjectData.reset(new BaseObjectData());
		m_baseObjectData->LoadData(m_dataAsset);

		textureAsset = m_baseObjectData->GetTextureAsset();
	}
	else
	{
		textureAsset = m_dataAsset;
	}
	
	const wchar_t* wTextureAsset = GenericUtils::CharToWChar(textureAsset);
	m_textureHandler->Load(device, wTextureAsset);

	assert(m_textureHandler->GetTexture());

	// Put initialization code here
	if (m_size == Vector2::Zero && m_textureHandler.get())
	{
		m_size = m_textureHandler->GetDimensions();
	}

	delete[] wTextureAsset;
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseObject::Initialize()
{
	// All state variables for the object need to be set to true now that the object is about to be inserted into the game
	Create();
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseObject::AddCollider()
{
	m_collider.reset(new RectangleCollider(this));
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseObject::Update(DX::StepTimer const& timer)
{
	if (!m_active)
	{
		return;
	}

	// Put update code here
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseObject::Draw(SpriteBatch* spriteBatch, SpriteFont* spriteFont)
{
	if (!m_visible)
	{
		return;
	}

	// Put draw code here
	assert(m_textureHandler->GetTexture());
	spriteBatch->Draw(
		m_textureHandler->GetTexture(), 
		GetWorldPosition(), 
		nullptr, 
		m_colour * m_opacity, 
		GetWorldRotation(), 
		m_textureHandler->GetCentre(), 
		XMVectorDivide(m_size, m_textureHandler->GetDimensions()));
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseObject::HandleInput(DX::StepTimer const& timer, const Vector2& mousePosition)
{
	if (!m_acceptsInput)
	{
		return;
	}

	// Input handling code

	// We should have a collider - if an inherited class is reaching here without a collider, something is wrong
	assert(m_collider);

	// Work out whether the mouse is over the object using the collider and mouse in game position
	m_mouseOver = m_collider->CheckCollisionWith(mousePosition);

	// If mouse left button isn't clicked we do not need to change the selection state
	if (!ScreenManager::GetGameMouse().IsClicked(GameMouse::MouseButton::kLeftButton))
	{
		return;
	}

	// We have clicked the mouse left button so need to check the selection status
	if (m_mouseOver && !m_selected)
	{
		// Mouse is over the object and not already selected
		m_selected = true;
	}
	else
	{
		// Otherwise we have not clicked on the object so it is not selected
		m_selected = false;
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseObject::Create()
{
	m_alive = true;
	
	Show();
	AddCollider();
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseObject::Die()
{
	m_alive = false;

	Hide();
}


//-----------------------------------------------------------------------------------------------------------------------------------
const Vector2 BaseObject::GetWorldPosition() const
{
	if (!m_parent)
	{
		return m_localPosition;
	}

	// Horrible, but like this for optimization purposes
	return m_parent->GetWorldPosition() + Vector2::Transform(m_localPosition, Matrix::CreateRotationZ(GetWorldRotation()));
}


//-----------------------------------------------------------------------------------------------------------------------------------
const float BaseObject::GetWorldRotation() const
{
	if (!m_parent)
	{
		return m_localRotation;
	}

	return XMScalarModAngle(m_parent->GetWorldRotation() + m_localRotation);
}