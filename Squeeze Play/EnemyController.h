#pragma once
#include "Common.h"
#include "EnemyOne.h"
#include "EnemyTwo.h"
#include "EnemyThree.h"
#include "Managers.h"
#include "EnemyShotFactory.h"
#include "ExplosionControl.h"
#include "Border.h"
#include "ScoreKeeper.h"

class EnemyController : public Common
{
public:
	EnemyController();
	virtual ~EnemyController();

	std::vector<EnemyOne*> Ones;
	std::vector<EnemyTwo*> Twos;
	std::vector<EnemyThree*> Threes;

	void SetManagersRef(Managers& man);
	void SetCameraRef(Camera& cam);
	void SetPlayerRef(Player* player);
	void SetBorderRef(Border* borders);
	void SetScoreKeeperRef(ScoreKeeper* score);
	void SetShipOneModelID(size_t modelID);
	void SetShipTwoModelID(size_t modelID);
	void SetShipThreeModelID(size_t modelID);
	void SetShotModelID(size_t modelID);
	void SetMissileModelID(size_t modelID);
	void SetSounds(Sound oneHit, Sound twoHit, Sound twoFire);
	void SetExplosionControl(ExplosionControl* explosions);

	bool Initialize();
	bool BeginRun();

	void Update();
	void Draw();

	void Reset();

private:
	size_t ShipOneModelID = 0;
	size_t ShipTwoModelID = 0;
	size_t ShipThreeModelID = 0;
	size_t ShotModelID = 0;
	size_t MissileModelID = 0;
	size_t SpawnTimerID = 0;
	int WaveOne = 0;

	Sound OneHitSound = {};
	Sound TwoHitSound = {};
	Sound TwoFireSound = {};

	Managers* Man = {};
	Camera* Cam = {};
	Player* ThePlayer = {};
	Border* Borders = {};
	ScoreKeeper* Score = {};
	ExplosionControl* Explosions = {};
	EnemyShotFactory ESF = {};

	void SpawnOne(size_t count);
	void SpawnTwo(size_t count);
	void SpawnThree(size_t count);
};

