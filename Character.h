#pragma once

#include "GameObject.h"
#include "Controller.h"

class Character : public GameObject
{
public:
	Character(const Vector2& localPosition, const char* dataAsset, LoadType loadType = LoadType::kData, BaseObject* parent = nullptr);
	~Character();

	void Update(DX::StepTimer const& timer) override;
	void HandleInput(DX::StepTimer const& timer, const Vector2& mousePosition) override;

	template <typename T>
	void SetControllerAs();

	template <typename T>
	T* GetControllerAs() const;

protected:
	const Controller* GetController() const { return m_characterController.get(); }

private:
	std::unique_ptr<Controller> m_characterController;
};


template <typename T>
void Character::SetControllerAs()
{
	m_characterController.reset(new T(this));
}


template <typename T>
T* Character::GetControllerAs() const
{
	return dynamic_cast<T*>(m_characterController.get());
}