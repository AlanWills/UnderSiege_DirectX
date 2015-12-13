#pragma once

#include "Controller.h"

class Squadmate;

class SquadmateController : public Controller
{
public:
	enum MoveBehaviour
	{
		kWait,
		kMove,
		kFollow,
		kFlee,
	};

	SquadmateController(Character* parent);
	~SquadmateController();

	void Update(DX::StepTimer const& timer) override;
	void HandleInput(DX::StepTimer const& timer, const Vector2& mousePosition) override;
	
	void SetState(const MoveBehaviour moveBehaviour) { m_currentBehaviour = moveBehaviour; }
	void SetFollowDestination(const Vector2* followDestination) { m_followDestination = followDestination; }

private:
	/// \brief Follow a certain position keeping a certain offset
	void Follow();

	/// \brief Sets a destination vector which the squadmate will be moved towards
	void Move();

	Squadmate* m_squadmate;
	
	/// \brief Private variables used for the behaviours
	Vector2 m_moveDestination;								// Used for the move behaviour
	const Vector2* m_followDestination;						// Pointer to a Vector2 we will use to follow - probably the Player's world position

	/// \brief Our current behaviour state
	MoveBehaviour m_currentBehaviour;
};

