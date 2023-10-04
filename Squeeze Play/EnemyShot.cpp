#include "EnemyShot.h"

EnemyShot::EnemyShot()
{
}

EnemyShot::~EnemyShot()
{
}

void EnemyShot::SetManagersRef(EntityManager& man)
{
	Man = &man;
}

void EnemyShot::SetPlayerRef(Player* player)
{
	ThePlayer = player;
}

void EnemyShot::SetBorderRef(Border* borders)
{
	Borders = borders;
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

	ShotTimerID = Man->AddTimer();

	return false;
}

void EnemyShot::Update(float deltaTime)
{
	Model3D::Update(deltaTime);

	if (Man->Timers[ShotTimerID]->Elapsed())
	{
		Enabled = false;
	}

	if (CheckCollision()) Collide();
}

void EnemyShot::Draw()
{
	Model3D::Draw();

}

void EnemyShot::Spawn(Vector3 pos, size_t timerAmount)
{
	Position = pos;
	Position.z = 10;
	Enabled = true;

	Man->Timers[ShotTimerID]->Reset(timerAmount);

	float range = 1.5f;
	float rX = GetRandomFloat(-range, range);
	float rY = GetRandomFloat(-range, range);
	float rZ = GetRandomFloat(-range, range);
	RotationAxis = { rX, rY, rZ };
	RotationVelocity = GetRandomFloat(1.5f, 3.5f);

	float angle = AngleFromVectorZ(ThePlayer->Position);
	Velocity = VelocityFromAngleZ(angle, 100);
}

bool EnemyShot::CheckCollision()
{
	if (CirclesIntersect(*ThePlayer) && Enabled)
	{
		return true;
	}

	return false;
}

void EnemyShot::Collide()
{
	Enabled = false;
	X(WindowWidth + 50);
	ThePlayer->Hit();
}
