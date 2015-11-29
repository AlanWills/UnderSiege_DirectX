#include "pch.h"
#include "InGameUIObject.h"





//-----------------------------------------------------------------------------------------------------------------------------------
InGameUIObject::InGameUIObject(const char* dataAsset, BaseObject* parent, float lifeTime) :
	UIObject(dataAsset, parent, lifeTime)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
InGameUIObject::InGameUIObject(Vector2 localPosition, const char* dataAsset, BaseObject* parent, float lifeTime) :
	UIObject(localPosition, dataAsset, parent, lifeTime)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
InGameUIObject::InGameUIObject(Vector2 size, Vector2 localPosition, const char* dataAsset, BaseObject* parent, float lifeTime) :
	UIObject(size, localPosition, dataAsset, parent, lifeTime)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
InGameUIObject::~InGameUIObject()
{
}
