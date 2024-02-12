##########	PROGRAM		#######################################################

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

SRCS_CONV	=	ft_atoi_long.c
SRCS_CONV	+=	ft_atoi.c
SRCS_CONV	+=	ft_itoa.c
SRCS_CONV	+=	ft_strtoi.c
SRCS_CONV	+=	ft_strtol.c
SRCS_CONV	+=	ft_atoi_maxint.c

SRCS_CTYP	=	ft_isalnum.c
SRCS_CTYP	+=	ft_isalpha.c
SRCS_CTYP	+=	ft_isalphastr.c
SRCS_CTYP	+=	ft_isascii.c
SRCS_CTYP	+=	ft_isdigit.c
SRCS_CTYP	+=	ft_isdigitstr.c
SRCS_CTYP	+=	ft_isprint.c
SRCS_CTYP	+=	ft_isspace.c

SRCS_PRINTF	=	ft_printf.c
SRCS_PRINTF	+=	ft_putadress.c
SRCS_PRINTF	+=	ft_putchar.c
SRCS_PRINTF	+=	ft_puthexa_lower.c
SRCS_PRINTF	+=	ft_puthexa_upper.c
SRCS_PRINTF	+=	ft_putnbr.c
SRCS_PRINTF	+=	ft_putstr.c
SRCS_PRINTF	+=	ft_putunbr.c

SRCS_GNL	=	get_next_line.c
SRCS_GNL	+=	get_next_line_utils.c

SRCS_LST	=	ft_lstaddback.c
SRCS_LST	+=	ft_lstaddfront.c
SRCS_LST	+=	ft_lstappend.c
SRCS_LST	+=	ft_lstat.c
SRCS_LST	+=	ft_lstclear.c
SRCS_LST	+=	ft_lstdup.c
SRCS_LST	+=	ft_lstindex.c
SRCS_LST	+=	ft_lstiteri.c
SRCS_LST	+=	ft_lstlast.c
SRCS_LST	+=	ft_lstnew.c
SRCS_LST	+=	ft_lstsize.c

SRCS_MATH	=	ft_absi.c
SRCS_MATH	+=	ft_digitat.c
SRCS_MATH	+=	ft_getdigits.c
SRCS_MATH	+=	ft_max.c
SRCS_MATH	+=	ft_min.c
SRCS_MATH	+=	ft_powi.c

SRCS_MEMO	=	ft_bzero.c
SRCS_MEMO	+=	ft_calloc.c
SRCS_MEMO	+=	ft_memchr.c
SRCS_MEMO	+=	ft_memcmp.c
SRCS_MEMO	+=	ft_memcpy.c
SRCS_MEMO	+=	ft_memdup.c
SRCS_MEMO	+=	ft_memelemset.c
SRCS_MEMO	+=	ft_memmove.c
SRCS_MEMO	+=	ft_memset.c
SRCS_MEMO	+=	ft_realloc.c
SRCS_MEMO	+=	ft_free_tab.c

SRCS_OUTP	=	ft_putchar_fd.c
SRCS_OUTP	+=	ft_putendl_fd.c
SRCS_OUTP	+=	ft_putnbr_fd.c
SRCS_OUTP	+=	ft_putstr_fd.c

SRCS_STR	=	ft_countc.c
SRCS_STR	+=	ft_countcs.c
SRCS_STR	+=	ft_intlen.c
SRCS_STR	+=	ft_longlen.c
SRCS_STR	+=	ft_putlong.c
SRCS_STR	+=	ft_rotate.c
SRCS_STR	+=	ft_split.c
SRCS_STR	+=	ft_splitcs.c
SRCS_STR	+=	ft_strcat.c
SRCS_STR	+=	ft_strchr.c
SRCS_STR	+=	ft_strchr1.c
SRCS_STR	+=	ft_strcmp.c
SRCS_STR	+=	ft_strcpy.c
SRCS_STR	+=	ft_strdup.c
SRCS_STR	+=	ft_strinsert.c
SRCS_STR	+=	ft_strinsertn.c
SRCS_STR	+=	ft_striteri.c
SRCS_STR	+=	ft_strjoin.c
SRCS_STR	+=	ft_strlcat.c
SRCS_STR	+=	ft_strlcpy.c
SRCS_STR	+=	ft_strlen.c
SRCS_STR	+=	ft_strmapi.c
SRCS_STR	+=	ft_strncmp.c
SRCS_STR	+=	ft_strncpy.c
SRCS_STR	+=	ft_strndup.c
SRCS_STR	+=	ft_strnlen.c
SRCS_STR	+=	ft_strnstr.c
SRCS_STR	+=	ft_strrchr.c
SRCS_STR	+=	ft_strremove.c
SRCS_STR	+=	ft_strremoven.c
SRCS_STR	+=	ft_strreplace.c
SRCS_STR	+=	ft_strreplacen.c
SRCS_STR	+=	ft_strtrim_one.c
SRCS_STR	+=	ft_strtrim.c
SRCS_STR	+=	ft_substr.c
SRCS_STR	+=	ft_tolower.c
SRCS_STR	+=	ft_toupper.c

SRCS = ${SRCS_CONV} ${SRCS_CTYP} ${SRCS_LST} ${SRCS_MATH} ${SRCS_MEMO} ${SRCS_OUTP} ${SRCS_GNL} ${SRCS_PRINTF} ${SRCS_STR}

vpath %.c $(PATH_SRCS)

##########	OBJECTS		#######################################################

PATH_OBJS	=	objects
OBJS		=	$(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

##########	INCLUDES	#######################################################

INCLUDES	=	includes
HEADER		=	$(INCLUDES)/libft.h\
				$(INCLUDES)/ft_convert.h\
				$(INCLUDES)/ft_ctype.h\
				$(INCLUDES)/ft_list_type.h\
				$(INCLUDES)/ft_list.h\
				$(INCLUDES)/ft_math.h\
				$(INCLUDES)/ft_memory.h\
				$(INCLUDES)/ft_output.h\
				$(INCLUDES)/ft_printf.h\
				$(INCLUDES)/ft_string.h\
				$(INCLUDES)/get_next_line.h

##########	COMPILATION	#######################################################

CFLAGS 		=	-Wall
CFLAGS 		+=	-Wextra
CFLAGS 		+=	-Werror

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