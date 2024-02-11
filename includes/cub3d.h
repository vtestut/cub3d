/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:47:42 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/11 17:12:43 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// # include "libft.h"
# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define WIN_WIDTH 960 
# define WIN_HEIGHT 720

# define TEX_SIZE 64

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

# define MOVESPEED 0.0600
# define ROTSPEED 0.060

enum e_texture_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

typedef unsigned long	t_ulong;

/* ---------------------------------------------------------------------------*
							STRUCTURES
 --------------------------------------------------------------------------- */

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_data
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				*floor;
	int				*ceiling;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				size;
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
}	t_data;

typedef struct s_ray
{
	double	camera_x;
	// tout mettre en float??
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		rotate;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	int			fd;
	int			n_line;
	char		*path;
	char		**file;
	int			height;
	int			width;
	int			index_end_of_map;
	char		**map;
	int			**texture_pixels;
	int			**textures;
	t_ray		ray;
	t_data		data;
	t_player	player;
}	t_game;

/* ---------------------------------------------------------------------------*
							FUNCTIONS
 --------------------------------------------------------------------------- */

// main.c
void			init_mlx(t_game *game);
void			init_textures(t_game *game);
void			render_images(t_game *game);
void			listen_for_input(t_game *game);

// parsing_01.c
int				check_arg(char *arg, bool cub); // cub sert a quoi??
void			init_player(t_player *player);
void			init_data(t_data *textures);
void			init_game(t_game *game);
int				parser(t_game *game, char **argv);

// parsing_02.c
int				count_lines(char *path);
void			start_parse(char *path, t_game *game);
bool			is_xpm_file(char *arg); // sert a quoi ?
bool			check_format(char *argv);
bool			check_if_directory(char *arg);

// parsing_03.c
char			*get_texture_path(char *line, int j);
int				fill_direction_textures(t_data *textures, char *line, int j);
int				skip_spaces(t_game *game, char **map, int i, int j);
int				parse_file(t_game *game, char **map);
void			fill_map(int row, int col, int i, t_game *game);

// parsing_04.c
int				create_map(t_game *game, char **file, int i);
bool			no_digit(char *str);
int				*copy_into_rgb_array(char **rgb_to_convert, int *rgb);
int				*set_rgb_colors(char *line);
int				fill_color_textures(t_data *textures, char *line, int j);

// parsing_05.c
void			change_space_into_wall(t_game *game);
size_t			find_biggest_len(t_game *game, int i);
int				fill_map_tab(t_game *game, char **map_tab, int index);
int				count_map_lines(t_game *game, char **file, int i);
int				get_map_info(t_game *game, char **file, int i);

// parsing_06.c
int				check_player_position(t_game *game, char **map_tab);
int				check_map_elements(t_game *game, char **map_tab);
int				check_top_or_bottom(char **map_tab, int i, int j);
int				check_map_sides(t_game *map, char **map_tab);
int				check_map_validity(t_game *game, char **map_tab);

// parsing_07.c
unsigned long	convert_rgb_to_hex(int *rgb_tab);
int				check_textures_validity(t_data *textures);
int				check_map_is_at_the_end(t_game *map);
int				is_a_white_space(char c);
int				check_position_is_valid(t_game *game, char **map_tab);

// parsing_08.c
void			init_player_north_south(t_player *player);
void			init_player_east_west(t_player *player);
void			init_player_direction(t_game *game);
int				check_valid_rgb(int *rgb);

// my_init_mlx.c
void			init_img_clean(t_img *img);
void			init_texture_img(t_game *game, t_img *image, char *path);
int				*xpm_to_img(t_game *game, char *path);

// ! my_render_01.c
void			init_texture_pixels(t_game *game);
void			init_img(t_game *game, t_img *image, int width, int height);
void			render_frame(t_game *game);
int				render(t_game *game);

// my_render_02.c
void			set_image_pixel(t_img *image, int x, int y, int color);
void			set_frame_image_pixel(t_game *game, t_img *image, int x, int y);

// my_raycasting_01.c
void			init_ray(t_ray *ray);
void			init_raycasting_info(int x, t_ray *ray, t_player *player);
void			set_dda(t_ray *ray, t_player *player);
void			perform_dda(t_game *game, t_ray *ray);
int				raycasting(t_player *player, t_game *game);

// my_raycasting_02.c
void			get_texture_index(t_game *game, t_ray *ray);
void			update_texture_pixels(t_game *game, t_data *tex, t_ray *ray, int x);
void			calculate_line_height(t_ray *ray, t_game *game, t_player *player);

// my_input_01.c
int				key_press_handler(int key, t_game *game);
int				key_release_handler(int key, t_game *game);

// my_moves_01.c
int				move_player_forward(t_game *game);
int				move_player_backward(t_game *game);
int				move_player_left(t_game *game);
int				move_player_right(t_game *game);
int				move_player(t_game *game);

// my_moves_02.c
int				rotate_left_right(t_game *game, double rotspeed);
int				rotate_player(t_game *game, double rotdir);
bool			is_valid_pos_wall_collision(t_game *game, double x, double y);
bool			is_valid_pos(t_game *game, double x, double y);
int				validate_move(t_game *game, double new_x, double new_y);

// ! my_exit_free.c
void			free_tab(void **tab);
void			free_data(t_data *textures);
void			free_map(t_game *game);
int				free_game(t_game *game);
void			exit_free(t_game *game, int ret);
int				quit_cub3d(t_game *game);
int				err_msg(char *str, int ret);

#endif
