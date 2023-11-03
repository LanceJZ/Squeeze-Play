#pragma once
#include "EnemyFires.h"

class EnemyThree : public EnemyFires
{
public:
	EnemyThree();
	virtual ~EnemyThree();

	bool Initialize();
	bool BeginRun(Camera* camera);

	void Update(float deltaTime);
	void Draw();

	void Spawn();

private:

};
