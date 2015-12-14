#pragma once

#include "BaseScreen.h"
#include "LoadoutUI.h"

class SelectLoadoutScreen : public BaseScreen
{
public:
	SelectLoadoutScreen(ScreenManager* screenManager, const char* dataAsset = "SelectLoadoutScreen.xml");
	~SelectLoadoutScreen();

	/// \brief Loads the screen data and also the LoadoutData that we are using in the game
	void LoadContent() override;
	
	void AddInitialUI() override;

	void Initialize() override;

	void DrawScreenObjects(SpriteBatch* spriteBatch, SpriteFont* spriteFont) override;

	void HandleInput(DX::StepTimer const& timer) override;

	static const std::vector<const char*>& GetLoadoutAssets()
	{
		static std::vector<const char*> m_loadoutDataAssets;
		m_loadoutDataAssets.push_back("HeavyGunner.xml");
		m_loadoutDataAssets.push_back("Sharpshooter.xml");

		return m_loadoutDataAssets;
	}

private:
	/// \brief Toggles the states of the loadouts so that only the current loadout UI is active, visible and accepts input
	void OnCurrentLoadoutChanged();

	/// \brief Typedefs
	typedef std::vector<std::unique_ptr<LoadoutUI>> LoadoutUIs;

	LoadoutUIs m_loadoutUI;
	int m_numLoadouts;

	int m_currentLoadout;
};