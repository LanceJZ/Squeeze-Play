#pragma once
#include "EnemyFires.h"

class EnemyTwo : public EnemyFires
{
public:
	EnemyTwo();
	virtual ~EnemyTwo();

	bool Initialize();
	bool BeginRun(Camera* camera);

	void Update(float deltaTime);
	void Draw();

	void Spawn();

private:
	size_t DistanceTimerID = 0;
	float Speed = 22.666f;
	float MaxSpeed = 52.666;

	void ChangeVelocity();
	void Collide();
	void Fire();
};
