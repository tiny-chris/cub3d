NAME	= libft.a

SRCS =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_bzero.c ft_is_in_set.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_strlen.c ft_strlen_spechar.c ft_strlcpy.c ft_strlcat.c \
		ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c \
		ft_toupper.c ft_tolower.c ft_atoi.c ft_itoa.c \
		ft_calloc.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
		ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_free_tabstr.c ft_lines_tabstr.c \
		get_next_line.c \

SRCS_B	=	ft_lstnew.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_front.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c \
			ft_lstiter.c ft_lstmap.c \

OBJS	= ${SRCS:.c=.o}

OBJS_B	= ${SRCS_B:.c=.o}

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -rf

.c.o:
			${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

all: 		${NAME}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}

bonus:		${OBJS} ${OBJS_B}
			${AR} ${NAME} ${OBJS} ${OBJS_B}

clean: 
			${RM} ${OBJS} ${OBJS_B}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re bonus
