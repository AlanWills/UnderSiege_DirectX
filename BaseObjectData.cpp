#include "pch.h"
#include "BaseObjectData.h"


BaseObjectData::BaseObjectData() :
	m_document(nullptr)
{
}


BaseObjectData::~BaseObjectData()
{
	delete m_document;
}

//-----------------------------------------------------------------------------------------------------------------------------------
void BaseObjectData::LoadData(const char* filename)
{
	m_document = new tinyxml2::XMLDocument();
	m_document->LoadFile(filename);
	assert(m_document);
}


//-----------------------------------------------------------------------------------------------------------------------------------
const char* BaseObjectData::GetTextureAsset() const
{
	return m_document->FirstChildElement("TextureAsset")->GetText();
}