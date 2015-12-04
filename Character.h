#pragma once

#include "GameObject.h"
#include "Controller.h"

class Character : public GameObject
{
public:
	Character(const Vector2& localPosition, const char* dataAsset, LoadType loadType = LoadType::kData, BaseObject* parent = nullptr);
	~Character();

	void Update(DX::StepTimer const& timer) override;

	template <typename T>
	void SetCharacterController();

protected:
	std::unique_ptr<Controller> m_characterController;
};

template <typename T>
void Character::SetCharacterController()
{
	m_characterController.reset(new T(this));
}