#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::SetManagersRef(Managers* man)
{
	Man = man;
}

void Enemy::SetPlayerRef(Player* player)
{
	ThePlayer = player;
}

void Enemy::SetBorderRef(Border* borders)
{
	Borders = borders;
}

void Enemy::SetScoreKeeperRef(ScoreKeeper* score)
{
	Score = score;
}

void Enemy::SetExplosionControlRef(ExplosionControl* explosions)
{
	Explosions = explosions;
}

void Enemy::SetSound(Sound hit)
{
	HitSound = hit;
}

bool Enemy::Initialize()
{
	Model3D::Initialize();

	return false;
}

bool Enemy::BeginRun(Camera* camera)
{
	Model3D::BeginRun(camera);

	return false;
}

void Enemy::Update(float deltaTime)
{
	Model3D::Update(deltaTime);

	if (CheckCollisionPlayerShot() || CheckCollision()) Collide();
}

void Enemy::Draw()
{
	Model3D::Draw();

}

void Enemy::Spawn()
{
	Enabled = true;
	float buffer = 20.0f;
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
		{
			y = -WindowHeight - buffer;
		}
	}

	X(x);
	Y(y);
}

void Enemy::Spawn(Vector3 position, float rotation, float speed, float turnSpeed)
{
	Position = position;
	Rotation = rotation;
	Speed = speed;
	TurnSpeed = turnSpeed;
	Enabled = true;
}

void Enemy::Spawn(Vector3 position, float rotation, Vector3 velocity)
{
	Position = position;
	Rotation = rotation;
	Velocity = velocity;
	Enabled = true;
}

bool Enemy::CheckCollisionPlayerShot()
{
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

bool Enemy::CheckCollision()
{
	if (CirclesIntersect(*ThePlayer) && ThePlayer->Enabled)
	{
		ThePlayer->Hit();

		return true;
	}
}

void Enemy::Collide()
{
	Enabled = false;
	Borders->EnemyHit();
	Score->Add(10);
	PlaySound(HitSound);
}

void Enemy::ChasePlayer()
{
	RotateVelocity(ThePlayer->Position, TurnSpeed, Speed);
}