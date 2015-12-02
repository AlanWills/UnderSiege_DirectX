#include "pch.h"
#include "GameObject.h"
#include "ScreenManager.h"


//-----------------------------------------------------------------------------------------------------------------------------------
GameObject::GameObject(const char* dataAsset, LoadType loadType, BaseObject* parent) :
BaseObject(dataAsset, loadType, parent)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
GameObject::GameObject(const Vector2& localPosition, const char* dataAsset, LoadType loadType, BaseObject* parent) :
BaseObject(localPosition, dataAsset, loadType, parent)
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
GameObject::GameObject(const Vector2& size, const Vector2& localPosition, const char* dataAsset, LoadType loadType, BaseObject* parent) :
BaseObject(size, localPosition, dataAsset, loadType, parent)
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
GameObject::~GameObject()
{
	
}