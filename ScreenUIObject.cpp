#include "pch.h"
#include "ScreenUIObject.h"


//-----------------------------------------------------------------------------------------------------------------------------------
ScreenUIObject::ScreenUIObject(std::wstring& dataAsset, BaseObject* parent, float lifeTime) :
	UIObject(dataAsset, parent, lifeTime)
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
ScreenUIObject::ScreenUIObject(Vector2 localPosition, std::wstring& dataAsset, BaseObject* parent, float lifeTime) :
	UIObject(localPosition, dataAsset, parent)
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
ScreenUIObject::ScreenUIObject(Vector2 size, Vector2 localPosition, std::wstring& dataAsset, BaseObject* parent, float lifeTime) :
	UIObject(size, localPosition, dataAsset, parent, lifeTime)
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
ScreenUIObject::~ScreenUIObject()
{
}
