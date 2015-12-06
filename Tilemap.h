#pragma once

#include "BaseObjectManager.h"

#include "Tile.h"
#include "TilemapData.h"

class Tilemap
{
public:
	Tilemap(Microsoft::WRL::ComPtr<ID3D11Device> device, const char* tilemapDataAsset);
	~Tilemap();

	void LoadData();
	void Initialize();
	void Update(DX::StepTimer const& timer);
	void Draw(SpriteBatch* spriteBatch, SpriteFont* spriteFont);
	void HandleInput(DX::StepTimer const& timer, const Vector2& mousePosition);

private:
	/// \brief Typedefs
	typedef std::unique_ptr<BaseObjectManager<Tile>> Tiles;

	// Holds the tiles in the tilemap
	Tiles							m_tiles;

	// Will be used to obtain the information to create the Tiles
	std::unique_ptr<TilemapData>	m_tilemapData;
};

