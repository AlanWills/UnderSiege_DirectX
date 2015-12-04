#include "pch.h"

#include "Controller.h"
#include "Character.h"


//-----------------------------------------------------------------------------------------------------------------------------------
Controller::Controller(Character* parent) :
	m_parent(parent)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
Controller::~Controller()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Controller::LookInLocalSpaceDirection(const Vector2& localSpaceDir)
{
	XMVECTOR angles = XMVector2AngleBetweenVectors(Vector2(0, -1), localSpaceDir);
	m_parent->m_localRotation = XMVectorGetZ(angles);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Controller::LookAtLocalSpacePosition(const Vector2& localSpacePosition)
{
	XMVECTOR angles = XMVector2AngleBetweenVectors(Vector2(0, -1), localSpacePosition);
	m_parent->m_localRotation = XMVectorGetZ(angles);
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Controller::LookInWorldSpaceDirection(const Vector2& worldSpaceDir)
{
	// If the object this controller is attached to has a parent, return it's world rotation, otherwise just set it to 0
	float parentWorldRotation = m_parent->GetParent() ? m_parent->GetParent()->GetWorldRotation() : 0;

	// Get the world space rotation needed to point in the inputted direction
	float rotation = atan2(worldSpaceDir.x, -worldSpaceDir.y);
	XMScalarModAngle(rotation);

	m_parent->m_localRotation = rotation - parentWorldRotation;
}


//-----------------------------------------------------------------------------------------------------------------------------------
void Controller::LookAtWorldSpacePosition(const Vector2& worldSpacePosition)
{
	// If the object this controller is attached to has a parent, return it's world rotation, otherwise just set it to 0
	float parentWorldRotation = m_parent->GetParent() ? m_parent->GetParent()->GetWorldRotation() : 0;

	// We need to set the local rotation of the attached object to mimic the effect of changing it's world space rotation
	float rotation = MathUtils::GetAngleBetweenObjectAndWorldSpaceVector(m_parent, worldSpacePosition);

	m_parent->m_localRotation = rotation - parentWorldRotation;
}


//-----------------------------------------------------------------------------------------------------------------------------------
const Vector2 Controller::GetLocalLookDirection() const
{
	return Vector2::TransformNormal(Vector2(0, -1), Matrix::CreateRotationZ(m_parent->m_localRotation));
}


//-----------------------------------------------------------------------------------------------------------------------------------
const Vector2 Controller::GetWorldLookDirection() const
{
	return Vector2::TransformNormal(Vector2(0, -1), Matrix::CreateRotationZ(m_parent->GetWorldRotation()));
}