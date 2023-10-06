#pragma once
#include "Model3D.h"

class EnemyThree : public Model3D
{
public:
	EnemyThree();
	virtual ~EnemyThree();

	bool Initialize();
	bool BeginRun(Camera* camera);

	void Update(float deltaTime);
	void Draw();

private:

};
