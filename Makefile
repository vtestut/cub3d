##########	PROGRAM		#######################################################

NAME		=	cub3d

##########	SOURCES		#######################################################

PATH_SRCS	=	sources/
PATH_SRCS	+=	sources/parsing/
PATH_SRCS	+=	sources/raycasting/
PATH_SRCS	+=	sources/utils/

SRCS		=	main.c
SRCS		+=	

vpath %.c $(PATH_SRCS)

##########	OBJECTS		#######################################################

PATH_OBJS	=	objects
OBJS		=	$(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
DPD = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.d))

##########	INCLUDES	#######################################################

INC_DIR		=	-I includes -I libft
INCLUDES	=	includes
HEADER		=	${INCLUDES}/cub3d.h

##########	MLX			#######################################################

MLX_DIR		=	minilibx-linux
MLX			=	libmlx.a

##########	LIBFT		#######################################################

LIBFTPATH	=	-L libft -lft
LIBS		=	${INCLUDE} ${LIBFTPATH}

##########	COMPILATION	#######################################################

CFLAGS		=	-Wall
CFLAGS		+=	-Wextra 
CFLAGS		+=	-Werror 
CFLAGS		+=	-g #-fsanitize=address

CC			=	clang
AR			=	ar rcs

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
