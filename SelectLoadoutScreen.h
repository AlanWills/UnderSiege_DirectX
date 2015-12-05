#pragma once

#include "BaseScreen.h"
#include "LoadoutUI.h"

class SelectLoadoutScreen : public BaseScreen
{
public:
	SelectLoadoutScreen(ScreenManager* screenManager, const char* dataAsset);
	~SelectLoadoutScreen();

private:
	/// \brief Typedefs
	typedef std::vector<LoadoutUI> LoadoutUIs;

	LoadoutUIs m_loadoutUI;
};