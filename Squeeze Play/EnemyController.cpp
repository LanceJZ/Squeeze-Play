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

void EnemyController::SetShipThreeModelID(size_t modelID)
{
	ShipThreeModelID = modelID;
}

void EnemyController::SetShotModelID(size_t modelID)
{
	ShotModelID = modelID;
}

void EnemyController::SetMissileModelID(size_t modelID)
{
	MissileModelID = modelID;
}

void EnemyController::SetSounds(Sound oneHit, Sound twoHit, Sound twoFire)
{
	OneHitSound = oneHit;
	TwoHitSound = twoHit;
	TwoFireSound = twoFire;
}

void EnemyController::SetExplosionControl(ExplosionControl* explosions)
{
	Explosions = explosions;
}

bool EnemyController::Initialize()
{

	return false;
}

bool EnemyController::BeginRun()
{
	SpawnTimerID = Man->EM.AddTimer(3.0f);

	ESF.SetCameraRef(Cam);
	ESF.SetManagersRef(Man);
	ESF.SetPlayerRef(ThePlayer);

	return true;
}

void EnemyController::Update()
{
	if (Man->EM.Timers[SpawnTimerID]->Elapsed())
	{
		Man->EM.Timers[SpawnTimerID]->Reset();
		SpawnOne(4);

		if (WaveOne > 2)
		{
			SpawnTwo(2);
		}

		if (WaveOne > 3)
		{
			SpawnThree(1);
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
	}

	for (auto three : Threes)
	{
		three->Enabled = false;
	}

	ESF.Reset();

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
			Ones.push_back(DBG_NEW EnemyOne());
			Ones[oneNumber]->SetManagersRef(Man);
			Ones[oneNumber]->SetPlayerRef(ThePlayer);
			Ones[oneNumber]->SetBorderRef(Borders);
			Ones[oneNumber]->SetScoreKeeperRef(Score);
			Ones[oneNumber]->SetExplosionControlRef(Explosions);
			Ones[oneNumber]->SetSound(OneHitSound);
			Man->EM.AddModel3D(Ones[oneNumber],
				Man->CM.GetModel(ShipOneModelID), 15.0f, Cam);
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
			Twos.push_back(DBG_NEW EnemyTwo());
			Twos[twoNumber]->SetManagersRef(Man);
			Twos[twoNumber]->SetShotModelID(ShotModelID);
			Twos[twoNumber]->SetPlayerRef(ThePlayer);
			Twos[twoNumber]->SetBorderRef(Borders);
			Twos[twoNumber]->SetScoreKeeperRef(Score);
			Twos[twoNumber]->SetExplosionControlRef(Explosions);
			Twos[twoNumber]->SetEnemyShotFactoryRef(&ESF);
			Twos[twoNumber]->SetSounds(TwoHitSound, TwoFireSound);
			Man->EM.AddModel3D(Twos[twoNumber],
				Man->CM.GetModel(ShipTwoModelID), 15.0f, Cam);
		}

		Twos[twoNumber]->Spawn();
	}
}

void EnemyController::SpawnThree(size_t count)
{
	for (int three = 0; three < count; three++)
	{
		bool spawnNewThree = true;
		size_t threeNumber = Threes.size();

		for (size_t threeCheck = 0; threeCheck < threeNumber; threeCheck++)
		{
			if (!Threes[threeCheck]->Enabled)
			{
				spawnNewThree = false;
				threeNumber = threeCheck;
				break;
			}
		}

		if (spawnNewThree)
		{
			Threes.push_back(DBG_NEW EnemyThree());
			Threes[threeNumber]->SetManagersRef(Man);
			Threes[threeNumber]->SetShotModelID(MissileModelID);
			Threes[threeNumber]->SetPlayerRef(ThePlayer);
			Threes[threeNumber]->SetBorderRef(Borders);
			Threes[threeNumber]->SetScoreKeeperRef(Score);
			Threes[threeNumber]->SetExplosionControlRef(Explosions);
			Threes[threeNumber]->SetEnemyShotFactoryRef(&ESF);
			Man->EM.AddModel3D(Threes[threeNumber],
				Man->CM.GetModel(ShipThreeModelID), 15, Cam);
		}

		Threes[threeNumber]->Spawn();
	}
}
