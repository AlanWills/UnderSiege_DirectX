#pragma once

#include "GameObject.h"
#include "MovementController.h"

class Character : public GameObject
{
public:
	Character(const Vector2& localPosition, const char* dataAsset, LoadType loadType = LoadType::kData, BaseObject* parent = nullptr);
	~Character();

	void Update(DX::StepTimer const& timer) override;
	void HandleInput(DX::StepTimer const& timer, const Vector2& mousePosition) override;

protected:
	/// \brief Returns a pointer to the newly set up movement controller
	template <typename T>
	T* SetMovementControllerAs();

	template <typename T>
	T* GetMovementControllerAs() const;

	const MovementController* GetMovementController() const { return m_characterController.get(); }

private:
	std::unique_ptr<MovementController> m_characterController;
};


template <typename T>
T* Character::SetMovementControllerAs()
{
	m_characterController.reset(new T(this));
	return dynamic_cast<T*>(m_characterController.get());
}


template <typename T>
T* Character::GetMovementControllerAs() const
{
	return dynamic_cast<T*>(m_characterController.get());
}