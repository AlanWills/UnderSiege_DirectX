#include "pch.h"
#include "BaseObject.h"

#include <DirectXMath.h>


//-----------------------------------------------------------------------------------------------------------------------------------
BaseObject::BaseObject(std::wstring& dataAsset, BaseObject* parent) :
BaseObject(Vector2(0, 0), Vector2(0, 0), dataAsset, parent)
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
BaseObject::BaseObject(Vector2 localPosition, std::wstring& dataAsset, BaseObject* parent) :
BaseObject(Vector2(0, 0), localPosition, dataAsset, parent)
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
BaseObject::BaseObject(Vector2 size, Vector2 localPosition, std::wstring& dataAsset, BaseObject* parent) :
m_tag(L""),
m_localPosition(localPosition),
m_localRotation(0),
m_dataAsset(dataAsset),
m_parent(parent),
m_texture(nullptr),
m_size(size),
m_mouseOver(false),
m_selected(false),
m_active(false),
m_visible(false),
m_acceptsInput(false),
m_alive(false),
m_colour(Color(1, 1, 1, 1)),
m_opacity(0)
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
BaseObject::~BaseObject()
{
	delete m_texture;
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseObject::LoadContent(ID3D11Device* device)
{
	// Put data reading code here

	m_texture = new Texture2D();
	//m_texture->Load(device, m_dataAsset.c_str());

	assert(m_texture);

	if (m_size == Vector2::Zero)
	{
		m_size = m_texture->m_dimensions;
	}
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
void BaseObject::Draw(SpriteBatch* spriteBatch)
{
	if (!m_visible)
	{
		return;
	}

	// Put draw code here
	spriteBatch->Draw(m_texture->GetTexture(), GetWorldPosition(), nullptr, m_colour * m_opacity, GetWorldRotation(), m_texture->m_centre, XMVectorDivide(m_size, m_texture->m_dimensions));
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseObject::HandleInput(DX::StepTimer const& timer)
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