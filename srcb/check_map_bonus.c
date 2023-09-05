/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:31:05 by rdelicad          #+#    #+#             */
/*   Updated: 2023/09/02 10:48:00 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	check_map(t_read *r)
{
	if (!rectagular_map(r))
	{
		ft_error(2, "Not rectangular map or exceeds the wall");
		exit(1);
	}
	if (!surrounded_by_walls(r))
	{
		ft_error(2, "The map is not surrounded by walls");
		exit(1);
	}
	if (!player_output_object(r))
	{
		ft_error(2, "No player, object o output");
		exit(1);
	}
	if (!dead_end_player(r))
	{
		ft_error(2, "dead-end player");
		exit(1);
	}
}

int	rectagular_map(t_read *r)
{
	int		row;

	r->column = (int)ft_strlen(r->map[0]);
	row = 0;
	while (r->map[row] != NULL)
		row++;
	r->row = row;
	if (r->row >= r->column)
		return (0);
	row = 0;
	while (r->map[row])
	{
		if (row <= r->column - 1)
		{
			if (r->column != (int)ft_strlen(r->map[row]))
				return (0);
		}
		else
			return (0);
		row++;
	}
	return (1);
}

int	surrounded_by_walls(t_read *r)
{
	int	i;
	int	j;

	i = 0;
	while (r->map[i])
		i++;
	r->row = i;
	i = -1;
	while (r->map[++i])
	{
		j = 0;
		if (i == 0 || i == r->row - 1)
		{
			while (j < r->column)
			{
				if (r->map[i][j++] != '1')
					return (0);
			}
		}
		else if (r->map[i][0] != '1' || r->map[i][r->column - 1] != '1')
			return (0);
	}
	return (1);
}

int	player_output_object(t_read *r)
{
	int		i;
	int		j;

	i = 0;
	while (r->map[i])
	{
		j = 0;
		while (r->map[i][j++])
		{
			if (r->map[i][j] == 'P')
				r->flag_p++;
			if (r->map[i][j] == 'C')
				r->flag_c++;
			if (r->map[i][j] == 'E')
				r->flag_e++;
		}
		i++;
	}
	if (r->flag_p < 1 || r->flag_p > 1)
		return (0);
	if (r->flag_c < 1)
		return (0);
	if (r->flag_e < 1 || r->flag_e > 1)
		return (0);
	return (1);
}

int	dead_end_player(t_read *r)
{
	copy_map(r);
	points_obj(r);
	if (r->copy_m[r->ey][r->ex] != '.')
		return (0);
	if (r->copy_m[r->py][r->px] != '.')
		return (0);
	if (check_collectionable(r) == 0)
		return (0);
	return (1);
}
