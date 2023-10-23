#pragma once
#include "Enemy.h"
#include "EnemyShotFactory.h"

class EnemyFires : public Enemy
{
public:
	EnemyFires();
	virtual ~EnemyFires();

	void SetEnemyShotFactoryRef(EnemyShotFactory* esf);
	void SetShotModelID(size_t modelID);
	void SetSounds(Sound hit, Sound fire);

	bool Initialize();
	bool BeginRun(Camera* camera);

	void Update(float deltaTime);
	void Draw();

protected:
	size_t FireTimerID = 0;
	size_t ShotModelID = 0;

	Sound FireSound = {};
	EnemyShotFactory* ESF = {};

private:

};
