/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:47:46 by rdelicad          #+#    #+#             */
/*   Updated: 2023/09/02 10:29:41 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

/* Define window size */
# define WIDTH 50
# define HEIGHT 50

/* Color definitions */
# define BOLD     "\033[1m"
# define BLACK    "\033[30;1m"
# define RED      "\033[31;1m"
# define GREEN    "\033[32;1m"
# define YELLOW   "\033[33;1m"
# define BLUE     "\033[34;1m"
# define MAGENTA  "\033[35;1m"
# define CYAN     "\033[36;1m"
# define WHITE    "\033[37;1m"
# define RESET    "\033[0m"

// leaks
void	leaks(void);

typedef struct s_read
{
	char			**map;
	char			*line;
	char			*file;
	int				fd;
	int				column;
	int				row;
	int				flag_p;
	int				flag_c;
	int				flag_e;
	char			**copy_m;
	int				px;
	int				py;
	int				cx;
	int				cy;
	int				ex;
	int				ey;
	char			obj_p;
	char			obj_e;
	char			obj_c;
	int				cont;
	mlx_t			*mlx;
	mlx_image_t		*img_floor;
	mlx_image_t		*img_walls;
	mlx_image_t		*img_player;
	mlx_image_t		*img_collectable;
	mlx_image_t		*img_exit;
	mlx_image_t		*img_background;
	mlx_image_t		*img_left_side;
	mlx_image_t		*img_right_side;
	mlx_texture_t	*texture_floor;
	mlx_texture_t	*texture_walls;
	mlx_texture_t	*texture_player;
	mlx_texture_t	*texture_collectable;
	mlx_texture_t	*texture_exit;
	mlx_texture_t	*texture_background;
	mlx_texture_t	*texture_left_side;
	mlx_texture_t	*texture_right_side;
}	t_read;

typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

/* leaks.c */
void	leaks(void);
void	printf_map(t_read *r);

/* so_long.c */
void	ft_error(int fd, char *msn);
char	*search_ext(char **av);
void	verification_av(char **av);
int		verification_args(int ac, char **av);

/* utils_struct.c */
void	init_struct(t_read *r, char **av);
void	init_read(t_read *r, char **av);
void	init_play_struct(t_read *r);

/* utils.read_map.c */
void	read_check_map(t_read *r);
void	get_arr_map(t_read *r, int len);
void	copy_map(t_read *r);

/* utils_check_map.c */
void	check_map(t_read *r);
int		rectagular_map(t_read *r);
int		surrounded_by_walls(t_read *r);
int		player_output_object(t_read *r);
int		dead_end_player(t_read *r);

/* utils_flood_fill.c */
void	position_obj(char **map, int *obj_x, int *obj_y, char obj);
void	points_obj(t_read *r);
void	flood_fill(t_read *r, t_point size, t_point init);
int		check_collectionable(t_read *r);

/* utils_main_game.c */
int32_t	main_game(t_read *r);
void	check_img(t_read *r);
void	error_img(char c);
void	clear_texture(t_read *r);
void	load_map(t_read *r);

/* utils_img.c */
void	load_images(t_read *r);
void	draw_floor_wall(t_read *r, char **map);
void	assign_img_to_map(t_read *r, char **map, int i, int j);
void	draw_player_objs(t_read *r);

/* utils_draw_big_map.c */
void	draw_big_map(t_read *r);
void	draw_background(t_read *r);
void	left_right_side_map(t_read *r);
void	load_big_images(t_read *r);
void	clear_big_texture(t_read *r);

/* utils_accion_player.c */
void	accion_player(t_read *r);
void	key_hook(mlx_key_data_t keydata, void *param);
void	move_player(t_read *r, int x, int y);
int		is_valid_position(t_read *r, int nx, int ny);
void	player_update(t_read *r);

#endif