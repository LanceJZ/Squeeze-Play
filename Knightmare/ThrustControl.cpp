#include "ThrustControl.h"

ThrustControl::ThrustControl()
{

}

ThrustControl::~ThrustControl()
{
}

bool ThrustControl::Initialize()
{
	ParticleManager::Initialize();

	return false;
}

bool ThrustControl::BeginRun()
{
	ParticleManager::BeginRun();

	return false;
}

void ThrustControl::Update()
{
	ParticleManager::Update();

}

void ThrustControl::Draw()
{
	ParticleManager::Draw();

}

void ThrustControl::Spawn(Vector3 position, Vector3 velocity, float radius,
	float speed, int count, float time, Color color)
{
	ParticleManager::Spawn(position, velocity, radius, speed, count, time, color);
}
