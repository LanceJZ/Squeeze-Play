#include "PlayerShared.h"

PlayerShared::PlayerShared()
{
}

PlayerShared::~PlayerShared()
{
}

void PlayerShared::SetManagersRef(Managers* man)
{
	Man = man;
}

void PlayerShared::SetBorderRef(Border* borders)
{
	Borders = borders;
}

void PlayerShared::SetBorderSound(Sound borderHit)
{
	BorderHitSound = borderHit;
}

bool PlayerShared::Initialize()
{
	Model3D::Initialize();

	return false;
}

bool PlayerShared::BeginRun(Camera* camera)
{
	Model3D::BeginRun(camera);

	return false;
}

void PlayerShared::Update(float deltaTime)
{
	Model3D::Update(deltaTime);

}

void PlayerShared::Draw()
{
	Model3D::Draw();

}

bool PlayerShared::CheckBorderHit()
{
	size_t borderTop = Borders->Borders[0];
	size_t borderBottom = Borders->Borders[1];
	size_t borderLeft = Borders->Borders[2];
	size_t borderRight = Borders->Borders[3];

	if (X() + Radius > Man->EM.Model3Ds[borderRight]->X())
	{
		Enabled = false;
		PlaySound(BorderHitSound);
		return true;
	}

	if (X() - Radius < Man->EM.Model3Ds[borderLeft]->X())
	{
		Enabled = false;
		PlaySound(BorderHitSound);
		return true;
	}

	if (Y() + Radius > Man->EM.Model3Ds[borderBottom]->Y())
	{
		Enabled = false;
		PlaySound(BorderHitSound);
		return true;
	}

	if (Y() - Radius < Man->EM.Model3Ds[borderTop]->Y())
	{
		Enabled = false;
		PlaySound(BorderHitSound);
		return true;
	}

	return false;
}
