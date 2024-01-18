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

# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"

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
	int valid_north;
	int valid_south;
	int valid_east;
	int valid_west;
	int valid_floor;
	int valid_ceil;
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

typedef struct s_game
{
	t_player	player;
	t_map_data	data;
	//mlx_t		*mlx;
	//mlx_image_t	*img;
	//uint32_t	textures_pxls[4][TEXTURE_HEIGHT][TEXTURE_WIDTH];
	//uint32_t	bg_colors[2];	
}	t_game;




#endif
