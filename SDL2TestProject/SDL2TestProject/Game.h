#pragma once
#include <string>
#include "SDL.h"
#include "IEnvironnement.h"
#include "Camera.h"

using namespace std;

class IGame {
public:
	virtual void Init(IEnvironnement * event, SDL_Renderer * renderer) = 0;
	virtual void UpdateInputs(SDL_Event * event) = 0;
	virtual void Update(IEnvironnement * event, float deltaTime) = 0;
	virtual void Draw(SDL_Renderer * renderer) = 0;
	virtual void Clean() = 0;
};

class Game : public IGame {
private:
	/*
	SDL_Rect * src_rect;
	SDL_Rect * ds_rect;
	SDL_Texture * texture;
	bool left;
	bool right;
	float x;
	float y;
	float velocityX = 0;
	*/
	Camera * camera;
	Space * space;
	Square * square;
public:
	Game() {}

	void Init(IEnvironnement * event, SDL_Renderer * renderer) {
		/*
		left = false;
		right = false;
		src_rect = new SDL_Rect();
		src_rect->x = 0;
		src_rect->y = 0;
		src_rect->h = 16;
		src_rect->w = 16;
		ds_rect = new SDL_Rect();
		ds_rect->y = 32;
		ds_rect->x = 32;
		x = ds_rect->x;
		y = ds_rect->y;
		ds_rect->h = 50;
		ds_rect->w = 50;
		string base_path(SDL_GetBasePath());
		string resourcePath = base_path + "..\\Ressources\\Sprite-0001.bmp";

		SDL_Surface * surface = SDL_LoadBMP(resourcePath.c_str());
		//SDL_SetColorKey(surface, SDL_SRCCOLORKEY, SDL_MapRGB(surface->format, 0, 0, 255));
		texture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP(resourcePath.c_str()));
		*/
		Point p(-10,-10,10);
		SDL_Color c;
		c.r = 255;
		c.g = 0;
		c.b = 0;
		c.a = 0;
		camera = new Camera(400, 600, 100);
		space = new Space();
		square = new Square(p, 20, 20, c);
		space->AddObject(square);
	}
	void UpdateInputs(SDL_Event * event) {
		/*
		if (event->type == SDL_KEYDOWN) {
			if (event->key.keysym.sym == SDLK_d)
			{
				right = true;
			}
			else if (event->key.keysym.sym == SDLK_a)
			{
				left = true;
			}
		}
		else if(event->type == SDL_KEYUP)
		{
			if (event->key.keysym.sym == SDLK_d)
			{
				right = false;
			}
			else if (event->key.keysym.sym == SDLK_a)
			{
				left = false;
			}
		}
		*/
	}

	void Update(IEnvironnement * event, float deltaTime) {
		/*
		if (left) {
			velocityX = -100;
		}
		else if (right)
		{
			velocityX = 100;
		}
		else
		{
			velocityX = 0;
		}
		x += velocityX * deltaTime / 1000;
		ds_rect->x = (int)x;
		*/
	}

	void Draw(SDL_Renderer * renderer) {
		camera->DrawRendering(renderer, space);
		//SDL_Render
		//SDL_RenderDrawRect(renderer, sdl_rect);
		/*
		SDL_RenderCopy(renderer, texture, src_rect, ds_rect);
		*/
	}

	void Clean() {
		delete camera;
		delete space;
		delete square;
		/*
		delete src_rect;
		delete ds_rect;
		*/
	}
};