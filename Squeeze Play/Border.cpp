#include "Border.h"

Border::Border()
{

}

Border::~Border()
{
}

void Border::SetManagersRef(Managers& man)
{
	Man = &man;
}

void Border::SetCameraRef(Camera& cam)
{
	Cam = &cam;
}

void Border::SetBorderModelID(size_t modelID)
{
	BorderModelID = modelID;
}

bool Border::Initialize()
{
	Common::Initialize();

	return false;
}

bool Border::BeginRun()
{
	Common::BeginRun();

	ShrinkTimerID = Man->EM.AddTimer(1.0f);

	SetupBorders();

	return false;
}

void Border::Update()
{
	if (Man->EM.Timers[ShrinkTimerID]->Elapsed())
	{
		Man->EM.Timers[ShrinkTimerID]->Reset();
		Shrink();
	}
}

void Border::Draw()
{

}

void Border::EnemyHit()
{
	Expand();
}

void Border::Reset()
{
	size_t borderTop = Borders[0];
	size_t borderBottom = Borders[1];
	size_t borderLeft = Borders[2];
	size_t borderRight = Borders[3];

	Man->EM.Model3Ds[borderLeft]->X(-GameWindowHalfWidth);
	Man->EM.Model3Ds[borderRight]->X(GameWindowHalfWidth);

	Man->EM.Model3Ds[borderTop]->Y(-GameWindowHalfHeight);
	Man->EM.Model3Ds[borderBottom]->Y(GameWindowHalfHeight);
}

void Border::SetupBorders()
{
	for (int i = 0; i < 4; i++)
	{
		Borders.push_back(Man->EM.AddModel3D(Man->CM.GetModel(BorderModelID)));
		Man->EM.Model3Ds[Borders[i]]->BeginRun(Cam);
		Man->EM.Model3Ds[Borders[i]]->Scale = 50.0f;
	}

	size_t borderTop = Borders[0];
	size_t borderBottom = Borders[1];
	size_t borderLeft = Borders[2];
	size_t borderRight = Borders[3];

	Man->EM.Model3Ds[borderLeft]->Rotation = -PI * 0.5f;
	Man->EM.Model3Ds[borderRight]->Rotation = PI * 0.5f;
	Man->EM.Model3Ds[borderBottom]->Rotation = PI;

	Reset();
}

void Border::Shrink()
{
	size_t borderTop = Borders[0];
	size_t borderBottom = Borders[1];
	size_t borderLeft = Borders[2];
	size_t borderRight = Borders[3];

	float speed = 6.666f;

	Man->EM.Model3Ds[borderLeft]->Velocity.x = speed;
	Man->EM.Model3Ds[borderRight]->Velocity.x = -speed;
	Man->EM.Model3Ds[borderTop]->Velocity.y = speed;
	Man->EM.Model3Ds[borderBottom]->Velocity.y = -speed;
}

void Border::Expand()
{
	size_t borderTop = Borders[0];
	size_t borderBottom = Borders[1];
	size_t borderLeft = Borders[2];
	size_t borderRight = Borders[3];

	float speed = 4.666f;

	Vector3 left = Man->EM.Model3Ds[borderLeft]->Position;
	Vector3 right = Man->EM.Model3Ds[borderRight]->Position;
	Vector3 top = Man->EM.Model3Ds[borderTop]->Position;
	Vector3 bottom = Man->EM.Model3Ds[borderBottom]->Position;

	if (left.x > -GameWindowHalfWidth)
	{
		Man->EM.Model3Ds[borderLeft]->Velocity.x = -speed;
	}

	if (right.x < GameWindowHalfWidth)
	{
		Man->EM.Model3Ds[borderRight]->Velocity.x = speed;
	}

	if (top.y > -GameWindowHalfHeight)
	{
		Man->EM.Model3Ds[borderTop]->Velocity.y = -speed;
	}

	if (bottom.y < GameWindowHalfHeight)
	{
		Man->EM.Model3Ds[borderBottom]->Velocity.y = speed;
	}
}
