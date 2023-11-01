#include "EnemyOne.h"

EnemyOne::EnemyOne()
{
}

EnemyOne::~EnemyOne()
{
}
bool EnemyOne::Initialize()
{
	Enemy::Initialize();

	//Scale = 1.0f;
	Radius = 15;

	return false;
}

bool EnemyOne::BeginRun(Camera* camera)
{
	Enemy::BeginRun(camera);

	return false;
}

void EnemyOne::Update(float deltaTime)
{
	Enemy::Update(deltaTime);

	ChasePlayer();
}

void EnemyOne::Draw()
{
	Enemy::Draw();

}

void EnemyOne::Spawn()
{
	Enemy::Spawn();

	float maxSpeed = 33.666f;
	float maxTurnSpeed = 0.25f;

	Speed = GetRandomFloat(maxSpeed * 0.5f, maxSpeed);
	TurnSpeed = GetRandomFloat(maxTurnSpeed * 0.5f, maxTurnSpeed);
	Rotation = AngleFromVectorZ(ThePlayer->Position);
}

void EnemyOne::Collide()
{
	Enemy::Collide();

	Explosions->Spawn(Position, 15.0f, 40.0f, 10, 1.5f, RED);
}