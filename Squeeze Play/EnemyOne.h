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

	void Collide();
};
