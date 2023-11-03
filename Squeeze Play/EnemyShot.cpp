#include "EnemyShot.h"

EnemyShot::EnemyShot()
{
}

EnemyShot::~EnemyShot()
{
}

bool EnemyShot::Initialize()
{
	Model3D::Initialize();

	Cull = false;
	Radius = 3.75f;

	return false;
}

bool EnemyShot::BeginRun(Camera* camera)
{
	Model3D::BeginRun(camera);

	ShotTimerID = Man->EM.AddTimer();

	return false;
}

void EnemyShot::Update(float deltaTime)
{
	Model3D::Update(deltaTime);

	if (Man->EM.Timers[ShotTimerID]->Elapsed())
	{
		Enabled = false;
	}

	if (CheckCollision()) Collide();
}

void EnemyShot::Draw()
{
	Enemy::Draw();

}

void EnemyShot::Spawn(Vector3 position, Vector3 velocity, float timerAmount)
{
	Enemy::Spawn(position, 0, velocity);

	Position.z = 10;

	Man->EM.Timers[ShotTimerID]->Reset(timerAmount);

	float range = 1.5f;
	float rX = GetRandomFloat(-range, range);
	float rY = GetRandomFloat(-range, range);
	float rZ = GetRandomFloat(-range, range);
	RotationAxis = { rX, rY, rZ };
	RotationVelocity = GetRandomFloat(1.5f, 3.5f);
}

bool EnemyShot::CheckCollision()
{
	if (Enemy::CheckCollision()) return true;

	return false;
}

void EnemyShot::Collide()
{
	Enabled = false;
	X(WindowWidth + 50);
}
