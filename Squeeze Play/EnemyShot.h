#pragma once
#include "Enemy.h"

class EnemyShot : public Enemy
{
public:
	EnemyShot();
	virtual ~EnemyShot();

	bool Initialize();
	bool BeginRun(Camera* camera);

	void Update(float deltaTime);
	void Draw();

	void Spawn(Vector3 pos, Vector3 vel, float timerAmount);

private:
	size_t ShotTimerID = 0;

	bool CheckCollision();
	void Collide();
};
