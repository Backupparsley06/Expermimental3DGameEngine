#pragma once
#include "SDL.h"
#include "IPoint.h"
#include "IRay.h"
#include "MatricePoint.h"

class IObject {
public:
	virtual IPoint * GetCollisionPoint(IRay * ray) = 0;
	virtual SDL_Color GetCollisionPointColor(IRay * ray) = 0;
};

class Plane : public IObject {
	float A, B, C, W;
public:
	Plane(float A, float B, float C, float W) {
		this->A = A;
		this->B = B;
		this->C = C;
		this->W = W;
	}

	IPoint * GetCollisionPoint(IRay * ray) {
		float num = W - (A * ray->GetOrigine()->GetX())
			- (B * ray->GetOrigine()->GetY())
			- (C * ray->GetOrigine()->GetZ());
		Point trajectory = ray->GetTrajectory();
		float den = (A * trajectory.GetX())
			+ (B * trajectory.GetY())
			+ (C * trajectory.GetZ());
		if (den == 0)
		{
			return nullptr;
		}
		float t = num / den;
		if (t < 0)
		{
			return nullptr;
		}
		return new Point(ray->GetOrigine()->GetX() + (t * trajectory.GetX()),
			ray->GetOrigine()->GetY() + (t * trajectory.GetY()),
			ray->GetOrigine()->GetZ() + (t * trajectory.GetZ()));
	}

	SDL_Color GetCollisionPointColor(IRay * ray) {
		return SDL_Color();
	}
};

class Square : public IObject {
	Point p;
	float width;
	float height;
	Plane * plane;
	SDL_Color color;
public:
	Square(Point p, float width, float height, SDL_Color color) {
		this->p = p;
		this->width = width;
		this->height = height;
		this->color = color;
		ABCW abcw = MatriceHelper::FindABCW( p,
			Point(p.GetX() + width, p.GetY(),p.GetZ()),
			Point(p.GetX(), p.GetY() + height, p.GetZ()));
		plane = new Plane(abcw.A, abcw.B, abcw.C, abcw.W);
	
	}

	IPoint * GetCollisionPoint(IRay * ray) {
		IPoint * collision = plane->GetCollisionPoint(ray);
		if (collision == nullptr) {
			return nullptr;
		}

		//On assume que z ne varie pas
		if (collision->GetX() >= p.GetX() && 
			collision->GetX() <= (p.GetX() + width) &&
			collision->GetY() >= p.GetY() &&
			collision->GetY() <= (p.GetY() + height)) {
			return collision;
		}

		delete collision;
		return nullptr;
	}

	SDL_Color GetCollisionPointColor(IRay * ray) {
		IPoint * collision = GetCollisionPoint(ray);
		if (collision == nullptr)
		{
			SDL_Color vide;
			vide.r = 0;
			vide.g = 0;
			vide.b = 0;
			vide.a = 0;
			return vide;
		}
		return color;
	}

	~Square() {
		delete plane;
	}

};
