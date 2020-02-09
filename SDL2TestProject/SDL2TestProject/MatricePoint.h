#pragma once
#include "IPoint.h"

struct ABCW {
	float A;
	float B;
	float C;
	float W;
};

struct vecteur {
	float x, y, z;
	vecteur(float x, float y, float z){
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

static class MatriceHelper {
public:
	static ABCW FindABCW(Point p1, Point p2, Point p3) {
		//init
		vecteur p1Ap2(p2.GetX() - p1.GetX(), 
			p2.GetY() - p1.GetY(), 
			p2.GetZ() - p1.GetZ());
		vecteur p1Ap3(p3.GetX() - p1.GetX(),
			p3.GetY() - p1.GetY(),
			p3.GetZ() - p1.GetZ());
		ABCW abcw;

		//calculation
		abcw.A = (p1Ap2.y * p1Ap3.z) - (p1Ap3.y * p1Ap2.z);
		abcw.B = -((p1Ap2.x * p1Ap3.z) - (p1Ap3.x * p1Ap2.z));
		abcw.C = (p1Ap2.x * p1Ap3.y) - (p1Ap3.x * p1Ap2.y);
		abcw.W = (abcw.A * p1.GetX())
			+ (abcw.B * p1.GetY())
			+ (abcw.C * p1.GetZ());
		return abcw;
	}
};