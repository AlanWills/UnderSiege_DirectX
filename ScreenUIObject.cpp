#include "pch.h"
#include "ScreenUIObject.h"


//-----------------------------------------------------------------------------------------------------------------------------------
ScreenUIObject::ScreenUIObject(const char* dataAsset, LoadType loadType, BaseObject* parent, float lifeTime) :
	UIObject(dataAsset, loadType, parent, lifeTime)
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
ScreenUIObject::ScreenUIObject(Vector2 localPosition, const char* dataAsset, LoadType loadType, BaseObject* parent, float lifeTime) :
	UIObject(localPosition, dataAsset, loadType, parent)
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
ScreenUIObject::ScreenUIObject(Vector2 size, Vector2 localPosition, const char* dataAsset, LoadType loadType, BaseObject* parent, float lifeTime) :
	UIObject(size, localPosition, dataAsset, loadType, parent, lifeTime)
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
ScreenUIObject::~ScreenUIObject()
{
}
