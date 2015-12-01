#include "pch.h"
#include "Camera.h"
#include "ScreenManager.h"


//-----------------------------------------------------------------------------------------------------------------------------------
Camera::Camera() :
	m_cameraMode(CameraMode::kFixed),
	m_position(Vector2::Zero),
	m_panSpeed(300),
	m_zoom(1.0f)
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
Camera::~Camera()
{
}


//-----------------------------------------------------------------------------------------------------------------------------------
Matrix Camera::GetViewMatrix() const
{
	// It's -ve position because it is - don't change it
	return Matrix::CreateScale(m_zoom) * Matrix::CreateTranslation(-m_position.x, -m_position.y, 0);
}


//-----------------------------------------------------------------------------------------------------------------------------------
Vector2 Camera::ScreenToGameCoords(const Vector2 screenPosition)
{
	Vector2 screenCentre = ScreenManager::GetScreenCentre();
	Vector2 tmp = (m_position - screenCentre) / m_zoom;				/// This is here because apparently the '/' operator returns XMVECTOR2 not Vector2
	return m_position + screenCentre - (m_zoom - 1) * screenCentre + tmp;
}


//-----------------------------------------------------------------------------------------------------------------------------------
Vector2 Camera::GameToScreenCoords(const Vector2 gamePosition)
{
	Vector2 screenCentre = ScreenManager::GetScreenCentre();
	return screenCentre - m_position + (m_zoom - 1) * screenCentre + (gamePosition - screenCentre) * m_zoom;
}