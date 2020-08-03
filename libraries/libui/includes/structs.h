/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 19:34:21 by jhakala           #+#    #+#             */
/*   Updated: 2020/08/03 18:59:17 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct		s_xyz_point
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_xyz_point;

typedef struct		s_xyz_square
{
	t_xyz_point		square[4];
}					t_xyz_square;

#endif
