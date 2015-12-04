#pragma once

class BaseObject;

using namespace DirectX;
using namespace DirectX::SimpleMath;

class MathUtils
{
public:
	MathUtils();
	~MathUtils();

	static const float GetAngleBetweenObjectAndWorldSpaceVector(const BaseObject* object, const Vector2& v);
};

