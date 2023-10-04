#include "EnemyController.h"

EnemyController::EnemyController()
{

}

EnemyController::~EnemyController()
{
}

void EnemyController::SetManagersRef(Managers& man)
{
	Man = &man;
}

void EnemyController::SetCameraRef(Camera& cam)
{
	Cam = &cam;
}

void EnemyController::SetPlayerRef(Player* player)
{
	ThePlayer = player;
}

void EnemyController::SetBorderRef(Border* borders)
{
	Borders = borders;
}

void EnemyController::SetScoreKeeperRef(ScoreKeeper* score)
{
	Score = score;
}

void EnemyController::SetShipOneModelID(size_t modelID)
{
	ShipOneModelID = modelID;
}

void EnemyController::SetShipTwoModelID(size_t modelID)
{
	ShipTwoModelID = modelID;
}

void EnemyController::SetShotModelID(size_t modelID)
{
	ShotModelID = modelID;
}

void EnemyController::SetSounds(Sound oneHit, Sound twoHit, Sound twoFire)
{
	OneHitSound = oneHit;
	TwoHitSound = twoHit;
	TwoFireSound = twoFire;
}

bool EnemyController::Initialize()
{

	return false;
}

bool EnemyController::BeginRun()
{
	SpawnTimerID = Man->EM.AddTimer(3.0f);

	return false;
}

void EnemyController::Update()
{
	if (Man->EM.Timers[SpawnTimerID]->Elapsed())
	{
		Man->EM.Timers[SpawnTimerID]->Reset();
		SpawnOne(5);

		if (WaveOne > 5)
		{
			SpawnTwo(2);
		}
	}

}

void EnemyController::Draw()
{

}

void EnemyController::Reset()
{
	for (auto one : Ones)
	{
		one->Enabled = false;
	}

	for (auto two : Twos)
	{
		two->Enabled = false;

		for (auto shot : two->Shots)
		{
			shot->Enabled = false;
		}
	}

	WaveOne = 0;
}

void EnemyController::SpawnOne(size_t count)
{
	for (int one = 0; one < count; one++)
	{
		bool spawnNewOne = true;
		size_t oneNumber = Ones.size();

		for (size_t oneCheck = 0; oneCheck < oneNumber; oneCheck++)
		{
			if (!Ones[oneCheck]->Enabled)
			{
				spawnNewOne = false;
				oneNumber = oneCheck;
				break;
			}
		}

		if (spawnNewOne)
		{
			Ones.push_back(new EnemyOne());
			Man->EM.AddModel3D(Ones[oneNumber],
				Man->CM.GetModel(ShipOneModelID), 15.0f, Cam);
			Ones[oneNumber]->SetManagersRef(Man->EM);
			Ones[oneNumber]->SetPlayerRef(ThePlayer);
			Ones[oneNumber]->SetBorderRef(Borders);
			Ones[oneNumber]->SetScoreKeeperRef(Score);
			Ones[oneNumber]->SetSound(OneHitSound);
		}

		Ones[oneNumber]->Spawn();
	}

	WaveOne++;
}

void EnemyController::SpawnTwo(size_t count)
{
	for (int two = 0; two < count; two++)
	{
		bool spawnNewTwo = true;
		size_t twoNumber = Twos.size();

		for (size_t twoCheck = 0; twoCheck < twoNumber; twoCheck++)
		{
			if (!Twos[twoCheck]->Enabled)
			{
				spawnNewTwo = false;
				twoNumber = twoCheck;
				break;
			}
		}

		if (spawnNewTwo)
		{
			Twos.push_back(new EnemyTwo());
			Man->EM.AddModel3D(Twos[twoNumber],
				Man->CM.GetModel(ShipTwoModelID), 15.0f, Cam);
			Twos[twoNumber]->SetShotModelID(ShotModelID);
			Twos[twoNumber]->SetManagersRef(*Man);
			Twos[twoNumber]->SetPlayerRef(ThePlayer);
			Twos[twoNumber]->SetBorderRef(Borders);
			Twos[twoNumber]->SetScoreKeeperRef(Score);
			Twos[twoNumber]->SetSounds(TwoHitSound, TwoFireSound);
		}

		Twos[twoNumber]->Spawn();
	}
}
