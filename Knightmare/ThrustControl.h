#pragma once
#include "Common.h"

#ifdef _DEBUG
	#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
	// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
	// allocations to be of _CLIENT_BLOCK type
#else
	#define DBG_NEW new
#endif

class ThrustControl : public Common
{
public:
	ThrustControl();
	virtual ~ThrustControl();

	bool Initialize();
	bool BeginRun();

	void Input();
	void Update();
	void Draw();

private:

};

