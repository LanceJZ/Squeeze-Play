#pragma once
#include "Enemy.h"

class EnemyOne : public Enemy
{
public:
	EnemyOne();
	virtual ~EnemyOne();

	bool Initialize();
	bool BeginRun(Camera* camera);

	void Update(float deltaTime);
	void Draw();

	void Spawn();

private:
	float Speed = 33.666f;
	float MaxSpeed = 33.666;
	float TurnSpeed = 0.25f;
	float MaxTurnSpeed = 0.25f;
	float RotateMagnitude = PI / 2;

	void Collide();
	void ChasePlayer();
};
