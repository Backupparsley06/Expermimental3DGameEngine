#pragma once
#include <map>
#include "SDL.h"


class IResourceManager {
public:
	virtual SDL_Texture * LoadTexture(char * str) = 0;
};

class ResourceManager : public IResourceManager {
	std::map<char *, SDL_Texture *> * textureMap;
	SDL_Renderer * renderer;
public:
	ResourceManager(SDL_Renderer * renderer) {
		textureMap = new std::map<char *, SDL_Texture *>();
		this->renderer = renderer;
	}
	SDL_Texture * LoadTexture(char * str) {
		SDL_Texture * texture = (*textureMap)[str];
	}
};