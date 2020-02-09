#include <iostream>
#include "SDL.h"
#include "IEnvironnement.h"
#include "Game.h"

void gestionEvenementDeFenetre(IEnvironnement * environnement, SDL_Event * event);

int main(int argc, char* argv[])
{

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window = SDL_CreateWindow("An SDL2 window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_OPENGL);
	SDL_Renderer * renderer = SDL_CreateRenderer(window,-1,0);
	SDL_Event * event = new SDL_Event();
	SDL_SetRenderDrawColor(renderer, 0, 255, 0,255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	Environnement * environnement = new Environnement();
	environnement->SetFPS(30);

	IGame * game = new Game();

	int time = SDL_GetTicks();
	int lastTime = time;
	

	game->Init(environnement, renderer);

	while (!environnement->IsExit())
	{
		
		lastTime = time;
		time = SDL_GetTicks();

		std::cout << time - lastTime << ",";
		
		if (SDL_PollEvent(event))
		{
			if (event->type == SDL_WINDOWEVENT)
			{
				gestionEvenementDeFenetre(environnement, event);
			}
			else
			{
				game->UpdateInputs(event);
			}
		}

		game->Update(environnement, time - lastTime);

		
		SDL_RenderClear(renderer);
		game->Draw(renderer);
		SDL_RenderPresent(renderer);
		for (int ticks = SDL_GetTicks(); 1000 / environnement->GetFPS() > (ticks - time); ticks = SDL_GetTicks());
		

	}

	
	SDL_DestroyRenderer(renderer);
	game->Clean();
	delete game;
	delete event;
	delete environnement;
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

void gestionEvenementDeFenetre(IEnvironnement * environnement, SDL_Event * event)
{
	switch (event->window.event)
	{
	case SDL_WINDOWEVENT_CLOSE:
		environnement->Exit();
		break;
	}
}
