/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_accion_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:22:52 by rdelicad          #+#    #+#             */
/*   Updated: 2023/09/01 19:40:07 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	accion_player(t_read *r)
{
	mlx_key_hook(r->mlx, &key_hook, r);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_read	*r;

	r = (t_read *)param;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_player(r, 1, 0);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_player(r, 0, -1);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_player(r, -1, 0);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_player(r, 0, 1);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT)
		move_player(r, 1, 0);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT)
		move_player(r, 0, -1);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_REPEAT)
		move_player(r, -1, 0);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT)
		move_player(r, 0, 1);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(0);
}

void	move_player(t_read *r, int nx, int ny)
{
	nx += r->px;
	ny += r->py;
	if (is_valid_position(r, nx, ny))
	{
		if (r->map[r->py][r->px] != 'E')
		{
			r->map[r->py][r->px] = '0';
			mlx_image_to_window(r->mlx, r->img_floor, r->px * WIDTH, \
			r->py * HEIGHT);
		}
		if (r->map[r->py][r->px] == 'E')
		{
			r->map[r->py][r->px] = 'E';
			mlx_image_to_window(r->mlx, r->img_exit, r->px * WIDTH, \
			r->py * HEIGHT);
		}
		r->px = nx;
		r->py = ny;
		player_update(r);
		ft_printf("Nº de movements: %d\n", r->cont);
		r->cont += 1;
	}
}

void	player_update(t_read *r)
{
	if (r->map[r->py][r->px] == '0')
	{
		mlx_image_to_window(r->mlx, r->img_player, \
		r->px * WIDTH, r->py * HEIGHT);
	}
	if (r->map[r->py][r->px] == 'C')
	{
		r->flag_c--;
		mlx_image_to_window(r->mlx, r->img_player, \
		r->px * WIDTH, r->py * HEIGHT);
	}
	if (r->map[r->py][r->px] == 'E')
	{
		mlx_image_to_window(r->mlx, r->img_player, \
		r->px * WIDTH, r->py * HEIGHT);
		if (r->flag_c == 0)
			exit(0);
	}
}

int	is_valid_position(t_read *r, int nx, int ny)
{
	if (r->map[ny][nx] == '1')
		return (0);
	else
		return (1);
}
