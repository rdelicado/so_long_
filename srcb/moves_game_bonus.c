/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:48:14 by rdelicad          #+#    #+#             */
/*   Updated: 2023/09/04 23:03:40 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	print_move_game(t_read *r)
{
	char	*moves;

	moves = ft_itoa(r->cont);
	mlx_image_to_window(r->mlx, r->img_walls, 0, 0);
	mlx_put_string(r->mlx, moves, 5, 5);
	free(moves);
}
