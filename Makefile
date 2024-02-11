##########	PROGRAM		#######################################################

NAME		=	cub3d

##########	SOURCES		#######################################################

PATH_SRCS 	=	sources/
SRCS		= 	main.c
SRCS		+= 	exit_free.c
SRCS		+= 	init_mlx.c
SRCS		+= 	input.c
SRCS		+= 	moves.c
SRCS		+= 	moves2.c
SRCS		+= 	raycasting.c
SRCS		+= 	raycasting2.c
SRCS		+= 	render.c
SRCS		+= 	render2.c
SRCS		+= 	parser.c
SRCS		+= 	parser2.c
SRCS		+= 	parser3.c
SRCS		+= 	parser4.c
SRCS		+= 	parser5.c
SRCS		+= 	parser6.c
SRCS		+= 	parser7.c 	
SRCS		+= 	parser8.c

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

CC			= 	clang
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

# $(LIBFT):
# 	make -C $(PATH_LIBFT)

# $(MLX):
# 	make -C $(PATH_MLX)

clean:
	rm -rf $(PATH_OBJS)
# make -C $(PATH_LIBFT) clean	
# make -C $(PATH_MLX) clean

fclean: clean
	rm -f $(NAME)
# make -C $(PATH_LIBFT) fclean

re: fclean all

.PHONY: all re clean fclean

# variables spéciales
# $@ fait référence au nom de la cible
# $< nom première dépendance
# $^ liste dépendance
# $? liste dépendance plus récentes que la cible
# $* nom fichier, sans son extension
# CIBLES > DEPENDANCES > REGLES