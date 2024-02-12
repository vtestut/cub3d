##########	PROGRAM		#######################################################

NAME		=	cub3d

##########	SOURCES		#######################################################

PATH_SRCS 	=	sources/
SRCS		= 	main.c
SRCS		+= 	display.c
SRCS		+= 	display2.c
SRCS		+= 	exit_free.c
SRCS		+= 	init_player.c
SRCS		+= 	moves.c
SRCS		+= 	moves2.c
SRCS		+= 	parser_check_content.c
SRCS		+= 	parser_fill_map.c
SRCS		+= 	parser_fill_textures.c
SRCS		+= 	parser_fill_textures2.c 	
SRCS		+= 	parser_gnl.c
SRCS		+= 	parser_utils.c
SRCS		+= 	parser.c
SRCS		+= 	raycasting.c
SRCS		+= 	raycasting2.c
SRCS		+= 	utils.c

vpath %.c $(PATH_SRCS)	

##########	OBJECTS		#######################################################

PATH_OBJS	=	objects/
OBJS		=	$(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

##########	INCLUDES	#######################################################

INCLUDES	=	-I ./includes/
INCLUDES	+=	-I ./libft/includes/
INCLUDES	+=	-I ./minilibx-linux/

PATH_LIBFT	=	libft/
LIBFT		=	libft/libft.a

PATH_MLX	=	minilibx-linux/
MLX			=	minilibx-linux/libmlx.a

##########	COMPILATION	#######################################################

CC			= 	cc
CFLAGS		=	-Wall
CFLAGS		+=	-Wextra
CFLAGS		+=	-Werror
# CFLAGS		+=	-g
# CFLAGS		+=	-fsanitize=address

##########	RULES		#######################################################

all: $(PATH_OBJS) $(MLX) $(LIBFT) $(NAME)
	@echo "\nCUB3D EST COMPILE !\n"

$(PATH_OBJS):		
	mkdir -p $(PATH_OBJS)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c		
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INCLUDES) $(LIBFT) $(MLX) -lXext -lX11 -lm

$(LIBFT):
	make -C $(PATH_LIBFT)

$(MLX):
	make -C $(PATH_MLX)

clean:
	rm -rf $(PATH_OBJS)
	make -C $(PATH_LIBFT) clean	
	make -C $(PATH_MLX) clean

fclean: clean
	rm -f $(NAME)
	make -C $(PATH_LIBFT) fclean

re: fclean all

.PHONY: all re clean fclean

# variables spéciales
# $@ fait référence au nom de la cible
# $< nom première dépendance
# $^ liste dépendance
# $? liste dépendance plus récentes que la cible
# $* nom fichier, sans son extension
# CIBLES > DEPENDANCES > REGLES