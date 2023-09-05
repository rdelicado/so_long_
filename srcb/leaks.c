/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:20:35 by rdelicad          #+#    #+#             */
/*   Updated: 2023/09/02 10:48:20 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	leaks(void)
{
	system("leaks -q so_long");
}

void	printf_map(t_read *r)
{
	int	i;

	ft_printf(YELLOW"\nOriginal\n"RESET);
	i = 0;
	while (r->map[i] != NULL)
	{
		ft_printf("%s\n", r->map[i]);
		i++;
	}
	ft_printf(YELLOW"\nCopia\n"RESET);
	i = 0;
	while (r->copy_m[i] != NULL)
	{
		ft_printf("%s\n", r->copy_m[i]);
		i++;
	}
}
