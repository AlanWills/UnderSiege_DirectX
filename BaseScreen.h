#pragma once

#include "BaseObjectManager.h"

#include "GameObject.h"
#include "UIObject.h"

#include "BaseScreenData.h"

using namespace std;

class ScreenManager;

class BaseScreen
{
public:
	BaseScreen(ScreenManager* screenManager, const char* dataAsset);
	virtual ~BaseScreen();

	/// \brief Adds initial UI before the load context and initialize steps
	/// Adds a title automatically from the XML Display Name element
	virtual void AddInitialUI();

	/// \brief Loads the content of all the objects we have already set up
	virtual void LoadContent();

	/// \brief Initializes all of the objects we have already set up
	virtual void Initialize();

	/// \brief Run when we started updating - good for initializing music etc.
	virtual void Begin();

	/// \brief Updates all the objects in the screen (game, then gameUI, then screenUI)
	virtual void Update(DX::StepTimer const& timer);

	/// \brief Draws all the objects in the screen that are dependent on camera and game world (game, then gameUI)
	virtual void DrawInGameObjects(SpriteBatch* spriteBatch, SpriteFont* spriteFont);

	/// \brief Draws all the objects in the screen that are not dependent on camera or game world (Screen UI)
	virtual void DrawScreenObjects(SpriteBatch* spriteBatch, SpriteFont* spriteFont);

	/// \brief Draws the background
	void DrawBackground(SpriteBatch* spriteBatch, SpriteFont* spriteFont);

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
	void AddInGameUIObject(UIObject* inGameUIObject, bool load = false, bool initialize = false);
	void RemoveInGameUIObject(UIObject* inGameUIObject);

	/// \brief Wrapper functions for adding/removing screen UI objects
	void AddScreenUIObject(UIObject* screenUIObject, bool load = false, bool initialize = false);
	void RemoveScreenUIObject(UIObject* screenUIObject);

protected:
	void Transition(BaseScreen* transitionTo);

	/// \brief Get a pointer to the ScreenManager
	ScreenManager* GetScreenManager() const { return m_screenManager; }
	Microsoft::WRL::ComPtr<ID3D11Device> GetDevice() const { return m_device; }

private:
	/// \brief Typedefs
	typedef BaseObjectManager<GameObject> GameObjects;
	typedef BaseObjectManager<UIObject> UIObjects;

	// ScreenManager pointer
	ScreenManager* m_screenManager;

	// Device pointer
	Microsoft::WRL::ComPtr<ID3D11Device> m_device;

	// Path to an XML document containing data about this screen - must be char* for tinyxml2 parser
	const char* m_dataAsset;

	// Screen data
	std::unique_ptr<BaseScreenData> m_baseScreenData;

	// States variables
	bool m_begun;			// If false, we will run the Begin function in the first loop of this screen's update
	bool m_active;			// If true the screen updates
	bool m_visible;			// If true the screen renders
	bool m_acceptsInput;	// If true the screen handles and accepts input
	bool m_alive;			// if false the screen will be removed by the screen manager

	// Object managers
	std::unique_ptr<GameObjects>		m_gameObjects;			// Handles all the game objects
	std::unique_ptr<UIObjects>			m_inGameUIObjects;		// Handles all the in game (camera dependent) UI Objects
	std::unique_ptr<UIObjects>			m_screenUIObjects;		// Handles all the screen UI

	// Background
	std::unique_ptr<UIObject> m_background;
};

