#pragma once

#include "ArmedCharacter.h"

class Squadmate : public ArmedCharacter
{
public:
	Squadmate(const Vector2& localPosition, const char* loadoutDataAsset, BaseObject* parent = nullptr);
	~Squadmate();

	void Initialize() override;
};