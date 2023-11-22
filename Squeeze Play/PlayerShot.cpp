#include "PlayerShot.h"

PlayerShot::PlayerShot()
{
}

PlayerShot::~PlayerShot()
{
}

bool PlayerShot::Initialize()
{
	PlayerShared::Initialize();

	Cull = false;
	Radius = 5;

	return false;
}

bool PlayerShot::BeginRun(Camera* camera)
{
	PlayerShared::BeginRun(camera);

	ShotTimerID = Man->EM.AddTimer();

	return true;
}

void PlayerShot::Update(float deltaTime)
{
	PlayerShared::Update(deltaTime);

	if (Man->EM.Timers[ShotTimerID]->Elapsed())
	{
		Enabled = false;
	}

	CheckBorderHit();
}

void PlayerShot::Draw()
{
	PlayerShared::Draw();

}

void PlayerShot::Spawn(Vector3 position, float rotation, Vector3 velocity,
	size_t timerAmount)
{
	Position = position;
	Position.z = 10;
	Velocity = velocity;
	Rotation = rotation;
	Enabled = true;

	Man->EM.Timers[ShotTimerID]->Reset(timerAmount);
}