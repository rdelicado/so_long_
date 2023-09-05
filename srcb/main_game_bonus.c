/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:27:28 by rdelicad          #+#    #+#             */
/*   Updated: 2023/09/04 20:52:02 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	check_img(t_read *r)
{
	if (r->texture_walls == NULL)
		ft_error(2, "Failure to open file walls");
	if (r->texture_floor == NULL)
		ft_error(2, "Failure to open file floor");
	if (r->texture_collectable == NULL)
		ft_error(2, "Failure to open file collectable");
	if (r->texture_player == NULL)
		ft_error(2, "Failure to open file player");
}

void	error_img(char c)
{
	if (c == '1')
	{
		ft_error(2, "Failure to load wall image");
		exit(1);
	}
	else if (c == '0')
	{
		ft_error(2, "Failure to load floor image");
		exit(1);
	}
	else if (c == 'P')
	{
		ft_error(2, "Failure to load player image");
		exit(1);
	}
	else if (c == 'C')
	{
		ft_error(2, "Failure to load collectable image");
		exit(1);
	}
	else if (c == 'E')
	{
		ft_error(2, "Failure to load exit image");
		exit(1);
	}
}

void	clear_texture(t_read *r)
{
	mlx_delete_texture(r->texture_walls);
	mlx_delete_texture(r->texture_floor);
	mlx_delete_texture(r->texture_player);
	mlx_delete_texture(r->texture_collectable);
	mlx_delete_texture(r->tex_close0);
}

void	load_map(t_read *r)
{
	load_images(r);
	draw_floor_wall(r, r->map);
	draw_player_objs(r);
}

int32_t	main_game(t_read *r)
{	
	r->mlx = mlx_init(r->column * WIDTH, r->row * HEIGHT, "so_long", false);
	if (!r->mlx)
		return (free(r->mlx), EXIT_FAILURE);
	load_map(r);
	accion_player(r);
	mlx_loop(r->mlx);
	mlx_terminate(r->mlx);
	return (EXIT_SUCCESS);
}
