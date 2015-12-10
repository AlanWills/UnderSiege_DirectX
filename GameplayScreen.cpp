#include "pch.h"

#include "GameplayScreen.h"
#include "ScreenManager.h"

#include "Player.h"
#include "Squadmate.h"


//-----------------------------------------------------------------------------------------------------------------------------------
GameplayScreen::GameplayScreen(ScreenManager* screenManager, const char* levelDataAsset) :
	BaseScreen(screenManager, levelDataAsset),
	m_tilemap(nullptr)
{
	AddGameObject(new Player(GetScreenCentre(), "HeavyGunner.xml"));
	AddGameObject(new Squadmate(Vector2(500, 500), "HeavyGunner.xml"));
}


//-----------------------------------------------------------------------------------------------------------------------------------
GameplayScreen::~GameplayScreen()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void GameplayScreen::LoadContent()
{
	BaseScreen::LoadContent();

	//m_tilemap.reset(new Tilemap(GetDevice(), m_gameplayScreenData->GetTilemapDataAsset()));
	//m_tilemap->LoadData();
}


//-----------------------------------------------------------------------------------------------------------------------------------
void GameplayScreen::Initialize()
{
	BaseScreen::Initialize();

	//m_tilemap->Initialize();
}


//-----------------------------------------------------------------------------------------------------------------------------------
void GameplayScreen::Update(DX::StepTimer const& timer)
{
	BaseScreen::Update(timer);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void GameplayScreen::DrawInGameObjects(SpriteBatch* spriteBatch, SpriteFont* spriteFont)
{
	//m_tilemap->Draw(spriteBatch, spriteFont);

	BaseScreen::DrawInGameObjects(spriteBatch, spriteFont);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void GameplayScreen::HandleInput(DX::StepTimer const& timer)
{
	BaseScreen::HandleInput(timer);

	const Vector2& mousePosition = GetScreenManager()->GetGameMouse().GetInGamePosition();
	//m_tilemap->HandleInput(timer, mousePosition);
}