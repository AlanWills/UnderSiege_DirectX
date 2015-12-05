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

private:
	/// \brief Typedefs
	typedef std::vector<std::unique_ptr<LoadoutUI>> LoadoutUIs;

	LoadoutUIs m_loadoutUI;
	std::vector<const char*> m_loadoutDataAssets;
};