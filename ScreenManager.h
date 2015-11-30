#pragma once

#include "SpriteBatch.h"
#include "StepTimer.h"
#include "BaseScreen.h"
#include "GameMouse.h"
#include "KeyboardInput.h"

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
	std::unique_ptr<ID3D11Device> m_device;
	std::unique_ptr<ID3D11DeviceContext> m_deviceContext;

	// SpriteBatch
	std::unique_ptr<SpriteBatch> m_spriteBatch;

	// SpriteFont
	std::unique_ptr<SpriteFont> m_spriteFont;

	// Used for alpha blending sprites
	std::unique_ptr<CommonStates> m_states;

	// Screens
	std::list<BaseScreen*> m_activeScreens;
	
	// Container for screens about to be deleted
	std::list<BaseScreen*> m_screensToDelete;
};