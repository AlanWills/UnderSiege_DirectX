#pragma once

#include "StepTimer.h"

using namespace::DirectX;
using namespace::DirectX::SimpleMath;

class GameObject;

class RigidBody
{
public:
	RigidBody(GameObject* parent);
	~RigidBody();

	/// \brief Updates the local position and rotation of the GameObject this rigid body is linked to by using the linear and angular velocities and accelerations
	/// It WILL take into account elapsed time
	void Update(DX::StepTimer const& timer);

	/// \brief Performs a full angular stop by setting the angular velocities and accelerations to 0
	void FullAngularStop();

	/// \brief Performs a full linear stop by setting the linear velocities and accelerations to Vector2::Zero
	void FullLinearStop();

	/// \brief Performs a full angular and linear stop immediately
	void FullStop();

	/// \brief Linear and Angular velocities - DO NOT MULTIPLY BY GAME TIME WHEN SETTING
	Vector2 m_linearVelocity;
	float m_angularVelocity;

	// Linear and Angular accelerations - DO NOT MULTIPLY BY GAME TIME WHEN SETTING
	Vector2 m_linearAcceleration;
	float m_angularAcceleration;

private:
	// The parent this rigidbody is attached to which we will affect
	GameObject* m_parent;
};