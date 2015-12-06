#include "pch.h"

#include "GameplayScreen.h"
#include "ScreenManager.h"


//-----------------------------------------------------------------------------------------------------------------------------------
GameplayScreen::GameplayScreen(ScreenManager* screenManager, const char* levelDataAsset) :
	BaseScreen(screenManager, levelDataAsset),
	m_tilemap(new Tilemap(GetDevice(), m_gameplayScreenData->GetTilemapDataAsset()))
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
GameplayScreen::~GameplayScreen()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void GameplayScreen::LoadContent()
{
	BaseScreen::LoadContent();

	m_tilemap->LoadData();
}


//-----------------------------------------------------------------------------------------------------------------------------------
void GameplayScreen::Initialize()
{
	BaseScreen::Initialize();

	m_tilemap->Initialize();
}


//-----------------------------------------------------------------------------------------------------------------------------------
void GameplayScreen::Update(DX::StepTimer const& timer)
{
	BaseScreen::Update(timer);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void GameplayScreen::DrawInGameObjects(SpriteBatch* spriteBatch, SpriteFont* spriteFont)
{
	m_tilemap->Draw(spriteBatch, spriteFont);

	BaseScreen::DrawInGameObjects(spriteBatch, spriteFont);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void GameplayScreen::HandleInput(DX::StepTimer const& timer)
{
	BaseScreen::HandleInput(timer);

	const Vector2& mousePosition = GetScreenManager()->GetGameMouse().GetInGamePosition();
	m_tilemap->HandleInput(timer, mousePosition);
}