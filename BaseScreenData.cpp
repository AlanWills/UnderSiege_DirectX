#include "pch.h"
#include "BaseScreenData.h"


//-----------------------------------------------------------------------------------------------------------------------------------
BaseScreenData::BaseScreenData() :
	m_document(nullptr)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
BaseScreenData::~BaseScreenData()
{
	delete m_document;
}


//-----------------------------------------------------------------------------------------------------------------------------------
void BaseScreenData::LoadData(const char* filename)
{
	m_document = new tinyxml2::XMLDocument();
	m_document->LoadFile(filename);
	assert(m_document);
}


//-----------------------------------------------------------------------------------------------------------------------------------
const char* BaseScreenData::GetBackgroundAsset() const
{
	return m_document->FirstChildElement("BackgroundTextureAsset")->GetText();
}