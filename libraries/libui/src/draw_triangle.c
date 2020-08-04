/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_triangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 09:49:51 by jhakala           #+#    #+#             */
/*   Updated: 2020/08/04 21:31:45 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	fill(t_xyz_triangle triangle, int w, int h, int *pixels)
{
	int count = 0;
	
	t_xyz_point a = triangle.triangle[0];
	t_xyz_point b = triangle.triangle[1];
	t_xyz_point c = triangle.triangle[2];
//	printf("a%d,%d,%d, y%d,%d,%d\n", a.x, b.x, c.x, a.y, b.y, c.y);
	t_xyz_fpoint s, e;
	t_xyz_point p;
	
	float dx1,dx2,dx3;
	float dr1,dr2,dr3, dg1,dg2,dg3, db1,db2,db3;
	
	float dr, dg, db;
	float arr, brr, crr, srr, err, prr, agg, bgg, cgg, sgg, egg, pgg, abb, bbb, cbb, sbb, ebb, pbb;

	float xx;
	
	arr = (a.color >> 24) & 0xFF;
	brr = (b.color >> 24) & 0xFF;
	crr = (c.color >> 24) & 0xFF;
	
	agg = (a.color >> 16) & 0xFF;
	bgg = (b.color >> 16) & 0xFF;
	cgg = (c.color >> 16) & 0xFF;
	
	abb = (a.color >> 8) & 0xFF;
	bbb = (b.color >> 8) & 0xFF;
	cbb = (c.color >> 8) & 0xFF;

	if (b.y - a.y > 0)
	{
		dx1 = (float)(b.x - a.x) / (float)(b.y - a.y);
		dr1 = (brr - arr) / (b.y - a.y);
		dg1 = (bgg - agg) / (b.y - a.y);
		db1 = (bbb - abb) / (b.y - a.y);
	}
	else
	{
		dx1 = 0;
		dr1 = 0;
		dg1 = 0;
		db1 = 0;
	}
//	printf("\n\ny=%d, %d, %d\n", a.y, b.y, c.y);
//	printf("%f, %f, %f\n", dr1, dg1, db1);
//	printf("%f - %f / %d - %d\n", brr, arr, b.y, a.y);
//	printf("%f - %f / %d - %d\n", bgg, agg, b.y, a.y);
//	printf("%f - %f / %d - %d\n", bbb, abb, b.y, a.y);
	if (c.y - a.y > 0)
	{
		dx2 = (float)(c.x - a.x) / (float)(c.y - a.y);
		dr2 = (crr - arr) / (c.y - a.y);
		dg2 = (cgg - agg) / (c.y - a.y);
		db2 = (cbb - abb) / (c.y - a.y);
	}
	else
	{
		dx2 = 0;
		dr2 = 0;
		dg2 = 0;
		db2 = 0;
	}
//	printf("%f, %f, %f\n", dr2, dg2, db2);
//	printf("%f - %f / %d - %d\n", crr, arr, c.y, a.y);
//	printf("%f - %f / %d - %d\n", cgg, agg, c.y, a.y);
//	printf("%f - %f / %d - %d\n", cbb, abb, c.y, a.y);
	if (c.y - b.y > 0)
	{
		dx3 = (float)(c.x - b.x) / (float)(c.y - b.y);
		dr3 = (crr - brr) / (c.y - b.y);
		dg3 = (cgg - bgg) / (c.y - b.y);
		db3 = (cbb - bbb) / (c.y - b.y);
	}
	else
	{
		dx3 = 0;
		dr3 = 0;
		dg3 = 0;
		db3 = 0;
	}
//	printf("%f, %f, %f\n", dr3, dg3, db3);
//	printf("%f - %f / %d - %d\n", crr, brr, c.y, b.y);
//	printf("%f - %f / %d - %d\n", cgg, bgg, c.y, b.y);
//	printf("%f - %f / %d - %d\n", cbb, bbb, c.y, b.y);
//	s = a;
	s.x = (float)(a.x);
	s.y = (float)(a.y);
	srr = arr;
	sgg = agg;
	sbb = abb;
//	e = a;
	e.x = (float)(a.x);
	e.y = (float)(a.y);
	err = arr;
	egg = agg;
	ebb = abb;
//	printf("here, s.y=%f, b.y=%d\n", s.y, b.y);
//	printf("%f, %f, %f\n", dx1, dx2, dx3);
//	exit(0);
//	return ;
	
//	if (dx1 > dx2)
//	if (1 == 1)
//	{
//	printf("her   e%10f, p%d\n", e.x, p.x);
		for (;s.y <= b.y; s.y++, e.y++)
		{
			if (e.x - s.x > 0)
			{
				dr = (err - srr) / (e.x - s.x);
				dg = (egg - sgg) / (e.x - s.x);
				db = (ebb - sbb) / (e.x - s.x);
			}
			else
			{
				dr = 0;
				dg = 0;
				db = 0;
			}
//			p = s;
			p.x = (int)(s.x);
			p.y = (int)(s.y);
			prr = srr;
			pgg = sgg;
			pbb = sbb;
//			printf("her   e%10f, p%d\n", e.x, p.x);
			for (; p.x < e.x; p.x++)
			{
//				printf("here1.0   %d, %d\n", p.x, p.y);
				if (p.y >= h || p.x >= w)
				{
//					printf("here1\n");
					break ;
				}
				pixels[p.y * w + p.x] = (((int)prr & 0xFF) << 24) + (((int)pgg & 0xFF) << 16) + (((int)pbb & 0xFF) << 8);
				prr += dr;
				pgg += dg;
				pbb += db;
			}
			if (count++ == 99)
			{
//				printf("color, %f, %f, %f\n", srr, sgg, sbb);
//				printf("color, %f, %f, %f\n", dr2, dg2, db2);
//				printf("dr, %f, %f, %f\n", dr, dg, db);
//				printf("dx2=%f\n", dx2);
//				exit(0);
//				return ;
			}
//tama alla eka on alkuperainen
			if (dx1 > dx2)
			{
				s.x += dx2;
				srr += dr2;
				sgg += dg2;
				sbb += db2;
				e.x += dx1;
				err += dr1;
				egg += dg1;
				ebb += db1;
			}
			else
			{
				s.x += dx1;
				srr += dr1;
				sgg += dg1;
				sbb += db1;
				e.x += dx2;
				err += dr2;
				egg += dg2;
				ebb += db2;
			}
			
		}
//		printf("count= %d\n", count);
//		count = 0;
//		exit(0);
//		e = b;
		e.x = (float)(b.x);
		e.y = (float)(b.y);
		err = brr;
		egg = bgg;
		ebb = bbb;
		for (;s.y <= c.y; s.y++, e.y++)
		{
			if (e.x - s.x > 0)
			{
				dr = (err - srr) / (e.x - s.x);
				dg = (egg - sgg) / (e.x - s.x);
				db = (ebb - sbb) / (e.x - s.x);
			}
			else
			{
				dr = 0;
				dg = 0;
				db = 0;
			}
//			p = s;
			p.x = (int)(s.x);
			p.y = (int)(s.y);
			prr = srr;
			pgg = sgg;
			pbb = sbb;
//			printf("-------   e%10f, p%d\n", e.x, p.x);			
			for (; p.x < e.x; p.x++)
			{
//				return ;
//				printf("here2.0\n");				
				if (p.y >= h || p.x >= w)
				{
//					printf("here2\n");
//					printf("BREAK2\n");
//					exit(0);
					break ;
				}
				pixels[p.y * w + p.x] = (((int)prr & 0xFF) << 24) + (((int)pgg & 0xFF) << 16) + (((int)pbb & 0xFF) << 8);
				prr += dr;
				pgg += dg;
				pbb += db;
			}
			count++;
			if (dx1 > dx2)
			{
				s.x += dx2;
				srr += dr2;
				sgg += dg2;
				sbb += db2;
				e.x += dx3;
				err += dr3;
				egg += dg3;
				ebb += db3;
			}
			else
			{
				s.x += dx3;
				srr += dr3;
				sgg += dg3;
				sbb += db3;
				e.x += dx2;
				err += dr2;
				egg += dg2;
				ebb += db2;
			}
		}
//		printf("count = %d\n", count);
//		exit(0);
//	}
	/*
	else
	{
				printf("1.5\n");
				//starting to alter from here to get same
		for (; s.x <= b.x; s.x++, e.x++)
		{
							printf("2.5\n");
			if (e.y - s.y > 0)
			{
				dr = (err - srr) / (e.y - s.y);
				dg = (egg - sgg) / (e.y - s.y);
				db = (ebb - sbb) / (e.y - s.y);
			}
			else
			{
				dr = 0;
				dg = 0;
				db = 0;
			}
//			p = s;
			p.x = (int)(s.x);
			p.y = (int)(s.y);
			prr = srr;
			pgg = sgg;
			pbb = sbb;
			for (; p.y < e.y; p.y++)
			{
				if (p.y >= h || p.x >= w)
				{
					printf("hoi\n");
					break ;
				}
				pixels[p.y * w + p.x] = (((int)prr & 0xFF) << 24) + (((int)pgg & 0xFF) << 16) + (((int)pbb & 0xFF) << 8);
				prr += dr;
				pgg += dg;
				pbb += db;
			}
			s.y += dx1;
			srr += dr1;
			sgg += dg1;
			sbb += db1;
			e.y += dx2;
			err += dr2;
			egg += dg2;
			ebb += db2;
		}
//		s = b;
		s.x = (float)(b.x);
		s.y = (float)(b.y);
		srr = brr;
		sgg = bgg;
		sbb = bbb;
		for (;s.x <= b.x; s.x++, e.x++)
		{
			if (e.y - s.y > 0)
			{
				dr = (err - srr) / (e.y - s.y);
				dg = (egg - sgg) / (e.y - s.y);
				db = (ebb - sbb) / (e.y - s.y);
			}
			else
			{
				dr = 0;
				dg = 0;
				db = 0;
			}
//			p = s;
			p.x = (int)(s.x);
			p.y = (int)(s.y);
			prr = srr;
			pgg = sgg;
			pbb = sbb;
			for (; p.y < e.y; p.y++)
			{
				if (p.y >= h || p.x >= w)
					break;
				pixels[p.y * w + p.x] = (((int)prr & 0xFF) << 24) + (((int)pgg & 0xFF) << 16) + (((int)pbb & 0xFF) << 8);
				prr += dr;
				pgg += dg;
				pbb += db;
			}
			s.y += dx3;
			srr += dr3;
			sgg += dg3;
			sbb += db3;
			e.y += dx2;
			err += dr2;
			egg += dg2;
			ebb += db2;
		}
		}*/
}

void	printtt(t_xyz_triangle t)
{
	printf("%08x, %d\n", t.triangle[0].color, t.triangle[0].y);
	printf("%08x, %d\n", t.triangle[1].color, t.triangle[1].y);
	printf("%08x, %d\n", t.triangle[2].color, t.triangle[2].y);

}

void	ui_draw_triangle_color(t_xyz_triangle triangle, int w, int h, int *pixels)
{
	t_xyz_point tmp;
//	ui_draw_line_color(triangle.triangle[0], triangle.triangle[1], w, h, pixels);
//	ui_draw_line_color(triangle.triangle[1], triangle.triangle[2], w, h, pixels);
//	ui_draw_line_color(triangle.triangle[2], triangle.triangle[0], w, h, pixels);

//	printtt(triangle);
	for (int i = 0; i < 2; i++)
	{
//		printf("i=%d\n", i);
		if (triangle.triangle[i].y > triangle.triangle[i + 1].y)
		{
			tmp = triangle.triangle[i];
			triangle.triangle[i] = triangle.triangle[i + 1];
			triangle.triangle[i + 1] = tmp;
//			printf("----------change i=%d\n", i);
//				printtt(triangle);
			i = -1;
		}
	}
//	exit(0);
	fill(triangle, w, h, pixels);
//	printf("%d, ", triangle.triangle[0].y);
//	printf("%d, ", triangle.triangle[1].y);
//	printf("%d\n", triangle.triangle[2].y);
	
}
