#include "EnemyThree.h"

EnemyThree::EnemyThree()
{
}

EnemyThree::~EnemyThree()
{
}

bool EnemyThree::Initialize()
{
	EnemyFires::Initialize();

	return false;
}

bool EnemyThree::BeginRun(Camera* camera)
{
	EnemyFires::BeginRun(camera);

	return false;
}

void EnemyThree::Update(float deltaTime)
{
	EnemyFires::Update(deltaTime);

}

void EnemyThree::Draw()
{
	EnemyFires::Draw();

}

void EnemyThree::Spawn()
{
	EnemyFires::Spawn();


}
