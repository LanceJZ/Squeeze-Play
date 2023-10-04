#include "PlayerShot.h"

PlayerShot::PlayerShot()
{
}

PlayerShot::~PlayerShot()
{
}

void PlayerShot::SetManagersRef(EntityManager& man)
{
	Man = &man;
}

void PlayerShot::SetBorderRef(Border* borders)
{
	Borders = borders;
}

void PlayerShot::SetSound(Sound borderHit)
{
	BorderHitSound = borderHit;
}

bool PlayerShot::Initialize()
{
	Model3D::Initialize();
	Cull = false;
	Radius = 5;

	return false;
}

bool PlayerShot::BeginRun(Camera* camera)
{
	Model3D::BeginRun(camera);

	ShotTimerID = Man->AddTimer();

	return true;
}

void PlayerShot::Update(float deltaTime)
{
	Model3D::Update(deltaTime);

	if (Man->Timers[ShotTimerID]->Elapsed())
	{
		Enabled = false;
	}

	CheckBorderHit();
}

void PlayerShot::Draw()
{
	Model3D::Draw();

}

void PlayerShot::Spawn(Vector3 pos, float rot, Vector3 vel, size_t timerAmount)
{
	Position = pos;
	Position.z = 10;
	Velocity = vel;
	Rotation = rot;
	Enabled = true;

	Man->Timers[ShotTimerID]->Reset(timerAmount);
}

void PlayerShot::CheckBorderHit()
{
	size_t borderTop = Borders->Borders[0];
	size_t borderBottom = Borders->Borders[1];
	size_t borderLeft = Borders->Borders[2];
	size_t borderRight = Borders->Borders[3];

	if (X() + Radius > Man->Model3Ds[borderRight]->X())
	{
		Enabled = false;
		PlaySound(BorderHitSound);
	}

	if (X() - Radius < Man->Model3Ds[borderLeft]->X())
	{
		Enabled = false;
		PlaySound(BorderHitSound);
	}

	if (Y() + Radius > Man->Model3Ds[borderBottom]->Y())
	{
		Enabled = false;
		PlaySound(BorderHitSound);
	}

	if (Y() - Radius < Man->Model3Ds[borderTop]->Y())
	{
		Enabled = false;
		PlaySound(BorderHitSound);
	}
}
