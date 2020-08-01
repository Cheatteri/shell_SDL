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
	SDL_Texture *texture = NULL;
	int ow = 0, w = 0;
	int oh = 0, h = 0;
	unsigned int old_time, new_time;
	int *pixels;
	

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		return (error(SDL_GetError()));
	if (!(win = SDL_CreateWindow("Otsikko", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_RESIZABLE)))
		return (error(SDL_GetError()));
	if (!(renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED)))
		return (error(SDL_GetError()));
	SDL_GetWindowSize(win, &ow, &oh);
	if (!(texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, ow, oh)))
		return (error(SDL_GetError()));
	pixels = (int*)malloc(sizeof(int) * (ow * oh));
		
	t_xyz_point a;
	t_xyz_point b;

	while (1)
	{
		if (SDL_PollEvent(&event))
		{
			//(command + q) to quit or pres top left corner x
			if (event.type == SDL_QUIT)
				break;
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
					break ;
				else if (event.key.keysym.sym == SDLK_SPACE)
					printf("w = %d, h = %d\n", w, h);
			}
			SDL_GetWindowSize(win, &w, &h);
			if (ow != w || oh != h)
			{
				free(pixels);
				ow = w;
				oh = h;
				pixels = (int*)malloc(sizeof(int) * (w * h));
				SDL_DestroyTexture(texture);
				if (!(texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, ow, oh)))
					return (error(SDL_GetError()));
			}
			ft_memset(pixels, 125, ow * oh * sizeof(int));

			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			SDL_RenderClear(renderer);
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
			a.x = w / 2;
			a.y = h / 2;
			b.x = w / 2 + w / 4;
			b.y = h / 2 + h / 4;
			old_time = SDL_GetTicks();
			for (int z = 0; z < 100000; z++)
				ui_draw_line(a, b, w, h, pixels);
			new_time = SDL_GetTicks();
			printf("own ui_draw_line tic rate = '%4u',", new_time - old_time);
			old_time = SDL_GetTicks();
			for (int z = 0; z < 100000; z++)
				SDL_RenderDrawLine(renderer, w / 2, h / 2, w / 2 + ow / 4, h / 2 + oh / 4);
			new_time = SDL_GetTicks();
			printf("%4u, SDL_RenderDrawLine tic rate\n", new_time - old_time);

			b.x = a.x - 100;
			b.y = a.y + 78;
			ui_draw_line(a, b, w, h, pixels);

			SDL_UpdateTexture(texture, NULL, pixels, ow * sizeof(int));
			SDL_RenderCopy(renderer, texture, NULL, NULL);
			SDL_RenderPresent(renderer);
		}
	}
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	return (0);
}
