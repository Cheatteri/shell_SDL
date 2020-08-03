/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 19:26:45 by jhakala           #+#    #+#             */
/*   Updated: 2020/08/03 17:46:39 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_H
# define LIBUI_H

# include "../SDL2-2.0.12/include/SDL.h"
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "structs.h"

void	ui_draw_line_color(t_xyz_point a, t_xyz_point b, int w, int h, int *pixels);

#endif
