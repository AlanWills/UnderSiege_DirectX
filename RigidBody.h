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
	void Update(DX::StepTimer const& timer);

	/// \brief Performs a full angular stop by setting the angular velocities and accelerations to 0
	void FullAngularStop();

	/// \brief Performs a full linear stop by setting the linear velocities and accelerations to Vector2::Zero
	void FullLinearStop();

	/// \brief Performs a full angular and linear stop immediately
	void FullStop();

	// Linear and Angular velocities
	Vector2 m_linearVelocity;
	float m_angularVelocity;

	// Linear and Angular accelerations
	Vector2 m_linearAcceleration;
	float m_angularAcceleration;

private:
	// The parent this rigidbody is attached to which we will affect
	GameObject* m_parent;
};