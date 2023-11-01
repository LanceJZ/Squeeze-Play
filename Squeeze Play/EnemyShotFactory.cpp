#include "EnemyShotFactory.h"

EnemyShotFactory::EnemyShotFactory()
{

}

EnemyShotFactory::~EnemyShotFactory()
{
}

void EnemyShotFactory::SetManagersRef(Managers* man)
{
	Man = man;
}

void EnemyShotFactory::SetPlayerRef(Player* player)
{
	ThePlayer = player;
}

void EnemyShotFactory::SetCameraRef(Camera* camera)
{
	Cam = camera;
}

bool EnemyShotFactory::Initialize()
{

	return false;
}

bool EnemyShotFactory::BeginRun()
{

	return false;
}

void EnemyShotFactory::Input()
{

}

void EnemyShotFactory::Update()
{

}

void EnemyShotFactory::Draw()
{

}

void EnemyShotFactory::SpawnShot(Vector3 position, Vector3 velocity, float timer,
	size_t shotModelID)
{
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
		Shots[shotNumber]->SetModel(Man->CM.GetModel(shotModelID), 3.75f);
		Shots[shotNumber]->SetManagersRef(Man->EM);
		Shots[shotNumber]->SetPlayerRef(ThePlayer);
		Shots[shotNumber]->BeginRun(Cam);
	}

	Shots[shotNumber]->Spawn(position, velocity, timer);
}

void EnemyShotFactory::SpawnMissile(Vector3 position, float rotation,
	float speed, float targeting, size_t missileModelID)
{
	bool spawnMissile = true;
	size_t missileNumber = Missiles.size();

	for (size_t missileCheck = 0; missileCheck < missileNumber; missileCheck++)
	{
		if (!Missiles[missileCheck]->Enabled)
		{
			spawnMissile = false;
			missileNumber = missileCheck;
			break;
		}
	}

	if (spawnMissile)
	{
		Missiles.push_back(new EnemyMissile());
		Man->EM.AddModel3D(Missiles[missileNumber]);
		Missiles[missileNumber]->SetModel(Man->CM.GetModel(missileModelID), 1.0f);
		Missiles[missileNumber]->SetManagersRef(Man);
		Missiles[missileNumber]->SetPlayerRef(ThePlayer);
		Missiles[missileNumber]->BeginRun(Cam);
	}

	Missiles[missileNumber]->Spawn(position, rotation, speed, targeting);
}

void EnemyShotFactory::Reset()
{
	for (auto shot : Shots)
	{
		shot->Enabled = false;
	}
}