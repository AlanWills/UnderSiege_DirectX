#include "pch.h"
#include "GameObject.h"


//-----------------------------------------------------------------------------------------------------------------------------------
GameObject::GameObject(const char* dataAsset, BaseObject* parent) :
BaseObject(dataAsset, parent)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
GameObject::GameObject(Vector2 localPosition, const char* dataAsset, BaseObject* parent) :
BaseObject(localPosition, dataAsset, parent)
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
GameObject::GameObject(Vector2 size, Vector2 localPosition, const char* dataAsset, BaseObject* parent) :
BaseObject(size, localPosition, dataAsset, parent)
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
GameObject::~GameObject()
{
	
}
