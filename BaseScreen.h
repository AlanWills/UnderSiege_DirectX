#pragma once

#include "ScreenManager.h"
#include "BaseObjectManager.h"

#include "GameObject.h"

using namespace std;

class BaseScreen
{
public:
	BaseScreen(ScreenManager* screenManager, std::wstring& dataAsset);
	~BaseScreen();

	/// \brief Run when we started updating - good for initializing music etc.
	virtual void Begin();

protected:
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
	BaseObjectManager<GameObject> m_gameObjects;
};

