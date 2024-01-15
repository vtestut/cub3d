##########	PROGRAM		##########

NAME = cub3d

##########	SOURCES		##########

SRC =	main.c

##########	PARAMS		##########

CC = clang
CFLAGS = -Wall 
CFLAGS += -Wextra
CFLAGS += -Werror 
CFLAGS += -g #-fsanitize=address

OBJ_DIR = obj
SRC_DIR = src
INC_DIR = -I inc -I libft

MLX_DIR = minilibx-linux
MLX = libmlx.a 

LIBFTPATH = -L libft -lft
LIBS = ${INCLUDE} ${LIBFTPATH}

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
DPD = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.d))

##########	RULES		##########

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
