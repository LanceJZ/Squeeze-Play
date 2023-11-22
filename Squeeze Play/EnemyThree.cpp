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

	Radius = 20.0f;
	Cull = false;

	return false;
}

bool EnemyThree::BeginRun(Camera* camera)
{
	EnemyFires::BeginRun(camera);

	Man->EM.Timers[FireTimerID]->Reset(10.0f);
	ESF->SetBorderRef(Borders);
	ESF->SetScoreKeeperRef(Score);

	return false;
}

void EnemyThree::Update(float deltaTime)
{
	EnemyFires::Update(deltaTime);

	if (Man->EM.Timers[FireTimerID]->Elapsed())
	{
		float time = GetRandomFloat(15.15f, 23.15f);
		Man->EM.Timers[FireTimerID]->Reset(time);
		Fire();
	}

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

void EnemyThree::Fire()
{
	EnemyFires::Fire(Position, Rotation, 40.0f, 10.0f);
}
