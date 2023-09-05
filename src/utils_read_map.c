/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_read_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:55:29 by rdelicad          #+#    #+#             */
/*   Updated: 2023/08/31 14:02:36 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	read_check_map(t_read *r)
{
	int		len;

	r->fd = open(r->file, O_RDONLY);
	if (r->fd <= 0)
	{
		ft_error(2, "Failure to open file map");
		exit(1);
	}
	r->line = get_next_line(r->fd);
	len = 0;
	while (r->line != NULL)
	{
		++len;
		free(r->line);
		r->line = get_next_line(r->fd);
	}
	close(r->fd);
	get_arr_map(r, len);
}

void	get_arr_map(t_read *r, int len)
{
	r->map = malloc(sizeof(int *) * (len + 1));
	if (!r->map)
	{
		ft_error(2, "Failure to create array map");
		free(r->map);
		exit(1);
	}
	r->fd = open(r->file, O_RDONLY);
	r->line = get_next_line(r->fd);
	len = 0;
	while (r->line != NULL)
	{
		r->line[ft_strcspn(r->line, "\n")] = '\0';
		r->map[len] = ft_strdup(r->line);
		free(r->line);
		r->line = get_next_line(r->fd);
		len++;
	}
	r->map[len] = NULL;
	close(r->fd);
}

void	copy_map(t_read *r)
{
	int	i;

	r->copy_m = malloc(sizeof(char *) * (r->row + 1));
	if (!r->copy_m)
	{
		free(r->copy_m);
		ft_error(2, "Failure create array copy map");
	}
	i = 0;
	while (r->map[i])
	{
		r->copy_m[i] = ft_strdup(r->map[i]);
		if (!r->copy_m[i])
			ft_error(2, "Failure copy map elements");
		i++;
	}
	r->copy_m[i] = NULL;
}
