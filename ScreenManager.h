#pragma once

#include "SpriteBatch.h"
#include "StepTimer.h"
#include "BaseScreen.h"
#include "GameMouse.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

class ScreenManager
{
public:
	ScreenManager(ID3D11Device* device, ID3D11DeviceContext* deviceContext, float screenWidth, float screenHeight);
	~ScreenManager();

	// Five basic game functions
	void LoadContent();
	void Initialize();
	void Update(DX::StepTimer const& timer);
	void Draw();
	void HandleInput(DX::StepTimer const& timer);

	/// \brief Add a screen (will automatically load and initialize for you)
	void AddScreen(BaseScreen* screenToAdd);
	void RemoveScreen(BaseScreen* screenToAdd);

	/// \brief Utility function for obtaining the centre of back buffer
	static Vector2 GetScreenCentre();

	// Viewport
	CD3D11_VIEWPORT m_viewport;

private:
	// General device and device context we get from creation - will need these for a lot of things
	ID3D11Device* m_device;
	ID3D11DeviceContext* m_deviceContext;

	// SpriteBatch
	SpriteBatch* m_spriteBatch;

	// Used for alpha blending sprites
	CommonStates* m_states;

	// Screens
	std::list<BaseScreen*> m_screensToAdd;
	std::list<BaseScreen*> m_activeScreens;
	std::list<BaseScreen*> m_screensToRemove;

	// Mouse
	GameMouse m_gameMouse;
};