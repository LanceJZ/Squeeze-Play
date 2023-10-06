#include "EnemyThree.h"

EnemyThree::EnemyThree()
{
}

EnemyThree::~EnemyThree()
{
}

bool EnemyThree::Initialize()
{
	Model3D::Initialize();

	return false;
}

bool EnemyThree::BeginRun(Camera* camera)
{
	Model3D::BeginRun(camera);

	return false;
}

void EnemyThree::Update(float deltaTime)
{
	Model3D::Update(deltaTime);

}

void EnemyThree::Draw()
{
	Model3D::Draw();

}
