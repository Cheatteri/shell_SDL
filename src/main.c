#include "test.h"

/*
** keys:
** esc || (command + q) = quit
** space = width and height of window
** f = fps
** t = tickrate comparison detween mine drawline and sdl_renderdrawline (i have color option from start to end)
** (10k or 100k lines both)
** d = distance to draw line from a to b
*/

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
	unsigned int old_time, new_time, old_time2, new_time2;
	unsigned int fps1, fps2;
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
	t_xyz_square s;
	t_xyz_triangle t;

	while (1)
	{
		fps1 = SDL_GetTicks();
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

		t.triangle[0].x = 100;
		t.triangle[0].y = 100;
		t.triangle[0].color = 0xFF000000;
		t.triangle[1].x = 200;
		t.triangle[1].y = 150;
		t.triangle[1].color = 0x0000FF00;
		t.triangle[2].x = 150;
		t.triangle[2].y = 200;
		t.triangle[2].color = 0x00FF0000;

		ui_draw_line_color(t.triangle[0], t.triangle[1], w, h, pixels);
		ui_draw_line_color(t.triangle[1], t.triangle[2], w, h, pixels);
		ui_draw_line_color(t.triangle[2], t.triangle[0], w, h, pixels);
		t.triangle[2].x = 250;
		t.triangle[1].x = 300;
		t.triangle[0].x = 200;
		ui_draw_triangle_color(t, w, h, pixels);
//
		t.triangle[0].x = 300;
		t.triangle[0].y = 300;
		t.triangle[0].color = 0xFF000000;
		t.triangle[1].x = 600;
		t.triangle[1].y = 600;
		t.triangle[1].color = 0x0000FF00;
		t.triangle[2].x = 200;
		t.triangle[2].y = 700;
		t.triangle[2].color = 0x00FF0000;
		ui_draw_triangle_color(t, w, h, pixels);

		t.triangle[0].x = 300;
		t.triangle[2].y = 300;
		t.triangle[0].color = 0xFF000000;
		t.triangle[1].x = 600;
		t.triangle[1].y = 600;
		t.triangle[1].color = 0x0000FF00;
		t.triangle[2].x = 601;
		t.triangle[0].y = 299;
		t.triangle[2].color = 0x00FF0000;
		ui_draw_triangle_color(t, w, h, pixels);
//

//		printf("vertailu = %08x\n", pixels[1]);
//		break ;
		
		s.square[0].x = 100;
		s.square[0].y = 100;
		s.square[0].color = 0xFFFFFF01;
		s.square[1].x = 200;
		s.square[1].y = 100;
		s.square[1].color = 0x00FF0000;
		s.square[2].x = 100;
		s.square[2].y = 200;
		s.square[2].color = 0x00000000;
		s.square[3].x = 200;
		s.square[3].y = 200;
		s.square[3].color = 0x00000000;
		
//		ui_draw_square_color(s, w, h, pixels);
		
		s.square[0].x = 300;
		s.square[0].y = 100;
		s.square[0].color = 0xFFFFFF00;
		s.square[1].x = 400;
		s.square[1].y = 100;
		s.square[1].color = 0x00FF0000;
		s.square[2].x = 300;
		s.square[2].y = 200;
		s.square[2].color = 0x00000000;
		s.square[3].x = 350;
		s.square[3].y = 200;
		s.square[3].color = 0x00000000;
		
//		ui_draw_square_color(s, w, h, pixels);

		s.square[0].x = 100;
		s.square[0].y = 300;
		s.square[0].color = 0xFFFFFF01;
		s.square[1].x = 200;
		s.square[1].y = 300;
		s.square[1].color = 0x00FF0000;
		s.square[2].x = 100;
		s.square[2].y = 400;
		s.square[2].color = 0x00000000;
		s.square[3].x = 250;
		s.square[3].y = 450;
		s.square[3].color = 0x00000000;
		
//		ui_draw_square_color(s, w, h, pixels);

		s.square[0].x = 420;
		s.square[0].y = 302;
		s.square[0].color = 0xFFFFFF01;
		s.square[1].x = 600;
		s.square[1].y = 300;
		s.square[1].color = 0x00FF0000;
		s.square[2].x = 400;
		s.square[2].y = 400;
		s.square[2].color = 0x00000000;
		s.square[3].x = 600;
		s.square[3].y = 450;
		s.square[3].color = 0x00000000;
		
//		ui_draw_square_color(s, w, h, pixels);
//		printf("vertailu = %08x\n", pixels[1]);
//		break ;
//		ui_draw_line_color(s.square[0], s.square[1], w, h, pixels);
//		exit(0);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
		a.x = w / 2;
		a.y = h / 2;
		a.color = 0xFFFFFF00;
		b.x = w / 2 + w / 4;
		b.y = h / 2 + h / 4;
		b.color = 0x00000000;
		old_time = SDL_GetTicks();
//		for (int z = 0; z < 100000; z++)
//		for (int z = 0; z < 10000; z++)
//			ui_draw_line_color(a, b, w, h, pixels);
		new_time = SDL_GetTicks();

		old_time2 = SDL_GetTicks();
//		for (int z = 0; z < 100000; z++)
		for (int z = 0; z < 10000; z++)
			SDL_RenderDrawLine(renderer, w / 2, h / 2, w / 2 + ow / 4, h / 2 + oh / 4);
		new_time2 = SDL_GetTicks();

		
		b.x = a.x - 100;
		b.y = a.y + 78;
//		ui_draw_line_color(a, b, w, h, pixels);
		
		SDL_UpdateTexture(texture, NULL, pixels, ow * sizeof(int));
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
		fps2 = SDL_GetTicks();
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
				else if (event.key.keysym.sym == SDLK_d)
				{
					int ll = abs(0);
					int lll = abs(100);
					printf("distance = %d\n", (int)sqrt(ll * ll + lll * lll));
				}
				else if (event.key.keysym.sym == SDLK_f)
					printf("FPS = '%3d'\n", 1000 /(fps2 - fps1 != 0 ? fps2 - fps1 : 0));
				else if (event.key.keysym.sym == SDLK_t)
				{
					printf("own ui_draw_line tic rate = '%4u',", new_time - old_time);					
					printf("%4u, SDL_RenderDrawLine tic rate\n", new_time2 - old_time2);
				}
			}
		}
	}
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
//	system("leaks prog");
	return (0);
}
