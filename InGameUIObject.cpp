#include "pch.h"
#include "InGameUIObject.h"





//-----------------------------------------------------------------------------------------------------------------------------------
InGameUIObject::InGameUIObject(const char* dataAsset, LoadType loadType, BaseObject* parent, float lifeTime) :
	UIObject(dataAsset, loadType, parent, lifeTime)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
InGameUIObject::InGameUIObject(Vector2 localPosition, const char* dataAsset, LoadType loadType, BaseObject* parent, float lifeTime) :
	UIObject(localPosition, dataAsset, loadType, parent, lifeTime)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
InGameUIObject::InGameUIObject(Vector2 size, Vector2 localPosition, const char* dataAsset, LoadType loadType, BaseObject* parent, float lifeTime) :
	UIObject(size, localPosition, dataAsset, loadType, parent, lifeTime)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
InGameUIObject::~InGameUIObject()
{
}
