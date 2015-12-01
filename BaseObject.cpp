#include "pch.h"
#include "BaseObject.h"

#include <DirectXMath.h>


//-----------------------------------------------------------------------------------------------------------------------------------
BaseObject::BaseObject(const char* dataAsset, LoadType loadType, BaseObject* parent) :
BaseObject(Vector2(0, 0), Vector2(0, 0), dataAsset, loadType, parent)
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
BaseObject::BaseObject(Vector2 localPosition, const char* dataAsset, LoadType loadType, BaseObject* parent) :
BaseObject(Vector2(0, 0), localPosition, dataAsset, loadType, parent)
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
BaseObject::BaseObject(Vector2 size, Vector2 localPosition, const char* dataAsset, LoadType loadType, BaseObject* parent) :
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
	const char* textureAsset;

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

	m_textureHandler.reset(new Texture2D());
	
	const wchar_t* pwcsName;
	// required size
	int nChars = MultiByteToWideChar(CP_ACP, 0, textureAsset, -1, NULL, 0);
	// allocate it
	pwcsName = new wchar_t[nChars];
	MultiByteToWideChar(CP_ACP, 0, textureAsset, -1, (LPWSTR)pwcsName, nChars);

	m_textureHandler->Load(device, pwcsName);

	assert(m_textureHandler->GetTexture());

	if (m_size == Vector2::Zero)
	{
		m_size = m_textureHandler->m_dimensions;
	}

	delete[] pwcsName;
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseObject::Initialize()
{
	// Put initialization code here

	// All state variables for the object need to be set to true now that the object is about to be inserted into the game
	Create();
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
	spriteBatch->Draw(m_textureHandler->GetTexture(), GetWorldPosition(), nullptr, m_colour * m_opacity, GetWorldRotation(), m_textureHandler->m_centre, XMVectorDivide(m_size, m_textureHandler->m_dimensions));
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseObject::HandleInput(const Ray& ray, DX::StepTimer const& timer)
{
	if (!m_acceptsInput)
	{
		return;
	}

	// Put input handling code here
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseObject::Create()
{
	m_alive = true;
	m_active = true;
	m_visible = true;
	m_acceptsInput = true;
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseObject::Die()
{
	m_alive = false;
	m_active = false;
	m_visible = false;
	m_acceptsInput = false;
}


//-----------------------------------------------------------------------------------------------------------------------------------
Vector2  BaseObject::GetWorldPosition()
{
	if (!m_parent)
	{
		return m_localPosition;
	}

	// Horrible, but like this for optimization purposes
	return m_parent->GetWorldPosition() + Vector2::Transform(m_localPosition, Matrix::CreateRotationZ(GetWorldRotation()));
}


//-----------------------------------------------------------------------------------------------------------------------------------
float BaseObject::GetWorldRotation()
{
	if (!m_parent)
	{
		return m_localRotation;
	}

	return XMScalarModAngle(m_parent->GetWorldRotation() + m_localRotation);
}