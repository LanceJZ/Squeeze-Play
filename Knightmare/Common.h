#pragma once
#include <random>
#include "raylib.h"
#include "raymath.h"

#define MAX(a, b) ((a)>(b)? (a) : (b))
#define MIN(a, b) ((a)<(b)? (a) : (b))

class Common
{
public:
	float GameWindowHalfWidth = { 0 };
	float GameWindowHalfHeight = { 0 };

	virtual bool Initialize();
	virtual bool BeginRun();
	virtual void Update();
	virtual void Draw2D();
	float GetRandomScreenY();
	float GetRandomFloat(float min, float max);
	float GetRandomRadian();
	float RotateTowardsTargetZ(Vector3 origin, Vector3 target, float facingAngle,
		float magnitude);
	float GetAngleFromVectorsZ(Vector3 origin, Vector3 target);
	Vector3 GetRandomVelocity(float speed);
	Vector3 GetRandomVelocity(float speed, float radianDirection);
	Vector3 GetVelocityFromAngleZ(float rotation, float magnitude);

private:
	std::random_device RandomDevice;
};