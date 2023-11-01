#pragma once
#include "Common.h"
#include "Managers.h"
#include "EnemyShot.h"
#include "EnemyMissile.h"

class EnemyShotFactory : public Common
{
public:
	EnemyShotFactory();
	virtual ~EnemyShotFactory();

	std::vector<EnemyShot*> Shots;
	std::vector<EnemyMissile*> Missiles;

	void SetManagersRef(Managers* man);
	void SetPlayerRef(Player* player);
	void SetCameraRef(Camera* camera);

	bool Initialize();
	bool BeginRun();

	void Input();
	void Update();
	void Draw();

	void SpawnShot(Vector3 position, Vector3 velocity, float timer,
		size_t shotModelID);
	void SpawnMissile(Vector3 position, float rotation, float speed,
		float targeting, size_t missileModelID);
	void Reset();

private:
	Managers* Man = {};
	Player* ThePlayer = {};
	Camera* Cam = {};
};

