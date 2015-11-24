#pragma once

#include "SpriteBatch.h"
#include "StepTimer.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

class ScreenManager
{
public:
	ScreenManager(ID3D11Device* device, ID3D11DeviceContext* deviceContext);
	~ScreenManager();

	// Five basic game functions
	void LoadContent();
	void Initialize();
	void Update(DX::StepTimer const& timer);
	void Render();
	void HandleInput(DX::StepTimer const& timer);

	// Utility functions
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
};

