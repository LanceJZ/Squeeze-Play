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

	Speed = GetRandomFloat(MaxSpeed * 0.5f, MaxSpeed);
	TurnSpeed = GetRandomFloat(MaxTurnSpeed * 0.5f, MaxTurnSpeed);

	Rotation = AngleFromVectorZ(ThePlayer->Position);
}

void EnemyOne::Collide()
{
	Enemy::Collide();

	Explosions->Spawn(Position, 15.0f, 40.0f, 10, 1.5f, RED);
}

void EnemyOne::ChasePlayer()
{
	RotateVelocity(ThePlayer->Position, TurnSpeed, Speed);
}