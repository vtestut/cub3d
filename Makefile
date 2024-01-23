##########	PROGRAM		#######################################################

NAME		=	cub3d

##########	SOURCES		#######################################################

PATH_SRCS	=	sources/
PATH_SRCS	+=	sources/parsing/
PATH_SRCS	+=	sources/raycasting/
PATH_SRCS	+=	sources/utils/

SRCS		=	main.c
SRCS		+=	01.pars_init.c
SRCS		+=	02.pars_arg.c
SRCS		+=	03.pars_map_start.c
SRCS		+=	04.pars_map_fill_data.c
SRCS		+=	05.pars_north_south.c
SRCS		+=	06.pars_east_west.c
SRCS		+=	07.pars_ceiling_floor.c
SRCS		+=	08.pars_map_check.c
SRCS		+=	09.pars_map_fill_utils.c
SRCS		+=	free.c


vpath %.c $(PATH_SRCS)

##########	OBJECTS		#######################################################

PATH_OBJS	=	objects
OBJS		=	$(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

##########	INCLUDES	#######################################################

INC_DIR		=	-I includes -I libft 

##########	MLX			#######################################################

MLX_DIR		=	minilibx-linux

##########	LIBFT		#######################################################

LIBFTPATH	=	-L libft -lft
LIBS		=	${INCLUDE} ${LIBFTPATH}

##########	COMPILATION	#######################################################

CFLAGS		=	-Wall
CFLAGS		+=	-Wextra 
CFLAGS		+=	-Werror 
CFLAGS		+=	-g #-fsanitize=address

CC			=	clang

##########	RULES		#######################################################

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o $@ $^ ${LIBS} -L ${MLX_DIR} -lmlx -lm -lbsd -lX11 -lXext

$(PATH_OBJS)/%.o: %.c
	@mkdir -p $(@D)
	${CC} ${CFLAGS} ${INC_DIR} -c -o $@ $<

clean:
	rm -rf $(PATH_OBJS)

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re

# variables spéciales
# $@ fait référence au nom de la cible
# $< nom première dépendance
# $^ liste dépendance
# $? liste dépendance plus récentes que la cible
# $* nom fichier, sans son extension
# CIBLES > DEPENDANCES > REGLES