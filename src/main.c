#include "test.h"

void	draw_line(int x1, int y1, int x2, int y2, int w, int h, int *pixels)
{
	int color;
	int dx;
	int dy;
	int x, x_val;
	int y, y_val;
	int e1, e2;

	
	if (x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0 || x1 >= w || x2 >= w || y1 >= h || y2 >= h)
		return ;
	x_val = x1 < x2 ? 1 : -1;
	y_val = y1 < y2 ? 1 : -1;
	dx = x1 - x2 < 0 ? x2 - x1: -(x2 - x1);
	dy = y1 - y2 < 0 ? y2 - y1: -(y2 - y1);
	e1 = dx -dy;
	color = 0xFF00FF;
	y = y1;
	x = x1;
	while (x != x2 || y != y2)
	{
//		pixels[y * w + (x * 32 / 8)] = color >> 24; //red
//		pixels[y * w + (x * 32 / 8) + 1] = color >> 16; //green
//		pixels[y * w + (x * 32 / 8) + 1] = color >> 8; //blue
		pixels[y * w + (x)] = 255; //red
//		pixels[y * w + (x * 32 / 8)] = 0 >> 8; //green
//		pixels[y * w + (x * 32 / 8) + 1] = 0 >> 8; //blue
		if ((e2 = e1 * 2) > -dy)
		{
			e1 -=dy;
			x += x_val;
		}
		if (e2 < dx)
		{
			e1 += dx;
			y += y_val;
		}
	}
}


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
		


	while (1)
	{
		if (SDL_PollEvent(&event))
		{
			//(command + q) to quit or pres top left corner x
			if (event.type == SDL_QUIT)
				break;
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
			memset(pixels, 125, ow * oh * sizeof(int));

			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			SDL_RenderClear(renderer);
			
			draw_line(w / 2, h / 2, w / 2 + ow / 4, h / 2 + oh / 4, w, h, pixels);
			
			draw_line(w / 2, h / 2, w / 2 + 100, h / 2 + 100, w, h, pixels);
			draw_line(w / 2, h / 2, w / 2 + 100, h / 2 - 100, w, h, pixels);
			draw_line(w / 2, h / 2, w / 2 - 100, h / 2 - 100, w, h, pixels);
			draw_line(w / 2, h / 2, w / 2 - 100, h / 2 + 100, w, h, pixels);
			
			draw_line(w / 2, h / 2, w / 2 + 50, h / 2 + 100, w, h, pixels);
			draw_line(w / 2, h / 2, w / 2 - 50, h / 2 + 100, w, h, pixels);
			draw_line(w / 2, h / 2, w / 2, h / 2 + 100, w, h, pixels);

			draw_line(w / 2, h / 2, w / 2 + 50, h / 2 - 100, w, h, pixels);
			draw_line(w / 2, h / 2, w / 2 - 50, h / 2 - 100, w, h, pixels);
			draw_line(w / 2, h / 2, w / 2, h / 2 - 100, w, h, pixels);

			draw_line(w / 2, h / 2, w / 2 + 100, h / 2 + 50, w, h, pixels);
			draw_line(w / 2, h / 2, w / 2 + 100, h / 2 - 50, w, h, pixels);
			draw_line(w / 2, h / 2, w / 2 + 100, h / 2, w, h, pixels);

			draw_line(w / 2, h / 2, w / 2 - 100, h / 2 + 50, w, h, pixels);
			draw_line(w / 2, h / 2, w / 2 - 100, h / 2 - 50, w, h, pixels);
			draw_line(w / 2, h / 2, w / 2 - 100, h / 2, w, h, pixels);

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
