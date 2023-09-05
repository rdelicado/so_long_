/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:47:46 by rdelicad          #+#    #+#             */
/*   Updated: 2023/09/04 20:54:56 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
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
	mlx_image_t		*img_pr;
	mlx_image_t		*img_pl;
	mlx_image_t		*img_pd;
	mlx_image_t		*img_pu;
	mlx_image_t		*img_mon1;
	mlx_image_t		*img_death;
	mlx_image_t		*img_close0;
	mlx_image_t		*img_open3;
	mlx_image_t		*img_floor;
	mlx_image_t		*img_walls;
	mlx_image_t		*img_player;
	mlx_image_t		*img_collectable;
	mlx_image_t		*img_exit;
	mlx_image_t		*img_background;
	mlx_image_t		*img_left_side;
	mlx_image_t		*img_right_side;
	mlx_texture_t	*tex_pr;
	mlx_texture_t	*tex_pl;
	mlx_texture_t	*tex_pd;
	mlx_texture_t	*tex_pu;
	mlx_texture_t	*tex_mon1;
	mlx_texture_t	*tex_death;
	mlx_texture_t	*tex_close0;
	mlx_texture_t	*tex_open3;
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

/* so_long_bonus.c */
void	ft_error(int fd, char *msn);
char	*search_ext(char **av);
void	verification_av(char **av);
int		verification_args(int ac, char **av);

/* struct_bonus.c */
void	init_struct(t_read *r, char **av);
void	init_read(t_read *r, char **av);
void	init_play_struct(t_read *r);

/* read_map_bonus.c */
void	read_check_map(t_read *r);
void	get_arr_map(t_read *r, int len);
void	copy_map(t_read *r);

/* check_map_bonus.c */
void	check_map(t_read *r);
int		rectagular_map(t_read *r);
int		surrounded_by_walls(t_read *r);
int		player_output_object(t_read *r);
int		dead_end_player(t_read *r);

/* flood_fill_bonus.c */
void	position_obj(char **map, int *obj_x, int *obj_y, char obj);
void	points_obj(t_read *r);
void	flood_fill(t_read *r, t_point size, t_point init);
int		check_collectionable(t_read *r);

/* main_game_bonus.c */
int32_t	main_game(t_read *r);
void	check_img(t_read *r);
void	error_img(char c);
void	clear_texture(t_read *r);
void	load_map(t_read *r);

/* img_bonus.c */
void	load_images(t_read *r);
void	draw_floor_wall(t_read *r, char **map);
void	assign_img_to_map(t_read *r, char **map, int i, int j);
void	draw_player_objs(t_read *r);
void	error_img1(char c);

/* img_accion_bonus.c */
void	load_img_player(t_read *r);
void	load_img_door(t_read *r);
void	clear_tex_player(t_read *r);
void	clear_tex_door(t_read *r);

/* accion_player_bonus.c */
void	accion_player(t_read *r);
void	key_hook(mlx_key_data_t keydata, void *param);
void	move_player(t_read *r, int x, int y, mlx_image_t *img);
int		is_valid_position(t_read *r, int nx, int ny);
void	player_update(t_read *r, mlx_image_t *img);

/* moves_game_bonus.c */
void	print_move_game(t_read *r);

#endif