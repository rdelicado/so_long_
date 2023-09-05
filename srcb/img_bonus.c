/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:50:14 by rdelicad          #+#    #+#             */
/*   Updated: 2023/09/04 20:53:10 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	load_images(t_read *r)
{
	load_img_player(r);
	r->texture_player = mlx_load_png("./img/game/walk/pr.png");
	r->texture_floor = mlx_load_png("./img/game/tiles.png");
	r->texture_walls = mlx_load_png("./img/game/wall.png");
	r->texture_collectable = mlx_load_png("./img/game/diamante.png");
	r->tex_mon1 = mlx_load_png("./img/game/zombie/mr.png");
	r->tex_close0 = mlx_load_png("./img/game/door/close0.png");
	r->tex_death = mlx_load_png("./img/game/death/17.png");
	check_img(r);
	r->img_player = mlx_texture_to_image(r->mlx, r->texture_player);
	r->img_floor = mlx_texture_to_image(r->mlx, r->texture_floor);
	r->img_walls = mlx_texture_to_image(r->mlx, r->texture_walls);
	r->img_collectable = mlx_texture_to_image(r->mlx, r->texture_collectable);
	r->img_mon1 = mlx_texture_to_image(r->mlx, r->tex_mon1);
	r->img_death = mlx_texture_to_image(r->mlx, r->tex_death);
	r->img_close0 = mlx_texture_to_image(r->mlx, r->tex_close0);
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
	else if (map[i][j] == '0' || map[i][j] == 'C' || map[i][j] == 'P' \
			|| map[i][j] == 'M' || map[i][j] == 'E')
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
	if (r->map[i][j] == 'M')
	{
		if ((mlx_image_to_window(r->mlx, r->img_mon1, \
		j * WIDTH, i * HEIGHT)) < 0)
			error_img1('M');
	}
}

void	draw_player_objs(t_read *r)
{
	if (r->map[r->ey][r->ex] == 'E')
	{
		if ((mlx_image_to_window(r->mlx, r->img_close0, r->ex * WIDTH, \
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

void	error_img1(char c)
{
	if (c == 'M')
	{
		ft_error(2, "Failure to load monster image");
		exit(1);
	}
}
