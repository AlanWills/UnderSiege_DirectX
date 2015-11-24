#include "pch.h"
#include "Texture2D.h"
#include "WICTextureLoader.h"

//-----------------------------------------------------------------------------------------------------------------------------------
Texture2D::Texture2D() :
m_texture(nullptr),
m_centre(Vector2(0, 0)),
m_dimensions(Vector2(0, 0))
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
Texture2D::~Texture2D()
{
	m_texture->Release();
	delete m_texture;
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Texture2D::Load(ID3D11Device* device, const wchar_t* filename)
{
	ID3D11Resource* resource;
	DX::ThrowIfFailed(CreateWICTextureFromFile(
		device,
		filename,
		&resource,
		&m_texture));

	ID3D11Texture2D* texture = dynamic_cast<ID3D11Texture2D*>(resource);
	if (texture)
	{
		CD3D11_TEXTURE2D_DESC desc;
		texture->GetDesc(&desc);

		m_centre = Vector2(desc.Width * 0.5f, desc.Height * 0.5f);
		m_dimensions = Vector2(desc.Width, desc.Height);
	}
}
