#include "pch.h"
#include "RigidBody.h"
#include "GameObject.h"


//-----------------------------------------------------------------------------------------------------------------------------------
RigidBody::RigidBody(GameObject* parent)
	: m_parent(parent),
	m_angularAcceleration(0),
	m_angularVelocity(0),
	m_linearAcceleration(Vector2::Zero),
	m_linearVelocity(Vector2::Zero)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
RigidBody::~RigidBody()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void RigidBody::Update(DX::StepTimer const& timer)
{
	float elapsedSeconds = (float)timer.GetElapsedSeconds();

	// Update the rotation and angular components
	m_angularVelocity += m_angularAcceleration * elapsedSeconds;
	m_parent->m_localRotation += m_angularVelocity * elapsedSeconds;

	// Update the position and linear components (it IS minus because of the screen coords
	m_linearVelocity += m_linearAcceleration * elapsedSeconds;
	m_parent->m_localPosition -= Vector2::Transform(m_linearVelocity, Matrix::CreateRotationZ(m_parent->m_localRotation)) * elapsedSeconds;
}


//-----------------------------------------------------------------------------------------------------------------------------------
void RigidBody::FullAngularStop()
{
	m_angularAcceleration = 0;
	m_angularVelocity = 0;
}


//-----------------------------------------------------------------------------------------------------------------------------------
void RigidBody::FullLinearStop()
{
	m_linearAcceleration = Vector2::Zero;
	m_linearVelocity = Vector2::Zero;
}


//-----------------------------------------------------------------------------------------------------------------------------------
void RigidBody::FullStop()
{
	FullAngularStop();
	FullLinearStop();
}