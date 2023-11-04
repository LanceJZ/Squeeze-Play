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

	virtual bool Initialize();
	virtual bool BeginRun(Camera* camera);

	virtual void Update(float deltaTime);
	virtual void Draw();

protected:
	size_t FireTimerID = 0;
	size_t ShotModelID = 0;

	Sound FireSound = {};
	EnemyShotFactory* ESF = {};

	void Fire(Vector3 position, Vector3 velocity, float timer);
	void Fire(Vector3 position, float rotation, float speed, float targeting);


private:

};
