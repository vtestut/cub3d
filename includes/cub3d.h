/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:39:42 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/13 19:43:59 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <sys/stat.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define WIDTH 320 
# define HEIGHT 240
# define SIZE 64
# define SPEED 0.06
# define ROTSPEED 0.04

enum e_NSEW
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		pxl_bit;
	int		line_size;
	int		endian;
}	t_img;

typedef struct s_player
{
	char	dir;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		rotate;
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
	float	plan_x;
	float	plan_y;
}	t_player;

typedef struct s_tex
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				*floor;
	int				*ceiling;
	unsigned long	hexa_floor;
	unsigned long	hexa_ceil;
	int				size;
	int				index;
	float			step;
	float			pos;
	int				x;
	int				y;
}	t_tex;

typedef struct s_ray
{
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	int		line_h;
	int		draw_start;
	int		draw_end;
	float	camera_x;
	float	dir_x;
	float	dir_y;
	float	side_x;
	float	side_y;
	float	delta_x;
	float	delta_y;
	float	wall_dist;
	float	wall_x;
}	t_ray;

typedef struct s_game
{
	char		*path;
	char		**map;
	char		**file;
	int			fd;
	int			nb_line;
	int			map_end;
	void		*mlx;
	void		*win;
	int			win_h;
	int			win_w;
	int			**tex_arr;
	int			**tex_pxl;
	int			height;
	int			width;
	t_ray		ray;
	t_tex		tex;
	t_player	player;
}	t_game;

// main.c
void			init_mlx(t_game *game);
void			init_textures(t_game *game);
void			display_game(t_game *game);
void			catch_input(t_game *game);

// parser.c
int				is_xpm_file(char *argv);
int				check_format(char *argv);
int				is_directory(char *argv);
int				check_arg(char *argv, bool cub);
int				parser(t_game *game, char **argv);

// parser_gnl.c
int				count_lines(char *path);
void			fill_map_gnl(int row, int col, int i, t_game *game);
void			start_fill_map(char *path, t_game *game);

// parser_fill_textures.c
char			*get_texture_path(char *line, int j);
int				get_direction_textures(t_tex *tex, char *line, int j);
int				create_map(t_game *game, char **file, int i);
int				skip_spaces_fill_tex(t_game *game, char **map, int i, int j);
int				parse_file(t_game *game, char **map);

// parser_fill_textures2.c
bool			no_digit(char *str);
int				*copy_into_rgb_tab(char **rgb_tab, int *rgb);
int				check_rgb(char **rgb_tab);
int				*set_rgb_colors(char *line);
int				get_colors(t_tex *tex, char *line, int j);

// parser_fill_map.c
void			change_spaces_to_walls(t_game *game);
size_t			find_biggest_line(t_game *game, int i);
int				fill_map_tab(t_game *game, char **map_tab, int index);
int				count_map_lines(t_game *game, char **file, int i);
int				get_map_info(t_game *game, char **file, int i);

// parser_check_content.c
int				check_player_pos(t_game *game, char **map_tab);
int				check_map_char(t_game *game, char **map_tab);
int				check_walls_utils(char **map_tab, int i, int j);
int				check_walls(t_game *map, char **map_tab);
int				check_map(t_game *game, char **map_tab);

// parser_utils.c
unsigned long	rgb_to_hexa(int *rgb_tab);
int				check_textures(t_tex *tex);
int				check_map_is_eof(t_game *map);
int				check_pos_is_valid(t_game *game, char **map_tab);

// init_player.c
void			north_south(t_player *player);
void			east_west(t_player *player);
void			init_player_dir(t_game *game);
int				check_valid_rgb(int *rgb);

// display.c
void			init_pxl(t_game *game);
void			create_image(t_game *game, t_img *image, int width, int height);
void			display_window(t_game *game);
int				display_loop(t_game *game);

// display2.c
void			img_pxl_utils(t_img *image, int x, int y, int color);
void			set_img_pxl(t_game *game, t_img *image, int x, int y);
void			init_img(t_img *img);
void			create_texture(t_game *game, t_img *image, char *path);
int				*xpm_to_img(t_game *game, char *path);

// raycasting.c
void			init_ray(t_ray *ray);
void			set_raycasting(int x, t_ray *ray, t_player *player);
void			dda_setup(t_ray *ray, t_player *player);
void			do_dda_algo(t_game *game, t_ray *ray);
int				raycasting(t_player *player, t_game *game);

// raycasting2.c
void			get_texture_idx(t_game *game, t_ray *ray);
void			set_texture_pxl(t_game *game, t_tex *tex, t_ray *ray, int x);
void			find_line_height(t_ray *ray, t_game *game, t_player *player);

// moves.c
int				move_front(t_game *game);
int				move_back(t_game *game);
int				move_left(t_game *game);
int				move_right(t_game *game);
int				move_player(t_game *game);

// moves2.c
int				do_rotation(t_game *game, float rotspeed);
int				rotation(t_game *game, float rotdir);
int				check_for_collision(t_game *game, float x, float y);
int				is_valid_pos(t_game *game, float x, float y);
int				is_valid_move(t_game *game, float new_x, float new_y);

// utils.c
void			init_player(t_player *player);
void			init_data(t_tex *tex);
void			init_game(t_game *game);
int				key_press(int key, t_game *game);
int				key_release(int key, t_game *game);

// exit_free.c
void			free_textures(t_tex *tex);
int				free_game(t_game *game);
void			exit_free(t_game *game, int ret);
int				exit_mlx(t_game *game);
int				msg_error(char *str, int ret);

#endif
