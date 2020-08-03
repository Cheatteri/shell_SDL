/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 18:51:44 by jhakala           #+#    #+#             */
/*   Updated: 2020/08/04 00:29:47 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

float calc_distance(t_xyz_point a, t_xyz_point b)
{
	return (sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
}


void	something(t_xyz_point a[2], t_xyz_point b[2], float times, int w, int h, int *pixels)
{
	t_xyz_point point[2];
    int dx[2];
    int dy[2];
    int x_val[2];
    int y_val[2];
    int e1[2], e2[2];
	float count;

	count = times;
	if (a[0].x < 0 || b[0].x < 0 || a[0].y < 0 || b[0].y < 0 || a[0].x >= w || b[0].x >= w || a[0].y >= h || b[0].y >= h)
        return ;
	if (a[1].x < 0 || b[1].x < 0 || a[1].y < 0 || b[1].y < 0 || a[1].x >= w || b[1].x >= w || a[1].y >= h || b[1].y >= h)
        return ;

	x_val[0] = a[0].x < a[1].x ? 1 : -1;
    y_val[0] = a[0].y < a[1].y ? 1 : -1;
	dx[0] = a[0].x - a[1].x < 0 ? a[1].x - a[0].x: -(a[1].x - a[0].x);
    dy[0] = a[0].y - a[1].y < 0 ? a[1].y - a[0].y: -(a[1].y - a[0].y);
	e1[0] = dx[0] - dy[0];
	point[0].x = a[0].x;
	point[0].y = a[0].y;
	point[0].color = pixels[point[0].y * w + point[0].x];

	x_val[1] = b[0].x < b[1].x ? 1 : -1;
    y_val[1] = b[0].y < b[1].y ? 1 : -1;
	dx[1] = b[0].x - b[1].x < 0 ? b[1].x - b[0].x: -(b[1].x - b[0].x);
    dy[1] = b[0].y - b[1].y < 0 ? b[1].y - b[0].y: -(b[1].y - b[0].y);
	e1[1] = dx[1] - dy[1];
	point[1].x = b[0].x;
	point[1].y = b[0].y;
	point[1].color = pixels[point[1].y * w + point[1].x];

	while (point[0].x != a[1].x || point[0].y != a[1].y)
	{
		if (point[0].color == 0x7b7b7b00 || point[1].color == 0x7b7b7b00)
		{
			printf("saman\n");
//			exit(0);
		}
		ui_draw_line_color(point[0], point[1], w, h, pixels);
		if (times >= 1)
		{
			if ((e2[1] = e1[1] * 2) > -dy[1])
			{
				e1[1] -= dy[1];
				point[1].x += x_val[1];
			}
			if (e2[1] < dx[1])
			{
				e1[1] = dx[1];
				point[1].y += y_val[1];
			}
			point[1].color = pixels[point[1].y * w + point[1].x];
			times -= 1;
		}
//		printf("times=%f\n",  times);
		if ((e2[0] = e1[0] * 2) > -dy[0])
		{
			e1[0] -= dy[0];
			point[0].x += x_val[0];
		}
		if (e2[0] < dx[0])
		{
			e1[0] = dx[0];
			point[0].y += y_val[0];
		}
		point[0].color = pixels[point[0].y * w + point[0].x];
		times += count;
	}
}
			
	
void	ui_draw_square_color(t_xyz_square square, int w, int h, int *pixels)
{
	t_xyz_point a[2];
	t_xyz_point b[2];
	float dist, dist1, dist2;
	float times;
	
	ui_draw_line_color(square.square[0], square.square[1], w, h, pixels);
	ui_draw_line_color(square.square[2], square.square[3], w, h, pixels);
	dist1 = calc_distance(square.square[0], square.square[1]);
	dist2 = calc_distance(square.square[2], square.square[3]);


	a[0] = square.square[0];
	a[1] = square.square[1];
	b[0] = square.square[2];
	b[1] = square.square[3];


	times = dist1 > dist2 ? (float)(dist2) / (float)(dist1) : (float)(dist1) / (float)(dist2);

//	printf("times=%f\n",  times);
	dist1 >= dist2 ? something(a, b, times, w, h, pixels) : something(b, a, times, w, h, pixels);

//	dist1 < dist2 ? something(a, b, times, w, h, pixels) : something(b, a, times, w, h, pixels);
	dist = dist1 > dist2 ? dist1 : dist2;

//	printf("dist=%d, float=%f\n", dist, times);
//	printf("d1=%d, d2=%d\n", dist1, dist2);	

	
//	ui_draw_color
}
