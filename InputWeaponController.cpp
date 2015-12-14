#include "pch.h"

#include "ScreenManager.h"

#include "InputWeaponController.h"
#include "Player.h"


//-----------------------------------------------------------------------------------------------------------------------------------
InputWeaponController::InputWeaponController(ArmedCharacter* armedCharacter) :
	WeaponController(armedCharacter)
{
	assert(dynamic_cast<Player*>(armedCharacter));
}


//-----------------------------------------------------------------------------------------------------------------------------------
InputWeaponController::~InputWeaponController()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void InputWeaponController::Update(DX::StepTimer const& timer)
{

}


//-----------------------------------------------------------------------------------------------------------------------------------
void InputWeaponController::HandleInput(DX::StepTimer const& timer, const Vector2& mousePosition)
{
	Gun* characterGun = GetCharacter()->GetGun();

	if (characterGun->AcceptsInput())
	{
		if (ScreenManager::GetGameMouse().IsPressed(GameMouse::MouseButton::kLeftButton))
		{
			// The fire function checks whether it can actually fire, so this does not need to check
			characterGun->Fire();
		}
	}
}