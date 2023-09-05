/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_accion_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 10:03:19 by rdelicad          #+#    #+#             */
/*   Updated: 2023/09/04 20:55:33 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	load_img_player(t_read *r)
{
	r->tex_pr = mlx_load_png("./img/game/walk/pr.png");
	r->tex_pl = mlx_load_png("./img/game/walk/pl.png");
	r->tex_pd = mlx_load_png("./img/game/walk/pd.png");
	r->tex_pu = mlx_load_png("./img/game/walk/pu.png");
	r->img_pr = mlx_texture_to_image(r->mlx, r->tex_pr);
	r->img_pl = mlx_texture_to_image(r->mlx, r->tex_pl);
	r->img_pd = mlx_texture_to_image(r->mlx, r->tex_pd);
	r->img_pu = mlx_texture_to_image(r->mlx, r->tex_pu);
	clear_tex_player(r);
}

void	load_img_door(t_read *r)
{
	r->tex_close0 = mlx_load_png("./img/game/door/close0.png");
	r->img_open3 = mlx_texture_to_image(r->mlx, r->tex_open3);
	clear_tex_door(r);
}

void	clear_tex_player(t_read *r)
{
	mlx_delete_texture(r->tex_pr);
	mlx_delete_texture(r->tex_pl);
	mlx_delete_texture(r->tex_pd);
	mlx_delete_texture(r->tex_pu);
}

void	clear_tex_door(t_read *r)
{
	mlx_delete_texture(r->tex_close0);
	mlx_delete_texture(r->tex_open3);
}
