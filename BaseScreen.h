#pragma once

#include "BaseObjectManager.h"

#include "GameObject.h"
#include "ScreenUIObject.h"
#include "InGameUIObject.h"

using namespace std;

class ScreenManager;

class BaseScreen
{
public:
	BaseScreen(ScreenManager* screenManager, std::wstring& dataAsset);
	~BaseScreen();

	/// \brief Loads the content of all the objects we have already set up
	virtual void LoadContent();

	/// \brief Initializes all of the objects we have already set up
	virtual void Initialize();

	/// \brief Run when we started updating - good for initializing music etc.
	virtual void Begin();

	/// \brief Updates all the objects in the screen (game, then gameUI, then screenUI)
	virtual void Update(DX::StepTimer const& timer);

	/// \brief Draws all the objects in the screen that are dependent on camera and game world (game, then gameUI)
	virtual void DrawInGameObjects(SpriteBatch* spriteBatch);

	/// \brief Draws all the objects in the screen that are not dependent on camera or game world (Screen UI)
	virtual void DrawScreenObjects(SpriteBatch* spriteBatch);

	/// \brief Handles all the input for the objects in the screen (game, then gameUI, then screenUI)
	virtual void HandleInput(DX::StepTimer const& timer);

	/// \brief Utility function to let the screen update, draw and handle input
	void Show();

	/// \brief Utility function to stop the screen updating, drawing and handling input
	void Hide();

	/// \brief Wrapper functions for adding/removing game objects
	void AddGameObject(GameObject* gameObject, bool load = false, bool initialize = false);
	void RemoveGameObject(GameObject* gameObject);

	/// \brief Wrapper functions for adding/removing in game UI objects
	void AddInGameUIObject(InGameUIObject* inGameUIObject, bool load = false, bool initialize = false);
	void RemoveInGameUIObject(InGameUIObject* inGameUIObject);

	/// \brief Wrapper functions for adding/removing screen UI objects
	void AddScreenUIObject(ScreenUIObject* screenUIObject, bool load = false, bool initialize = false);
	void RemoveScreenUIObject(ScreenUIObject* screenUIObject);

protected:
	void Transition(BaseScreen* transitionTo);

	// ScreenManager pointer
	ScreenManager* m_screenManager;

private:
	// Path to an XML document containing data about this screen
	std::wstring m_dataAsset;

	// States variables
	bool m_begun;			// If false, we will run the Begin function in the first loop of this screen's update
	bool m_active;			// If true the screen updates
	bool m_visible;			// If true the screen renders
	bool m_acceptsInput;	// If true the screen handles and accepts input
	bool m_alive;			// if false the screen will be removed by the screen manager

	// Object managers
	BaseObjectManager<GameObject>		m_gameObjects;			// Handles all the game objects
	BaseObjectManager<InGameUIObject>	m_inGameUIObjects;		// Handles all the in game (camera dependent) UI Objects
	BaseObjectManager<ScreenUIObject>	m_screenUIObjects;		// Handles all the screen UI
};

