#pragma once
#include "IPoint.h"
#include "IRay.h"
#include "IObject.h"

class ISpace {
public:
	virtual void AddObject(IObject * o) = 0;
	virtual SDL_Color GetCollisionPointColor(IRay * ray) = 0;
};

class Space : public ISpace {
	IObject * obj;
public:
	void AddObject(IObject * o)
	{
		obj = o;
	}
	SDL_Color  GetCollisionPointColor(IRay * ray) {
		return obj->GetCollisionPointColor(ray);
	}
};