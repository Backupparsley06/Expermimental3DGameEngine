#pragma once
#include "SDL.h"
#include "IRay.h"
#include "ISpace.h"

class Camera {
	SDL_Texture * texture;
	int height;
	int width;
	int depth;
	IRay * direction;
	Point * p;
public:
	Camera(int height, int width, IRay * direction) {
		this->height = height;
		this->width = width;
		this->direction = direction;
	}

	Camera(int height, int width, int depth) {
		this->height = height;
		this->width = width;
		this->depth = depth;
		p = new Point();
	}

	void DrawRendering(SDL_Renderer * renderer, ISpace * space)
	{

		for (int x = 0; x < width; x++) {
			for (int y = 0; y < height; y++) {
				Point * p2 = new Point(p->GetX() + (x - width / 2) , p->GetY() - (y - (height / 2)), p->GetZ() + depth);
				//Point * p2 = new Point(p->GetX(), p->GetY(), p->GetZ() + depth);
				Ray * r = new Ray(p, p2);
				SDL_Color color = space->GetCollisionPointColor(r);
				SDL_SetRenderDrawColor(renderer,color.r, color.g, color.b, color.a);
				SDL_RenderDrawPoint(renderer, x, y);
				delete r;
				delete p2;
			}
		}
	}

};