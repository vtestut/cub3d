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

INC_DIR		=	-I inc -I libft
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

.c.o:
	${CC} ${CFLAGS} -c$< -o ${<:.c=.o}

all:
	${MAKE} -C libft/
	@$(MAKE) -j $(NAME)

$(NAME): $(OBJ)
		${CC} ${CFLAGS} -o ${NAME} ${OBJ} ${LIBS} ${INC_DIR} -L ${MLX_DIR} -lmlx -lm -lbsd -lX11 -lXext

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		${CC} $(CFLAGS) $(INC_DIR) -I $(MLX_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean:	clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re

-include $(DPD)