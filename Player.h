#pragma once

#include "Character.h"
#include "Loadout.h"
#include "Gun.h"

class Player : public Character
{
public:
	Player(const Vector2& localPosition, const char* loadoutDataAsset, BaseObject* parent = nullptr);
	~Player();

	void LoadContent(ID3D11Device* device) override;
	void Initialize() override;

	const Loadout* GetLoadout() const { return m_loadout.get(); }

private:
	std::unique_ptr<Loadout> m_loadout;
	std::unique_ptr<Gun> m_gun;
};

