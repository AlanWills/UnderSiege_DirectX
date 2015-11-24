#pragma once

#include "StepTimer.h"
#include "SpriteBatch.h"
#include <list>

using namespace std;
using namespace DirectX;

template <typename T> class BaseObjectManager
{
public:
	BaseObjectManager();
	~BaseObjectManager();

	/// \brief Adds necessary objects and loads content of all active objects
	void LoadContent();

	/// \brief Initializes all active objects
	void Initialize();

	/// \brief Update all active objects and add/remove any necessary objects
	void Update(DX::StepTimer const& timer);

	/// \brief Draws all active objects
	void Draw(SpriteBatch* spriteBatch);

	/// \brief Handles input for all active objects
	void HandleInput(DX::StepTimer const& timer);

	/// \brief Adds an object 
	void AddObject(T* objectToAdd, bool load = false, bool initialize = false);

	/// \brief Find an object with a specific tag
	T* FindObject(const std::wstring& tag);

	/// \brief Removes an object
	void RemoveObject(T* objectToRemove);

private:
	std::list<T*> m_objectsToAdd;
	std::list<T*> m_activeObjects;
	std::list<T*> m_objectsToRemove;
};


///////////// TEMPLATED FUNCTION DEFINITIONS

//-----------------------------------------------------------------------------------------------------------------------------------
template <typename T>
BaseObjectManager<T>::BaseObjectManager()
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
template <typename T>
BaseObjectManager<T>::~BaseObjectManager()
{
	for (T* object : m_objectsToAdd)
	{
		delete object;
	}

	for (T* object : m_activeObjects)
	{
		delete object;
	}

	for (T* object : m_objectsToRemove)
	{
		delete object;
	}

	m_objectsToAdd.clear();
	m_activeObjects.clear();
	m_objectsToRemove.clear();
}


//-----------------------------------------------------------------------------------------------------------------------------------
template <typename T>
void BaseObjectManager<T>::LoadContent()
{
	for (T* object : m_objectsToAdd)
	{
		m_activeObjects.push_back(object);
	}

	m_objectsToAdd.clear();

	for (T* object : m_activeObjects)
	{
		object->LoadContent();
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
template <typename T>
void BaseObjectManager<T>::Initialize()
{
	for (T* object : m_activeObjects)
	{
		object->Initialize();
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
template <typename T>
void BaseObjectManager<T>::Update(DX::StepTimer const& timer)
{
	for (T* object : m_objectsToAdd)
	{
		m_activeObjects.push_back(object);
	}

	m_objectsToAdd.clear();

	for (T* object : m_activeObjects)
	{
		if (object->IsAlive())
		{
			object->Update(timer);
		}
		else
		{
			RemoveObject(object);
		}
	}

	for (T* object : m_objectsToRemove)
	{
		m_activeObjects.remove(object);
		delete object;
	}

	m_objectsToRemove.clear();
}


//-----------------------------------------------------------------------------------------------------------------------------------
template <typename T>
void BaseObjectManager<T>::Draw(SpriteBatch* spriteBatch)
{
	for (T* object : m_activeObjects)
	{
		object->Draw(spriteBatch);
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
template <typename T>
void BaseObjectManager<T>::HandleInput(DX::StepTimer const& timer)
{
	for (T* object : m_activeObjects)
	{
		object->HandleInput(timer);
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
template <typename T>
void BaseObjectManager<T>::AddObject(T* objectToAdd, bool load, bool initialize)
{
	if (load)
	{
		objectToAdd->LoadContent();
	}

	if (initialize)
	{
		objectToAdd->Initialize();
	}

	m_activeObjects->push_back(objectToAdd);
}


//-----------------------------------------------------------------------------------------------------------------------------------
template <typename T>
T* BaseObjectManager<T>::FindObject(const std::wstring& tag)
{
	for (T* object : m_activeObjects)
	{
		if (object->m_tag == tag)
		{
			return object;
		}
	}

	for (T* object : m_objectsToAdd)
	{
		if (object->m_tag == tag)
		{
			return object;
		}
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
template <typename T>
void BaseObjectManager<T>::RemoveObject(T* objectToRemove)
{
	objectToRemove->Die();
	m_objectsToRemove.push_back(objectToRemove);
}

