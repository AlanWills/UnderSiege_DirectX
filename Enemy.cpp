#include "pch.h"

#include "Enemy.h"


//-----------------------------------------------------------------------------------------------------------------------------------
Enemy::Enemy(const Vector2& localPosition, const char* loadoutDataAsset, BaseObject* parent) :
	ArmedCharacter(localPosition, loadoutDataAsset, parent)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
Enemy::~Enemy()
{
}
