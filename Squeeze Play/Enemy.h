#pragma once
#include "Model3D.h"
#include "Managers.h"
#include "Player.h"
#include "Border.h"
#include "ScoreKeeper.h"
#include "ExplosionControl.h"

class Enemy : public Model3D
{
public:
	Enemy();
	virtual ~Enemy();

	virtual void SetManagersRef(Managers* man);
	virtual void SetPlayerRef(Player* player);
	virtual void SetBorderRef(Border* borders);
	virtual void SetScoreKeeperRef(ScoreKeeper* score);
	virtual void SetExplosionControlRef(ExplosionControl* explosions);
	virtual void SetSound(Sound hit);
	virtual bool Initialize();
	virtual bool BeginRun(Camera* camera);

	virtual void Update(float deltaTime);
	virtual void Draw();

	virtual void Spawn();
	void Spawn(Vector3 position, float rotation, float speed, float turnSpeed);
	void Spawn(Vector3 position, float rotation, Vector3 Velocity);

protected:
	float Speed = 33.666f;
	float TurnSpeed = 0.25f;

	Sound HitSound = {};

	Managers* Man = {};
	Player* ThePlayer = {};
	ExplosionControl* Explosions = {};
	Border* Borders = {};

	virtual void Collide();
	virtual void ChasePlayer();

private:
	Color ExplodeColor = {};

	ScoreKeeper* Score = {};

	bool CheckCollision();
};
