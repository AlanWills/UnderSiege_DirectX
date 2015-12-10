#pragma once

#include "ArmedCharacter.h"

class Enemy : public ArmedCharacter
{
public:
	Enemy(const Vector2& localPosition, const char* loadoutDataAsset, BaseObject* parent = nullptr);
	~Enemy();
};

