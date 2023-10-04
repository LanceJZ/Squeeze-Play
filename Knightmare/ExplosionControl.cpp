#include "ExplosionControl.h"

ExplosionControl::ExplosionControl()
{
}

ExplosionControl::~ExplosionControl()
{
	Particles.clear();
}

bool ExplosionControl::Initialize()
{

	return false;
}

void ExplosionControl::SetCubeModel(Model model)
{
	CubeModel = model;
}

void ExplosionControl::SetCamera(Camera &camera)
{
	Cam = &camera;
}

void ExplosionControl::SetManagers(Managers& managers)
{
	Man = &managers;
}

bool ExplosionControl::BeginRun()
{
	return false;
}

void ExplosionControl::Update(float deltaTime)
{

}

void ExplosionControl::Spawn(Vector3 position, int count, float time)
{
	for (int i = 0; i < count; i++)
	{
		Particles[SpawnPool()]->Spawn(position, time);
	}
}

void ExplosionControl::Reset()
{
	for (const auto& cube : Particles)
	{
		cube->Enabled = false;
	}
}

size_t ExplosionControl::SpawnPool()
{
		bool spawnNew = true;
		size_t cubeSpawnNumber = Particles.size();
		int cubeNumber = 0;

		for (const auto& cube : Particles)
		{
			if (cube->Enabled)
			{
				spawnNew = false;
				cubeSpawnNumber = cubeNumber;
				break;
			}

			cubeNumber++;
		}

		if (spawnNew)
		{
			Particles.push_back(new ParticleCube());
			Man->EM.AddModel3D(Particles[cubeSpawnNumber], CubeModel, 10.0f, Cam);
		}

	return cubeSpawnNumber;
}