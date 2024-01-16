##########	TARGET		#######################################################

NAME 		=	libft.a

##########	SOURCES		#######################################################

PATH_SRCS	=	sources/
PATH_SRCS	+=	sources/ctype/
PATH_SRCS	+=	sources/list/
PATH_SRCS	+=	sources/math/
PATH_SRCS 	+=	sources/memory/
PATH_SRCS 	+=	sources/output/
PATH_SRCS 	+=	sources/convert/
PATH_SRCS 	+=	sources/strings/
PATH_SRCS 	+=	sources/ft_printf/
PATH_SRCS 	+=	sources/get_next_line/

SRCS		=	ft_isalpha.c
SRCS		+=	ft_isalphastr.c
SRCS		+=	ft_isdigit.c
SRCS		+=	ft_isdigitstr.c
SRCS		+=	ft_isspace.c
SRCS		+=	ft_lstat.c
SRCS		+=	ft_lstdup.c
SRCS		+=	ft_lstaddback.c
SRCS		+=	ft_lstaddfront.c
SRCS		+=	ft_lstclear.c
SRCS		+=	ft_lstnew.c
SRCS		+=	ft_lstsize.c
SRCS		+=	ft_lstindex.c
SRCS		+=	ft_lstiteri.c
SRCS		+=	ft_lstappend.c
SRCS		+=	ft_lstlast.c
SRCS		+=	ft_max.c
SRCS		+=	ft_min.c
SRCS		+=	ft_digitat.c
SRCS		+=	ft_getdigits.c
SRCS		+=	ft_absi.c
SRCS		+=	ft_powi.c
SRCS		+=	ft_calloc.c
SRCS		+=	ft_realloc.c
SRCS		+=	ft_atoi_long.c
SRCS		+=	ft_strtoi.c
SRCS		+=	ft_atoi.c
SRCS		+=	ft_strtol.c
SRCS		+=	ft_strcat.c
SRCS		+=	ft_strtrim_one.c
SRCS		+=	ft_strinsert.c
SRCS		+=	ft_strremoven.c
SRCS		+=	ft_memcpy.c
SRCS		+=	ft_strncpy.c
SRCS		+=	ft_memelemset.c
SRCS		+=	ft_strtrim.c
SRCS		+=	ft_memmove.c
SRCS		+=	ft_strcmp.c
SRCS		+=	ft_strndup.c
SRCS		+=	ft_strremove.c
SRCS		+=	ft_countc.c
SRCS		+=	ft_countcs.c
SRCS		+=	ft_strcpy.c
SRCS		+=	ft_strlen.c
SRCS		+=	ft_strnlen.c
SRCS		+=	ft_strreplace.c
SRCS		+=	ft_bzero.c
SRCS		+=	ft_memset.c
SRCS		+=	ft_substr.c
SRCS		+=	ft_strchr.c
SRCS		+=	ft_itoa.c
SRCS		+=	ft_strjoin.c
SRCS		+=	ft_strreplacen.c
SRCS		+=	ft_rotate.c
SRCS		+=	ft_strinsertn.c
SRCS		+=	ft_strchr1.c
SRCS		+=	ft_memdup.c
SRCS		+=	ft_strdup.c
SRCS		+=	ft_strlcpy.c
SRCS		+=	ft_putstrfd.c
SRCS		+=	ft_split.c
SRCS		+=	ft_splitcs.c
SRCS		+=	ft_toupper.c
SRCS		+=	ft_printf.c
SRCS		+=	ft_putadress.c
SRCS		+=	ft_putchar.c
SRCS		+=	ft_puthexa_lower.c
SRCS		+=	ft_puthexa_upper.c
SRCS		+=	ft_putnbr.c
SRCS		+=	ft_putstr.c
SRCS		+=	ft_putunbr.c
SRCS		+=	get_next_line.c
SRCS		+=	get_next_line_utils.c

vpath %.c $(PATH_SRCS)

##########	OBJECTS		#######################################################

PATH_OBJS	=	objects
OBJS		=	$(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

##########	INCLUDES	#######################################################

INCLUDES	=	includes
HEADER		=	$(INCLUDES)/libft.h\
				$(INCLUDES)/ft_ctype.h\
				$(INCLUDES)/ft_list_type.h\
				$(INCLUDES)/ft_list.h\
				$(INCLUDES)/ft_math.h\
				$(INCLUDES)/ft_printf.h\
				$(INCLUDES)/ft_convert.h\
				$(INCLUDES)/ft_string.h\
				$(INCLUDES)/ft_memory.h\
				$(INCLUDES)/get_next_line.h

##########	COMPILATION	#######################################################

CFLAGS 		=	-Wall -Wextra -Werror 
CC			=	cc
AR			=	ar rcs

##########	RULES		#######################################################

all:  			$(NAME)
				@echo "\nLA LIBFT EST COMPILEE !\n"

$(NAME): 		$(OBJS)
				$(AR) $@ $^

$(OBJS): 		$(PATH_OBJS)/%.o: %.c $(HEADER)
				@mkdir -p $(PATH_OBJS)
				$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

clean:
	 			$(RM) -R $(PATH_OBJS)

fclean: 		clean
				rm -rf $(NAME)	

re: 			fclean all

# variables spéciales
# $@ fait référence au nom de la cible
# $< nom première dépendance
# $^ liste dépendance
# $? liste dépendance plus récentes que la cible
# $* nom fichier, sans son extension
# CIBLES > DEPENDANCES > REGLES