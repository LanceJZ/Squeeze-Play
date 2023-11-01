#pragma once
#include "PlayerShared.h"

class PlayerShot : public PlayerShared
{
public:
	PlayerShot();
	virtual ~PlayerShot();

	bool Initialize();
	bool BeginRun(Camera* camera);

	void Update(float deltaTime);
	void Draw();

	void Spawn(Vector3 position, float rotation, Vector3 velocity, size_t timerAmount);

private:
	size_t ShotTimerID = 0;

};
