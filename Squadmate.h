#pragma once

#include "ArmedCharacter.h"

class Player;

class Squadmate : public ArmedCharacter
{
public:
	Squadmate(const Player* player, const Vector2& localPosition, const char* loadoutDataAsset, BaseObject* parent = nullptr);
	~Squadmate();

	void Initialize() override;

	const Player* GetPlayer() const { return m_player; }

private:
	const Player* m_player;
};