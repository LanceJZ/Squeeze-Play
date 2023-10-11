#pragma once
#include "Common.h"
#include "Managers.h"
#include "EnemyShot.h"

class EnemyShotFactory : public Common
{
public:
	EnemyShotFactory();
	virtual ~EnemyShotFactory();

	std::vector<EnemyShot*> Shots;

	void SetManagersRef(Managers* man);
	void SetPlayerRef(Player* player);
	void SetCameraRef(Camera* camera);

	bool Initialize();
	bool BeginRun();

	void Input();
	void Update();
	void Draw();

	void Spawn(Vector3 position, Vector3 velocity, float timer, size_t shotModel);
	void Reset();

private:
	Managers* Man = {};
	Player* ThePlayer = {};
	Camera* Cam = {};
};

