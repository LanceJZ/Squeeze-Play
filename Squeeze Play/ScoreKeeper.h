#pragma once
#include "Common.h"
#include "EntityManager.h"
#include <string>

class ScoreKeeper : public Common
{
public:
	ScoreKeeper();
	virtual ~ScoreKeeper();

	int Score = 0;
	int Timer = 0;
	int Lives = 0;

	void SetManagersRef(EntityManager& man);


	bool Initialize();
	bool BeginRun();

	void Input();
	void Update();
	void Draw2D();

	void Add(int score);
	void SetLives(int lives);
	void Reset();

private:
	size_t TimerTimerID = 0;

	EntityManager* Man = {};
};

