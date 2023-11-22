#pragma once
#include "Model3D.h"
#include "Managers.h"
#include "Border.h"

class PlayerShared : public Model3D
{
public:
	PlayerShared();
	virtual ~PlayerShared();

	void SetManagersRef(Managers* man);
	void SetBorderRef(Border* borders);
	void SetBorderSound(Sound borderHit);

	virtual bool Initialize();
	virtual bool BeginRun(Camera* camera);

	virtual void Update(float deltaTime);
	virtual void Draw();

protected:
	Sound BorderHitSound = {};

	Camera* Cam = {};
	Managers* Man = {};
	Border* Borders = {};

	bool CheckBorderHit();

private:

};
