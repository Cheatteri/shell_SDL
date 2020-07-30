#include "test.h"

int		error(const char *str)
{
	printf("%s\n", str);
	return (0);
}

int		main(void)
{
	SDL_Window *win;
	SDL_Event event;
	
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		return (error(SDL_GetError()));
	if (!(win = SDL_CreateWindow("Otsikko", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_RESIZABLE)))
		return (error(SDL_GetError()));
	while (1)
	{
		if (SDL_PollEvent(&event))
		{
			//(command + q) to quit or pres top left corner x
			if (event.type == SDL_QUIT)
			{
				break;
			}
		}
	}
	SDL_Quit();
	return (0);
}
