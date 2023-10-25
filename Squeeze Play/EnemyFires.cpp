#include "EnemyFires.h"

EnemyFires::EnemyFires()
{
}

EnemyFires::~EnemyFires()
{
}

void EnemyFires::SetEnemyShotFactoryRef(EnemyShotFactory* esf)
{
	ESF = esf;
}

void EnemyFires::SetShotModelID(size_t modelID)
{
	ShotModelID = modelID;
}

void EnemyFires::SetSounds(Sound hit, Sound fire)
{
	Enemy::SetSound(hit);

	FireSound = fire;
}

bool EnemyFires::Initialize()
{
	Enemy::Initialize();

	return false;
}

bool EnemyFires::BeginRun(Camera* camera)
{
	Enemy::BeginRun(camera);

	FireTimerID = Man->EM.AddTimer();

	return false;
}

void EnemyFires::Update(float deltaTime)
{
	Enemy::Update(deltaTime);

}

void EnemyFires::Draw()
{
	Enemy::Draw();

}