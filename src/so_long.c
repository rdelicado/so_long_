/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:04:19 by rdelicad          #+#    #+#             */
/*   Updated: 2023/09/04 20:41:00 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error(int fd, char *msn)
{
	const char	*error;
	const char	*reset;

	error = RED "Error: " RESET CYAN;
	reset = RESET "\n";
	write (fd, error, ft_strlen(error));
	write (fd, msn, ft_strlen(msn));
	write (fd, reset, ft_strlen(reset));
}

char	*search_ext(char **av)
{
	char	*str;
	int		i;

	str = av[1];
	i = 0;
	while (str[i] != 0)
		i++;
	return (&str[i - 4]);
}

void	verification_av(char **av)
{
	char	*str;
	char	*ext;

	ext = ".ber";
	str = search_ext(av);
	if (ft_strlen(*(av + 1)) >= 5)
	{
		if (ft_strncmp(str, ext, 4))
			ft_error(2, "Invalid extension");
	}
	else
		ft_error(2, "Invalid file name");
}

int	verification_args(int ac, char **av)
{
	if (ac < 2)
		ft_error(2, "No arguments!!");
	else if (ac > 2)
	{
		ft_error(2, "Too many arguemnts!!");
		return (0);
	}
	else
	{
		verification_av(av);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_read	r;

	if (!(verification_args(ac, av)))
		return (0);
	init_struct(&r, av);
	read_check_map(&r);
	check_map(&r);
	main_game(&r);
	ft_matfree(r.map);
	ft_matfree(r.copy_m);
	return (0);
}
