#pragma once
#include "Model3D.h"
#include "Managers.h"
#include "Border.h"
#include "Player.h"

class EnemyShot : public Model3D
{
public:
	EnemyShot();
	virtual ~EnemyShot();

	void SetManagersRef(EntityManager& man);
	void SetPlayerRef(Player* player);
	void SetBorderRef(Border* borders);

	bool Initialize();
	bool BeginRun(Camera* camera);

	void Update(float deltaTime);
	void Draw();

	void Spawn(Vector3 pos, size_t timerAmount);

private:
	size_t ShotTimerID = 0;
	EntityManager* Man = {};
	Player* ThePlayer = {};
	Border* Borders = {};

	bool CheckCollision();
	void Collide();
};
