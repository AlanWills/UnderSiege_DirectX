#pragma once

#include "Texture2D.h"
#include "BaseObjectData.h"
#include "StepTimer.h"

using namespace DirectX::SimpleMath;

class BaseObject
{
public:
	enum LoadType
	{
		kData,
		kTexture
	};

	BaseObject(const char* dataAsset, LoadType = LoadType::kData, BaseObject* parent = nullptr);
	BaseObject(Vector2 localPosition, const char* dataAsset, LoadType = LoadType::kData, BaseObject* parent = nullptr);
	BaseObject(Vector2 size, Vector2 localPosition, const char* dataAsset, LoadType = LoadType::kData, BaseObject* parent = nullptr);
	
	virtual ~BaseObject();

	/// \brief Loads the data (if it exists) and texture for the object
	virtual void LoadContent(ID3D11Device* device);

	/// \brief Initializes data before update begins
	virtual void Initialize();

	/// \brief Update the logic of the object
	virtual void Update(DX::StepTimer const& timer);

	/// \brief Draw the object in world space
	virtual void Draw(SpriteBatch* spriteBatch);

	/// \brief Handle input from elsewhere and update this object's mouse over and selection status
	virtual void HandleInput(DX::StepTimer const& timer);

	/// \brief State Utility Functions
	bool IsActive() { return m_active; }
	bool IsVisible() { return m_visible; }
	bool AcceptsInput() { return m_acceptsInput; }
	bool IsAlive() { return m_alive; }

	void SetActive(bool active) { m_active = active; }
	void SetVisible(bool visible) { m_visible = visible; }
	void SetAcceptsInput(bool acceptsInput) { m_acceptsInput = acceptsInput; }
	void SetAlive(bool alive) { m_alive = alive; }
	
	void Create();
	void Die();

	/// \brief Transform utility functions
	Vector2 GetWorldPosition();
	float GetWorldRotation();

	// A string to identify the object
	std::wstring m_tag;

	// Local position from parent
	Vector2 m_localPosition;

	// Local rotation from parent
	float m_localRotation;

	// Texture and size
	Texture2D* m_textureHandler;
	Vector2 m_size;

	// State variables
	bool m_active;			// If true the object updates
	bool m_visible;			// If true the object is drawn
	bool m_acceptsInput;	// If true the object accepts input
	bool m_alive;			// If false the object will be destroyed

	// Colour variables
	Color m_colour;
	float m_opacity;

	// Used for handling input - variables to represent whether the mouse is over the object
	// And whether it is selected
	bool m_mouseOver;
	bool m_selected;

private:
	// Used to work out whether we should load an XML file or just a texture
	LoadType m_loadType;

	// Data - must be char* for tinyxml2 parser
	const char* m_dataAsset;
	BaseObjectData* m_baseObjectData;

	// Parent object
	BaseObject* m_parent;
};

