/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:00:26 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/19 18:50:55 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <stdint.h>

# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

# define PLAYER_SPEED 0.07
# define ROTATION_SPEED 0.23

# define TEXTURE_WIDTH 256
# define TEXTURE_HEIGHT 256

typedef enum e_bg_color{
	CLR_TOP,
	CLR_BOT,
}	t_bg_color;

typedef enum e_txt_side{
	TXT_NORTH,
	TXT_SOUTH,
	TXT_WEST,
	TXT_EAST
}	t_txt_side;

typedef struct s_map_data
{
	char			*north_txt;
	char			*south_txt;
	char			*east_txt;
	char			*west_txt;
	unsigned char	floor_color[3];
	unsigned char	ceil_color[3];
	int				pos_player_x;
	int				pos_player_y;
	int				map_max_x;
	int				map_max_y;
	int				map_index;
	char			**map;
}	t_map_data;

typedef struct s_parse
{
	int	valid_north;
	int	valid_south;
	int	valid_east;
	int	valid_west;
	int	valid_floor;
	int	valid_ceil;
}	t_parse;

typedef struct s_vector_d
{
	double	x;
	double	y;
}	t_vector_d;

typedef struct s_vector_i
{
	int	x;
	int	y;
}	t_vector_i;

typedef struct s_player
{
	t_vector_d	pos;
	t_vector_d	dir;
	t_vector_d	plane;
}	t_player;

typedef struct s_matrix
{
	double	a;
	double	b;
	double	c;
	double	d;
}	t_matrix;

typedef struct s_texture_draw
{
	double		wall_x;
	double		step;
	t_vector_i	texture_coord;
	double		texture_pos;
}	t_texture_draw;

typedef struct s_raycast
{
	t_vector_d	ray_dir;
	t_vector_d	delta_dist;
	t_vector_d	side_dist;
	t_vector_i	map_pos;
	t_vector_i	step;
	double		wall_dist;
	bool		wall_hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
}	t_raycast;

typedef struct s_game
{
	t_player	player;
	t_map_data	data;
	// mlx_t		*mlx;
	// mlx_image_t	*img;
	uint32_t	textures_pxls[4][TEXTURE_HEIGHT][TEXTURE_WIDTH];
	uint32_t	bg_colors[2];	
}	t_game;


/*****************************************************************************/
/*							FUNCTIONS										 */
/*****************************************************************************/

//free
void	ft_free_texture(t_map_data *data);
void	ft_free_arr(void **array);
int		ft_strlen(const char *s);

//01 pars
void	map_parsing(int argc, char **argv, t_game *game);
void	ft_init_data(t_map_data *data); // ! ALERT static ?
//static void ft_init_parse(t_parse *parse); //! ALERT static ?
// static char	get_init_player_dir(char **map); // ! ALERT static ?
// static void	initial_player_direction(char dir, t_vector_d *player_dir, t_vector_d *player_plane); // ! ALERT static ?

//02 pars arg
int 	ft_check_arg(int argc, char **argv);
int		ft_check_format(char *argv);

//03 pars map 1
int		ft_start(int argc, char **argv, t_map_data *data, t_parse *parse);
int		ft_check_file(char **argv, t_map_data *data, t_parse *parse);
char	*ft_get_file(char *arg);
void	ft_fill_map(t_map_data *data, char *file_data);

//04 pars map 2
int		ft_check_file_data(t_map_data *data, char *file_data, t_parse *parse);
int		ft_fill_data(t_map_data *data, char *file_data, int i, t_parse *parse);
int		ft_fill_first_data(t_map_data *data, char *file_data, int i, t_parse *parse);
int		ft_check_if_full(t_parse *parse);

//05 pars map 3
int		ft_manage_north(t_map_data *data, char *file_data, int i, t_parse *parse);
int		ft_manage_north_loop(t_map_data *data, char *file_data, int i, int len);
int		ft_manage_south(t_map_data *data, char *file_data, int i, t_parse *parse);
int		ft_manage_south_loop(t_map_data *data, char *file_data, int i, int len);

//06 pars map 4
int		ft_manage_east(t_map_data *data, char *file_data, int i, t_parse *parse);
int		ft_manage_east_loop(t_map_data *data, char *file_data, int i, int len);
int		ft_manage_west(t_map_data *data, char *file_data, int i, t_parse *parse);
int		ft_manage_west_loop(t_map_data *data, char *file_data, int i, int len);

//07 pars map 5
int		ft_manage_floor(t_map_data *data, char *file_data, int i, t_parse *parse);
int		ft_check_id_nb(char *file_data, int i);
int		ft_get_rgb_value_floor(t_map_data *data, char *file, int i, t_parse *parse);
int		ft_manage_ceiling(t_map_data *data, char *file_data, int i, t_parse *parse);
int		ft_get_rgb_value_ceil(t_map_data *data, char *file, int i, t_parse *parse);

//08 pars map 6
int		ft_check_map(t_map_data *data, char *file_data);
int		ft_check_map_loop(char *file_data, int i);
int		ft_check_valid_char(char *file_data, int i);
int		ft_check_map_border(char *file_data, t_map_data *data);
int		ft_check_map_border_bis(char *file, int max_w, int max_l, t_map_data *data);

//09 pars map 7
char	**ft_add_border(int width, int len, char **map);
char	**ft_fill_middle(char *file, char **map, t_map_data *data);
int		ft_check_each_char_map(char **map);

#endif
