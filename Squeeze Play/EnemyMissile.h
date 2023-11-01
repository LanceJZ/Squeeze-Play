#pragma once
#include "Enemy.h"

class EnemyMissile : public Enemy
{
public:
	EnemyMissile();
	virtual ~EnemyMissile();

	bool Initialize();
	bool BeginRun(Camera* camera);

	void Update(float deltaTime);
	void Draw();

private:

};