#pragma once
#include <memory>
#include "raylib.h"
#include "Managers.h"
#include "ExplosionControl.h"
#include "Player.h"
#include "EnemyController.h"
#include "Border.h"
#include "ScoreKeeper.h"

enum GameState
{
	PlayerHit,
	Over,
	InPlay,
	Pause,
	HighScores,
	MainMenu
};


class Game
{
public:
	Game();
	virtual ~Game();

	bool PlayBackgroundMusic = true;
	GameState State = MainMenu;
	Camera Cam = { 0 };

	bool Initialize(Camera &camera);
	bool Load();
	bool BeginRun();
	void ProcessInput();
	void Update(float deltaTime);
	void Draw();

private:
	Managers Man = {};
	ExplosionControl* Explosions = {};
	Player* ThePlayer = {};
	EnemyController* Enemies = {};
	Border* Borders = {};
	ScoreKeeper* ScoreBoard = {};

	void NewGame();
	void Draw3D();
	void Draw2D();
};

