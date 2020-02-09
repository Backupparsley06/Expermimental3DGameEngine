#pragma once
#include "IResourceManager.h"

class IEnvironnement {
public:
	//virtual IResourceManager * GetRessourceManager() = 0;
	virtual void Exit() = 0;
	virtual void SetFPS(int fps) = 0;
};

class Environnement : public IEnvironnement {
private:
	bool exit;
	int fps;
public:
	Environnement()
	{
		exit = false;
	}
	void SetFPS(int fps)
	{
		(*this).fps = fps;
	}
	int GetFPS()
	{
		return fps;
	}
	void Exit() {
		exit = true;
	}
	bool IsExit()
	{
		return exit;
	}
};