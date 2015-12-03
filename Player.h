#pragma once

#include "Character.h"

class Player : public Character
{
public:
	Player(const Vector2& localPosition, const char* dataAsset, LoadType loadType = LoadType::kData, BaseObject* parent = nullptr);
	~Player();

	void Initialize() override;
};

