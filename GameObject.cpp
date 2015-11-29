#include "pch.h"
#include "GameObject.h"


//-----------------------------------------------------------------------------------------------------------------------------------
GameObject::GameObject(const char* dataAsset, LoadType loadType, BaseObject* parent) :
BaseObject(dataAsset, loadType, parent)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
GameObject::GameObject(Vector2 localPosition, const char* dataAsset, LoadType loadType, BaseObject* parent) :
BaseObject(localPosition, dataAsset, loadType, parent)
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
GameObject::GameObject(Vector2 size, Vector2 localPosition, const char* dataAsset, LoadType loadType, BaseObject* parent) :
BaseObject(size, localPosition, dataAsset, loadType, parent)
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
GameObject::~GameObject()
{
	
}
