#pragma once
#include "Model3D.h"
#include "Managers.h"
#include "Border.h"

class PlayerShot : public Model3D
{
public:
	PlayerShot();
	virtual ~PlayerShot();

	void SetManagersRef(EntityManager& man);
	void SetBorderRef(Border* borders);
	void SetSound(Sound borderHit);

	bool Initialize();
	bool BeginRun(Camera* camera);

	void Update(float deltaTime);
	void Draw();

	void Spawn(Vector3 pos, float rot, Vector3 vel, size_t timerAmount);

private:
	size_t ShotTimerID = 0;

	Sound BorderHitSound;

	EntityManager* Man = {};
	Border* Borders = {};

	void CheckBorderHit();
};
