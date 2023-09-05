/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:50:14 by rdelicad          #+#    #+#             */
/*   Updated: 2023/09/02 10:27:59 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_images(t_read *r)
{
	r->texture_floor = mlx_load_png("./img/game/tiles.png");
	r->texture_walls = mlx_load_png("./img/game/wall.png");
	r->texture_player = mlx_load_png("./img/game/player.png");
	r->texture_collectable = mlx_load_png("./img/game/diamante.png");
	r->texture_exit = mlx_load_png("./img/game/mago.png");
	check_img(r);
	r->img_exit = mlx_texture_to_image(r->mlx, r->texture_exit);
	r->img_floor = mlx_texture_to_image(r->mlx, r->texture_floor);
	r->img_player = mlx_texture_to_image(r->mlx, r->texture_player);
	r->img_walls = mlx_texture_to_image(r->mlx, r->texture_walls);
	r->img_collectable = mlx_texture_to_image(r->mlx, r->texture_collectable);
	clear_texture(r);
}

void	draw_floor_wall(t_read *r, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			assign_img_to_map(r, map, i, j);
			j++;
		}
		i++;
	}
}

void	assign_img_to_map(t_read *r, char **map, int i, int j)
{
	if (map[i][j] == '1')
	{
		if ((mlx_image_to_window(r->mlx, r->img_walls, \
		j * WIDTH, i * HEIGHT)) < 0)
			error_img('1');
	}
	else if (map[i][j] == '0' || map[i][j] == 'C' || map[i][j] == 'P')
	{
		if ((mlx_image_to_window(r->mlx, r->img_floor, \
		j * WIDTH, i * HEIGHT)) < 0)
			error_img('0');
	}
	if (map[i][j] == 'C')
	{
		if ((mlx_image_to_window(r->mlx, r->img_collectable, \
		j * WIDTH, i * HEIGHT)) < 0)
			error_img('C');
	}
}

void	draw_player_objs(t_read *r)
{
	if (r->map[r->ey][r->ex] == 'E')
	{
		if ((mlx_image_to_window(r->mlx, r->img_exit, r->ex * WIDTH, \
		r->ey * HEIGHT)) < 0)
			error_img('E');
	}
	if (r->map[r->py][r->px] == 'P')
	{
		if ((mlx_image_to_window(r->mlx, r->img_player, r->px * WIDTH, \
		r->py * HEIGHT)) < 0)
			error_img('P');
	}
}
