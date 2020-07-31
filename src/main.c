#include "test.h"



int		error(const char *str)
{
	printf("%s\n", str);
	return (0);
}

int		main(void)
{
	SDL_Window *win = NULL;
	SDL_Event event;
	SDL_Renderer *renderer = NULL;
	
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		return (error(SDL_GetError()));
	if (!(win = SDL_CreateWindow("Otsikko", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_RESIZABLE)))
		return (error(SDL_GetError()));
	if (!(renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED)))
		return (error(SDL_GetError()));
	while (1)
	{
		if (SDL_PollEvent(&event))
		{
			//(command + q) to quit or pres top left corner x
			if (event.type == SDL_QUIT)
				break;
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			SDL_RenderClear(renderer);
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
			for (int i = 0; i < 600; i++)
				SDL_RenderDrawPoint(renderer, i, i);
			SDL_RenderPresent(renderer);
		}
	}
	SDL_Quit();
	return (0);
}
