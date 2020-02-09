#pragma once

class IPoint {
public:
	virtual float GetX() const = 0;
	virtual float GetY() const = 0;
	virtual float GetZ() const = 0;
};

class Point : public IPoint {
	float x, y, z;
public:
	Point(const IPoint & p)
	{
		Set(p);
	}

	Point() {
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	Point(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void Set(const IPoint & p) {
		x = p.GetX();
		y = p.GetY();
		z = p.GetZ();
	}

	float GetX() const
	{
		return x;
	}

	float GetY() const
	{
		return y;
	}

	float GetZ() const
	{
		return z;
	}
};