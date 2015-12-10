#pragma once

#include "ArmedCharacter.h"


class Player : public ArmedCharacter
{
public:
	Player(const Vector2& localPosition, const char* loadoutDataAsset, BaseObject* parent = nullptr);
	~Player();

	void Initialize() override;
};

