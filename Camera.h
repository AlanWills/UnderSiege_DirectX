#pragma once

using namespace DirectX::SimpleMath;

class Camera
{
public:
	enum CameraMode
	{
		kFree,
		kFixed,
		kFollow
	};

	Camera();
	~Camera();

	/// \brief Calculates and returns the view matrix based on the camera position and zoom
	Matrix GetViewMatrix() const;

	/// \brief Sets the camera mode 
	void SetCameraMode(const CameraMode cameraMode) { m_cameraMode = cameraMode; }

	/// \brief Converts a position on the screen to a position in game world space
	Vector2 ScreenToGameCoords(const Vector2 screenPosition);

	/// \brief Converts a position in game world space to screen space
	Vector2 GameToScreenCoords(const Vector2 gamePosition);

private:
	// Describes the behaviour of the camera - whether it can be manually moved or not
	CameraMode m_cameraMode;

	// Position of the camera
	Vector2 m_position;

	// Pan speed of the camera
	float m_panSpeed;

	// Zoom of the camera
	float m_zoom;
};

