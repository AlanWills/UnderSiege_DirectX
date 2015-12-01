#pragma once

#include "StepTimer.h"
#include "SpriteBatch.h"
#include <DirectXCollision.h>
#include <list>

using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;

template <typename T> class BaseObjectManager
{
public:
	BaseObjectManager(Microsoft::WRL::ComPtr<ID3D11Device> device);
	~BaseObjectManager();

	/// \brief Adds necessary objects and loads content of all active objects
	void LoadContent();

	/// \brief Initializes all active objects
	void Initialize();

	/// \brief Update all active objects and add/remove any necessary objects
	void Update(DX::StepTimer const& timer);

	/// \brief Draws all active objects
	void Draw(SpriteBatch* spriteBatch, SpriteFont* spriteFont);

	/// \brief Handles input for all active objects
	void HandleInput(const Ray& ray, DX::StepTimer const& timer);

	/// \brief Adds an object 
	void AddObject(T* objectToAdd, bool load = false, bool initialize = false);

	/// \brief Find an object with a specific tag
	T* FindObject(const std::wstring& tag);

	/// \brief Removes an object
	void RemoveObject(T* objectToRemove);

private:
	std::list<T*> m_activeObjects;
	std::list<T*> m_objectsToDelete;

	Microsoft::WRL::ComPtr<ID3D11Device> m_device;
};


///////////// TEMPLATED FUNCTION DEFINITIONS

//-----------------------------------------------------------------------------------------------------------------------------------
template <typename T>
BaseObjectManager<T>::BaseObjectManager(Microsoft::WRL::ComPtr<ID3D11Device> device) :
	m_device(device)
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
template <typename T>
BaseObjectManager<T>::~BaseObjectManager()
{
	for (T* object : m_activeObjects)
	{
		delete object;
	}

	for (T* object : m_objectsToDelete)
	{
		delete object;
	}

	m_activeObjects.clear();
	m_objectsToDelete.clear();
}


//-----------------------------------------------------------------------------------------------------------------------------------
template <typename T>
void BaseObjectManager<T>::LoadContent()
{
	for (T* object : m_activeObjects)
	{
		object->LoadContent(m_device.Get());
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

	for (T* object : m_objectsToDelete)
	{
		m_activeObjects.remove(object);
		delete object;
	}

	m_objectsToDelete.clear();
}


//-----------------------------------------------------------------------------------------------------------------------------------
template <typename T>
void BaseObjectManager<T>::Draw(SpriteBatch* spriteBatch, SpriteFont* spriteFont)
{
	for (T* object : m_activeObjects)
	{
		object->Draw(spriteBatch, spriteFont);
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
template <typename T>
void BaseObjectManager<T>::HandleInput(const Ray& ray, DX::StepTimer const& timer)
{
	for (T* object : m_activeObjects)
	{
		object->HandleInput(ray, timer);
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------
template <typename T>
void BaseObjectManager<T>::AddObject(T* objectToAdd, bool load, bool initialize)
{
	if (load)
	{
		objectToAdd->LoadContent(m_device.Get());
	}

	if (initialize)
	{
		objectToAdd->Initialize();
	}

	m_activeObjects.push_back(objectToAdd);
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
}


//-----------------------------------------------------------------------------------------------------------------------------------
template <typename T>
void BaseObjectManager<T>::RemoveObject(T* objectToRemove)
{
	objectToRemove->Die();
	m_objectsToDelete.push_back(objectToRemove);
}

