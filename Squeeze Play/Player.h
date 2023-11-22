#pragma once
#include "Common.h"
#include "PlayerShared.h"
#include "PlayerShot.h"
#include "ScoreKeeper.h"
#include "ExplosionControl.h"
#include "ThrustControl.h"

struct ShotandTimer
{
	size_t Number;
	size_t Timer;
};

class Player : public PlayerShared
{
public:
	Player();
	virtual ~Player();

	bool NewLife = false;
	bool Exploding = false;
	bool GameOver = true;
	bool Debug = false;
	int Wave { 0 };
	int Lives { 0 };

	std::vector<PlayerShot*> Shots;

	void SetScoreKeeperRef(ScoreKeeper* score);
	void SetExplosionControlRef(ExplosionControl* explosions);
	void SetThrustControlRef(ThrustControl* thrust);
	void SetSounds(Sound fireSound, Sound explodeSound, Sound thrustSound);
	void SetShotSound(Sound borderHit);
	void SetShipModelID(size_t modelID);
	void SetShotModelID(size_t modelID);
	bool Initialize();
	bool BeginRun(Camera* camera);

	void Input();
	void Update(float deltaTime);
	void Draw();

	void Hit();
	void Reset();
	void NewGame();
	bool GetShieldIsOn();
	bool GetShieldIsOff();

private:
	bool ThrustIsOn = false;
	size_t ShipModelID = 0;
	size_t ShotModelID = 0;
	size_t FireTimerID = 0;
	int NextNewLifeScore = 10000;
	float ThrustSoundTime = 0;
	float ShieldPower = 100;

	Sound FireSound = {};
	Sound ExplodeSound = {};
	Sound ThrustSound = {};

	ScoreKeeper* Score = {};
	ExplosionControl* Explosions = {};
	ThrustControl* Thrust = {};

	void CheckBorderHit();
	void Fire();
	void ShieldOn();
	void ShieldOff();
	void ThrustOn(float deltaTime);
	void ThrustOff(float deltaTime);
	void GamePad();
	void Keyboard();
};
