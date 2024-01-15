##########	PROGRAM		#######################################################

NAME = libft.a

##########	SOURCES		#######################################################

SRCS_LIBFT	:=	./sources/ft_ctype/ft_isalpha.c\
				./sources/ft_ctype/ft_isdigit.c\
				./sources/ft_ctype/ft_isalphanum.c\
				./sources/ft_ctype/ft_isspace.c\
				./sources/ft_list/ft_lstat.c\
				./sources/ft_list/ft_lstdup.c\
				./sources/ft_list/ft_lstaddback.c\
				./sources/ft_list/ft_lstaddfront.c\
				./sources/ft_list/ft_lstclear.c\
				./sources/ft_list/ft_lstnew.c\
				./sources/ft_list/ft_lstsize.c\
				./sources/ft_list/ft_lstindex.c\
				./sources/ft_list/ft_lstiteri.c\
				./sources/ft_list/ft_lstappend.c\
				./sources/ft_list/ft_lstlast.c\
				./sources/ft_math/ft_min.c\
				./sources/ft_math/ft_digitat.c\
				./sources/ft_math/ft_getdigits.c\
				./sources/ft_math/ft_absi.c\
				./sources/ft_math/ft_powi.c\
				./sources/ft_stdlib/ft_calloc.c\
				./sources/ft_stdlib/ft_realloc.c\
				./sources/ft_stdlib/ft_atoi_long.c\
				./sources/ft_stdlib/ft_strtoi.c\
				./sources/ft_stdlib/ft_atoi.c\
				./sources/ft_stdlib/ft_strtol.c\
				./sources/ft_string/ft_strcat.c\
				./sources/ft_string/ft_strtrim_one.c\
				./sources/ft_string/ft_strinsert.c\
				./sources/ft_string/ft_strremoven.c\
				./sources/ft_string/ft_memcpy.c\
				./sources/ft_string/ft_strncpy.c\
				./sources/ft_string/ft_memelemset.c\
				./sources/ft_string/ft_strtrim.c\
				./sources/ft_string/ft_memmove.c\
				./sources/ft_string/ft_strcmp.c\
				./sources/ft_string/ft_strremove.c\
				./sources/ft_string/ft_countc.c\
				./sources/ft_string/ft_strcpy.c\
				./sources/ft_string/ft_strlen.c\
				./sources/ft_string/ft_strreplace.c\
				./sources/ft_string/ft_bzero.c\
				./sources/ft_string/ft_memset.c\
				./sources/ft_string/ft_substr.c\
				./sources/ft_string/ft_strchr.c\
				./sources/ft_string/ft_itoa.c\
				./sources/ft_string/ft_strjoin.c\
				./sources/ft_string/ft_strreplacen.c\
				./sources/ft_string/rotate.c\
				./sources/ft_string/ft_strinsertn.c\
				./sources/ft_string/ft_strchr1.c\
				./sources/ft_string/ft_memdup.c\
				./sources/ft_string/ft_strdup.c\
				./sources/ft_string/ft_strlcpy.c\
				./sources/ft_string/ft_putstrfd.c\
				./sources/ft_string/ft_split.c\
				./sources/ft_string/ft_splitcs.c\
				./sources/ft_string/ft_toupper.c

SRCS_PRINTF :=	./sources/ft_printf/ft_printf.c\
				./sources/ft_printf/ft_putadress.c\
				./sources/ft_printf/ft_putchar.c\
				./sources/ft_printf/ft_puthexa_lower.c\
				./sources/ft_printf/ft_puthexa_upper.c\
				./sources/ft_printf/ft_putnbr.c\
				./sources/ft_printf/ft_putstr.c\
				./sources/ft_printf/ft_putunbr.c

SRCS_GNL	:=	./sources/ft_gnl/get_next_line.c\
				./sources/ft_gnl/get_next_line_utils.c

SRCS_ALL 	:= ${SRCS_LIBFT} ${SRCS_PRINTF} ${SRCS_GNL}

##########	PARAMS		#######################################################

CC      	:= 	cc
CFLAGS  	:= 	-Wall\
				-Werror\
				-Wextra\
				-I\
				./

OBJ_DIR		:=	objects
SRC_DIR		:=	sources
INC_DIR		:=	includes

OBJ = $(addprefix $(OBJ_DIR)/,$(SRCS_ALL:.c=.o))
DPD = $(addprefix $(OBJ_DIR)/,$(SRCS_ALL:.c=.d))

##########	RULES		#######################################################

