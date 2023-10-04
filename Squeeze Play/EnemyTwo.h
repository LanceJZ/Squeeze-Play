#pragma once
#include "Model3D.h"
#include "Managers.h"
#include "Player.h"
#include "Border.h"
#include "EnemyShot.h"
#include "ScoreKeeper.h"

class EnemyTwo : public Model3D
{
public:
	EnemyTwo();
	virtual ~EnemyTwo();

	std::vector<EnemyShot*> Shots;

	void SetManagersRef(Managers& man);
	void SetPlayerRef(Player* player);
	void SetBorderRef(Border* borders);
	void SetScoreKeeperRef(ScoreKeeper* score);
	void SetShotModelID(size_t modelID);
	void SetSounds(Sound hit, Sound fire);

	bool Initialize();
	bool BeginRun(Camera* camera);

	void Update(float deltaTime);
	void Draw();

	void Spawn();

private:
	size_t DistanceTimerID = 0;
	size_t FireTimerID = 0;
	size_t ShotModelID = 0;
	float Speed = 22.666f;
	float MaxSpeed = 52.666;

	Sound HitSound;
	Sound FireSound;

	Managers* Man = {};
	Player* ThePlayer = {};
	Border* Borders = {};
	ScoreKeeper* Score = {};

	void ChasePlayer();
	bool CheckCollision();
	void Collide();
	void Fire();
};
