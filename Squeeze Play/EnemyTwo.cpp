#include "EnemyTwo.h"

EnemyTwo::EnemyTwo()
{
}

EnemyTwo::~EnemyTwo()
{
}

void EnemyTwo::SetEnemyShotFactoryRef(EnemyShotFactory* esf)
{
	ESF = esf;
}

void EnemyTwo::SetShotModelID(size_t modelID)
{
	ShotModelID = modelID;
}

void EnemyTwo::SetSounds(Sound hit, Sound fire)
{
	Enemy::SetSound(hit);

	FireSound = fire;
}

bool EnemyTwo::Initialize()
{
	Enemy::Initialize();

	Radius = 18;
	Cull = false;

	return false;
}

bool EnemyTwo::BeginRun(Camera* camera)
{
	Enemy::BeginRun(camera);

	FireTimerID = Man->EM.AddTimer(5.0f);
	DistanceTimerID = Man->EM.AddTimer(4.0f);

	return false;
}

void EnemyTwo::Update(float deltaTime)
{
	Enemy::Update(deltaTime);

	if (Man->EM.Timers[FireTimerID]->Elapsed())
	{
		float time = GetRandomFloat(5.15f, 13.15f);
		Man->EM.Timers[FireTimerID]->Reset(time);
		Fire();
	}

	if (Man->EM.Timers[DistanceTimerID]->Elapsed())
	{
		float time = GetRandomFloat(2.15f, 5.15f);
		Man->EM.Timers[DistanceTimerID]->Reset(time);
		ChangeVelocity();
	}
}

void EnemyTwo::Draw()
{
	Enemy::Draw();

}

void EnemyTwo::Spawn()
{
	Enemy::Spawn();

	Man->EM.Timers[FireTimerID]->Reset(5.0f);
	Man->EM.Timers[DistanceTimerID]->Reset(4.0f);

	float angle = AngleFromVectorZ(ThePlayer->Position);
	Velocity = VelocityFromAngleZ(angle, Speed);
}

void EnemyTwo::ChangeVelocity()
{
	float distanceX = GetRandomFloat(50.0f, 100.0f);
	float distanceY = GetRandomFloat(40.0f, 90.0f);
	float pX = ThePlayer->X();
	float pY = ThePlayer->Y();
	Speed = GetRandomFloat(MaxSpeed * 0.5f, MaxSpeed);

	if (pX < X() + distanceX && pX > X() - distanceX)
	{
		if (pY + distanceY < Y())
		{
			Velocity.y = -Speed;
		}
		else if (pY - distanceY > Y())
		{
			Velocity.y = Speed;
		}

		if (pX + distanceX < X())
		{
			Velocity.x = -Speed;
		}
		else if (pX - distanceX > X())
		{
			Velocity.x = Speed;
		}
	}
}

void EnemyTwo::Collide()
{
	Enemy::Collide();

	Explosions->Spawn(Position, 20.0f, 40.0f, 15, 1.5f, PURPLE);
}

void EnemyTwo::Fire()
{
	PlaySound(FireSound);

	float angle = AngleFromVectorZ(ThePlayer->Position);
	Vector3 vel = VelocityFromAngleZ(angle, 100);

	ESF->Spawn(Position, vel, 5.0f, ShotModelID);
}
