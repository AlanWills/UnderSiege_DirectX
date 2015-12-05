#pragma once

#include "BaseScreen.h"
#include "LoadoutUI.h"

class SelectLoadoutScreen : public BaseScreen
{
public:
	SelectLoadoutScreen(ScreenManager* screenManager, const char* dataAsset);
	~SelectLoadoutScreen();

	/// \brief Loads the screen data and also the LoadoutData that we are using in the game
	void LoadContent() override;

	void Initialize() override;

	void DrawScreenObjects(SpriteBatch* spriteBatch, SpriteFont* spriteFont) override;

	void HandleInput(DX::StepTimer const& timer) override;

private:
	/// \brief Toggles the states of the loadouts so that only the current loadout UI is active, visible and accepts input
	void OnCurrentLoadoutChanged();

	/// \brief Typedefs
	typedef std::vector<std::unique_ptr<LoadoutUI>> LoadoutUIs;

	LoadoutUIs m_loadoutUI;
	std::vector<const char*> m_loadoutDataAssets;
	size_t m_numLoadouts;

	size_t m_currentLoadout;
};