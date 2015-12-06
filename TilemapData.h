#pragma once

#include "BaseData.h"
#include "Tile.h"
#include <list>

class TilemapData : public BaseData
{

public:
	TilemapData(const char* dataAsset);
	~TilemapData();

	/// \brief Populates the inputted list with the tile data (better than dealing with having to return it
	void GetTiles(std::list<std::unique_ptr<Tile>>& tileData);
};