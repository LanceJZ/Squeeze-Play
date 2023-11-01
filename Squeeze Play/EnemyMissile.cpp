#include "EnemyMissile.h"

EnemyMissile::EnemyMissile()
{
}

EnemyMissile::~EnemyMissile()
{
}

bool EnemyMissile::Initialize()
{
	Enemy::Initialize();

	return false;
}

bool EnemyMissile::BeginRun(Camera* camera)
{
	Enemy::BeginRun(camera);

	return false;
}

void EnemyMissile::Update(float deltaTime)
{
	Enemy::Update(deltaTime);

	ChasePlayer();
}

void EnemyMissile::Draw()
{
	Enemy::Draw();

}
