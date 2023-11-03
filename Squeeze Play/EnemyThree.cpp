#include "EnemyThree.h"

EnemyThree::EnemyThree()
{
}

EnemyThree::~EnemyThree()
{
}

bool EnemyThree::Initialize()
{
	EnemyFires::Initialize();

	return false;
}

bool EnemyThree::BeginRun(Camera* camera)
{
	EnemyFires::BeginRun(camera);

	return false;
}

void EnemyThree::Update(float deltaTime)
{
	EnemyFires::Update(deltaTime);

	ChasePlayer();
}

void EnemyThree::Draw()
{
	EnemyFires::Draw();

}

void EnemyThree::Spawn()
{
	EnemyFires::Spawn();

	float maxSpeed = 26.666f;
	float maxTurnSpeed = 0.15f;

	Speed = GetRandomFloat(maxSpeed * 0.5f, maxSpeed);
	TurnSpeed = GetRandomFloat(maxTurnSpeed * 0.5f, maxTurnSpeed);
	Rotation = AngleFromVectorZ(ThePlayer->Position);

}
