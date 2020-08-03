/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 19:43:56 by jhakala           #+#    #+#             */
/*   Updated: 2020/08/03 23:46:52 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void    ui_draw_line_color(t_xyz_point a, t_xyz_point b, int w, int h, int *pixels)
{
	t_xyz_point point;
    int color, color2;
	float r1, g1, b1, r2, g2, b2;
	int distance;
    int dx;
    int dy;
    int x_val;
    int y_val;
    int e1, e2;

    if (a.x < 0 || b.x < 0 || a.y < 0 || b.y < 0 || a.x >= w || b.x >= w || a.y >= h || b.y >= h)
        return ;
    x_val = a.x < b.x ? 1 : -1;
    y_val = a.y < b.y ? 1 : -1;
    dx = a.x - b.x < 0 ? b.x - a.x: -(b.x - a.x);
    dy = a.y - b.y < 0 ? b.y - a.y: -(b.y - a.y);
    e1 = dx - dy;

    color = a.color;
	color2 = b.color;
	distance = sqrt(dx * dx + dy * dy);
	if (distance == 0)
		return ;
	r1 = (float)(((color >> 24) & 0xFF) - ((color2 >> 24) & 0xFF)) / distance;
	g1 = (float)(((color >> 16) & 0xFF) - ((color2 >> 16) & 0xFF)) / distance;
	b1 = (float)(((color >> 8) & 0xFF) - ((color2 >> 8) & 0xFF)) / distance;

	r2 = r1;
	g2 = g1;
	b2 = b1;

	r1 = 0;
	g1 = 0;
	b1 = 0;
	
	point.x = a.x;
	point.y = a.y;
	color2 = color;
    while (point.x != b.x || point.y != b.y)
    {
		pixels[point.y * w + (point.x)] = color;
		color = color2 + ((int)(r1 -= r2) << 24) + ((int)(g1 -= g2) << 16) + ((int)(b1 -= b2) << 8);
//		pixels[point.y * w + (point.x)] = color2 + ((int)(r1 += r2) << 24) + ((int)(g1 += g2) << 16) + ((int)(b1 += b2) << 8);
        if ((e2 = e1 * 2) > -dy)
        {
            e1 -=dy;
            point.x += x_val;
        }
        if (e2 < dx)
        {
            e1 += dx;
            point.y += y_val;
        }
    }
	pixels[point.y * w + (point.x)] = color;
}
