#include "ScoreKeeper.h"

ScoreKeeper::ScoreKeeper()
{

}

ScoreKeeper::~ScoreKeeper()
{
}

void ScoreKeeper::SetManagersRef(EntityManager& man)
{
	Man = &man;
}

bool ScoreKeeper::Initialize()
{

	return false;
}

bool ScoreKeeper::BeginRun()
{
	TimerTimerID = Man->AddTimer(1.0f);

	return false;
}

void ScoreKeeper::Input()
{

}

void ScoreKeeper::Update()
{
	if (Man->Timers[TimerTimerID]->Elapsed())
	{
		Man->Timers[TimerTimerID]->Reset();

		Timer += 1;
	}
}

void ScoreKeeper::Draw2D()
{
	DrawText(std::to_string(Score).c_str(), 200 - (1 * 45), 75, 45, BLUE);
	DrawText(std::to_string(Timer).c_str(), 700 - (1 * 45), 75, 45, BLUE);
	DrawText(std::to_string(Lives).c_str(), 1200 - (1 * 16), 75, 45, BLUE);
}

void ScoreKeeper::Add(int score)
{
	Score += score;
}

void ScoreKeeper::SetLives(int lives)
{
	Lives = lives;
}

void ScoreKeeper::Reset()
{
	Score = 0;
	Timer = 0;
}
