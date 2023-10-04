#pragma once
#include "Common.h"
#include "Managers.h"
#include "ParticleCube.h"

#ifdef _DEBUG
	#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
	// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
	// allocations to be of _CLIENT_BLOCK type
#else
	#define DBG_NEW new
#endif

class ExplosionControl : public Common
{
public:
	ExplosionControl();
	virtual ~ExplosionControl();

	void SetCamera(Camera &camera);
	void SetManagers(Managers& managers);
	void SetCubeModel(Model model);
	bool Initialize();
	bool BeginRun();

	virtual void Update(float deltaTime);

	void Spawn(Vector3 position, int count, float time);
	void Reset();

private:
	std::vector<ParticleCube*> Particles;

	Model CubeModel = {};
	Camera* Cam = {};
	Managers* Man = {};

	size_t SpawnPool();
};

