#pragma once

#include "BaseScreen.h"
#include "Tilemap.h"
#include "GameplayScreenData.h"

class GameplayScreen : public BaseScreen
{
public:
	GameplayScreen(const char* loadoutAsset, ScreenManager* screenManager, const char* levelDataAsset);
	~GameplayScreen();

	void LoadContent() override;

	/// \brief Do not want to add title or background to this screen
	void AddInitialUI() override { }

	void Initialize() override;
	void Update(DX::StepTimer const& timer) override;
	void DrawInGameObjects(SpriteBatch* spriteBatch, SpriteFont* spriteFont) override;
	void HandleInput(DX::StepTimer const& timer) override;

private:
	/// \brief Gameplay Screen Data pointer
	std::unique_ptr<GameplayScreenData> m_gameplayScreenData;

	/// \brief Tilemap for this level
	std::unique_ptr<Tilemap> m_tilemap;
};