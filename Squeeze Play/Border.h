#pragma once
#include "Common.h"
#include "Managers.h"

class Border : public Common
{
public:
	Border();
	virtual ~Border();

	std::vector<size_t> Borders;

	void SetManagersRef(Managers& man);
	void SetCameraRef(Camera& cam);
	void SetBorderModelID(size_t modelID);

	bool Initialize();
	bool BeginRun();

	void Update();
	void Draw();

	void EnemyHit();
	void Reset();

private:
	size_t BorderModelID = 0;
	size_t ShrinkTimerID = 0;
	float ShrinkSpeed = 20.0f;
	float ExpandSpeed = 5.0f;

	Managers* Man = {};
	Camera* Cam = {};

	void SetupBorders();
	void Shrink();
	void Expand();
};

