/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:25:33 by rdelicad          #+#    #+#             */
/*   Updated: 2023/09/02 10:48:37 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	init_struct(t_read *r, char **av)
{
	init_read(r, av);
	init_play_struct(r);
}

void	init_read(t_read *r, char **av)
{
	r->map = NULL;
	r->line = NULL;
	r->file = *(av + 1);
	r->fd = 0;
	r->column = 0;
	r->row = 0;
	r->flag_c = 0;
	r->flag_e = 0;
	r->flag_p = 0;
	r->copy_m = NULL;
	r->px = 0;
	r->py = 0;
	r->cx = 0;
	r->cy = 0;
	r->ex = 0;
	r->ey = 0;
	r->obj_c = 'C';
	r->obj_e = 'E';
	r->obj_p = 'P';
	r->cont = 0;
}

void	init_play_struct(t_read *r)
{
	r->img_floor = NULL;
	r->img_walls = NULL;
	r->img_player = NULL;
	r->img_collectable = NULL;
	r->img_exit = NULL;
	r->img_background = NULL;
	r->img_left_side = NULL;
	r->img_right_side = NULL;
	r->texture_floor = NULL;
	r->texture_walls = NULL;
	r->texture_player = NULL;
	r->texture_collectable = NULL;
	r->texture_exit = NULL;
	r->texture_background = NULL;
	r->texture_left_side = NULL;
	r->texture_right_side = NULL;
}
