#pragma once

#include "UIObject.h"
#include "BaseObjectManager.h"

typedef std::unique_ptr<BaseObjectManager<UIObject>> UIObjects;

class Menu : public UIObject
{
public:
	Menu();
	~Menu();

	/// \brief Set ups initial UI before load and initialize functions are called
	void AddInitialUI() { }

	/// \brief Loads the content of all the objects we have already set up
	void Initialize() override;

	/// \brief Updates all the objects in the menu
	void Update(DX::StepTimer const& timer) override;

	/// \brief Draws all objects in the menu and the menu itself
	void Draw(SpriteBatch* spriteBatch, SpriteFont* spriteFont) override;

	/// \brief Handles the input of all elements in the menu and the menu object itself
	void HandleInput(DX::StepTimer const& timer, const Vector2& mousePosition) override;

	/// brief Shows, activates and accepts input for all elements in the menu and the menu itself
	void Show();

	/// \brief Hides, deactivates and disables input for all elements in the menu and the menu itself
	void Hide();

	/// \brief Destroys the menu and all it's sub menus
	void Die() override;

	/// \brief Wrapper functions for adding/removing in UI objects
	void AddUIObject(UIObject* inGameUIObject, bool load = false, bool initialize = false);
	void RemoveUIObject(UIObject* inGameUIObject);

private:
	/// \brief A container for UIObjects.  Will only be able to deal with
	/// the same type as this Menu (i.e. In-Game or Screen)
	UIObjects m_uiObjects;
};