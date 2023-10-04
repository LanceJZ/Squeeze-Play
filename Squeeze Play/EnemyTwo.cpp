#include "EnemyTwo.h"

EnemyTwo::EnemyTwo()
{
}

EnemyTwo::~EnemyTwo()
{
}

void EnemyTwo::SetManagersRef(Managers& man)
{
	Man = &man;
}

void EnemyTwo::SetPlayerRef(Player* player)
{
	ThePlayer = player;
}

void EnemyTwo::SetBorderRef(Border* borders)
{
	Borders = borders;
}

void EnemyTwo::SetScoreKeeperRef(ScoreKeeper* score)
{
	Score = score;
}

void EnemyTwo::SetShotModelID(size_t modelID)
{
	ShotModelID = modelID;
}

void EnemyTwo::SetSounds(Sound hit, Sound fire)
{
	HitSound = hit;
	FireSound = fire;
}

bool EnemyTwo::Initialize()
{
	Model3D::Initialize();

	Radius = 18;
	Cull = false;

	return false;
}

bool EnemyTwo::BeginRun(Camera* camera)
{
	Model3D::BeginRun(camera);

	FireTimerID = Man->EM.AddTimer(5.0f);
	DistanceTimerID = Man->EM.AddTimer(4.0f);

	return false;
}

void EnemyTwo::Update(float deltaTime)
{
	Model3D::Update(deltaTime);

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
		ChasePlayer();
	}

	if (CheckCollision()) Collide();
}

void EnemyTwo::Draw()
{
	Model3D::Draw();

}

void EnemyTwo::Spawn()
{
	Enabled = true;

	float range = 0.95f;
	float rX = GetRandomFloat(-range, range);
	float rY = GetRandomFloat(-range, range);
	float rZ = GetRandomFloat(-range, range);
	RotationAxis = { rX, rY, rZ };
	RotationVelocity = GetRandomFloat(1.5f, 3.5f);


	float buffer = 1.0f;
	float x = GetRandomFloat(-WindowWidth, WindowWidth);
	float y = GetRandomFloat(-WindowHeight, WindowHeight);

	if (GetRandomValue(1, 100) < 50)
	{
		if (GetRandomValue(1, 100) < 50)
		{
			x = WindowWidth + buffer;
		}
		else
		{
			x = -WindowWidth - buffer;
		}
	}
	else
	{
		if (GetRandomValue(1, 100) < 50)
		{
			y = WindowHeight + buffer;
		}
		else
		{
			y = -WindowHeight - buffer;
		}
	}

	X(x);
	Y(y);

	Man->EM.Timers[FireTimerID]->Reset(5.0f);
	Man->EM.Timers[DistanceTimerID]->Reset(4.0f);

	float angle = AngleFromVectorZ(ThePlayer->Position);
	Velocity = VelocityFromAngleZ(angle, Speed);
}

void EnemyTwo::ChasePlayer()
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

bool EnemyTwo::CheckCollision()
{
	if (CirclesIntersect(*ThePlayer) && ThePlayer->Enabled)
	{
		ThePlayer->Hit();

		return true;
	}

	for (auto &shot : ThePlayer->Shots)
	{
		if (CirclesIntersect(*shot) && shot->Enabled)
		{
			shot->Enabled = false;

			return true;
		}
	}

	return false;
}

void EnemyTwo::Collide()
{
	Enabled = false;
	X(WindowWidth + 50.0f);
	Borders->EnemyHit();
	Score->Add(50);
	PlaySound(HitSound);
}

void EnemyTwo::Fire()
{
	PlaySound(FireSound);
	bool spawnShot = true;
	size_t shotNumber = Shots.size();

	for (size_t shotCheck = 0; shotCheck < shotNumber; shotCheck++)
	{
		if (!Shots[shotCheck]->Enabled)
		{
			spawnShot = false;
			shotNumber = shotCheck;
			break;
		}
	}

	if (spawnShot)
	{
		Shots.push_back(new EnemyShot());
		Man->EM.AddModel3D(Shots[shotNumber]);
		Shots[shotNumber]->SetModel(Man->CM.GetModel(ShotModelID), 3.75f);
		Shots[shotNumber]->SetManagersRef(Man->EM);
		Shots[shotNumber]->SetPlayerRef(ThePlayer);
		Shots[shotNumber]->SetBorderRef(Borders);
		Shots[shotNumber]->BeginRun(GetCamera());
	}

	Shots[shotNumber]->Spawn(Position, 5.0f);
}
