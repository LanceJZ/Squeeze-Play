#pragma once
#include "Enemy.h"
#include "EnemyShotFactory.h"

class EnemyTwo : public Enemy
{
public:
	EnemyTwo();
	virtual ~EnemyTwo();

	void SetEnemyShotFactoryRef(EnemyShotFactory* esf);
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

	Sound FireSound = {};
	EnemyShotFactory* ESF = {};

	void ChangeVelocity();
	void Collide();
	void Fire();
};
