#pragma once
#include "IPoint.h"

class IRay {
public:
	virtual IPoint * GetOrigine() = 0;
	virtual IPoint * GetDestination() = 0;
	virtual Point GetTrajectory() = 0;
};

class Ray : public IRay{
	IPoint * p1;
	IPoint * p2;
public:
	Ray() {
		this->p1 = new Point();
		this->p1 = new Point();
	}

	Ray(IPoint * p1) {
		this->p1 = new Point(*p1);
		this->p2 = new Point();
	}

	Ray (IPoint * p1, IPoint * p2){
		this->p1 = new Point(*p1);
		this->p2 = new Point(*p2);
	}

	IPoint * GetOrigine() {
		return p1;
	}

	IPoint * GetDestination() {
		return p2;
	}

	Point GetTrajectory() {
		return Point(p2->GetX() - p1->GetX(), 
			p2->GetY() - p1->GetY(), 
			p2->GetZ() - p1->GetZ());
	}

	~Ray() {
		delete p1;
		delete p2;
	}
};