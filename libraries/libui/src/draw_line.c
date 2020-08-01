/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 19:43:56 by jhakala           #+#    #+#             */
/*   Updated: 2020/08/01 21:35:40 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void    ui_draw_line(t_xyz_point a, t_xyz_point b, int w, int h, int *pixels)
{
	t_xyz_point point;
    int color;
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
    e1 = dx -dy;
    color = 0xFF00FF;
	point.x = a.x;
	point.y = a.y;
    while (point.x != b.x || point.y != b.y)
    {
//      pixels[y * w + (x * 32 / 8)] = color >> 24; //red
//      pixels[y * w + (x * 32 / 8) + 1] = color >> 16; //green
//      pixels[y * w + (x * 32 / 8) + 1] = color >> 8; //blue
        pixels[point.y * w + (point.x)] = 255; //red
//      pixels[y * w + (x * 32 / 8)] = 0 >> 8; //green
//      pixels[y * w + (x * 32 / 8) + 1] = 0 >> 8; //blue
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
}
