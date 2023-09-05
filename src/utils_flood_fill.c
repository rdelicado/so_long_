/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_flood_fill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:31:05 by rdelicad          #+#    #+#             */
/*   Updated: 2023/09/04 20:57:16 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	position_obj(char **map, int *obj_x, int *obj_y, char obj)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == obj)
			{
				*obj_x = j;
				*obj_y = i;
			}
			j++;
		}
		i++;
	}
}

void	points_obj(t_read *r)
{
	t_point	size;
	t_point	init;

	position_obj(r->copy_m, &r->ex, &r->ey, r->obj_e);
	position_obj(r->copy_m, &r->px, &r->py, r->obj_p);
	size.x = r->column;
	size.y = r->row;
	init.x = r->px;
	init.y = r->py;
	flood_fill(r, size, init);
}

void	flood_fill(t_read *r, t_point size, t_point curr)
{
	if (curr.x < 0 || curr.x >= size.x || \
		curr.y < 0 || curr.y >= size.y || \
		r->copy_m[curr.y][curr.x] == '1' || r->copy_m[curr.y][curr.x] == '.')
		return ;
	r->copy_m[curr.y][curr.x] = '.';
	flood_fill(r, size, (t_point){curr.x - 1, curr.y});
	flood_fill(r, size, (t_point){curr.x + 1, curr.y});
	flood_fill(r, size, (t_point){curr.x, curr.y - 1});
	flood_fill(r, size, (t_point){curr.x, curr.y + 1});
}

int	check_collectionable(t_read *r)
{
	int	i;
	int	j;

	i = 0;
	while (r->copy_m[i])
	{
		j = 0;
		while (r->copy_m[i][j])
		{
			if (r->copy_m[i][j] == 'C')
			{
				if (r->copy_m[i][j] != '.')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
