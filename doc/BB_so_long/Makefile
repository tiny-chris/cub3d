NAME	=	so_long
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf
MLX		=	mlx/libmlx.a
LFT		=	libft/libft.a
INC		=	-I./includes -I./libft -I./mlx
LIB		=	-L./libft -lft -L./mlx -lmlx -lXext -lX11 -lm

SRCS	=	so_long.c \
			sl_checks_map1.c \
			sl_checks_map2.c \
			sl_clean.c \
			sl_draw_map.c \
			sl_init.c \
			sl_player_moves.c \
			sl_utils.c \

SRCDIR	=	srcs

OBJDIR	=	objs

SOURCES	:= 	${addprefix ${SRCDIR}/, ${SRCS}}
OBJS	:=	${SOURCES:${SRCDIR}/%.c=${OBJDIR}/%.o}

all:		${NAME}

${NAME}:	${MLX} ${LFT} ${OBJS}
			@echo "Object files created."
			@${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${LIB}
			@echo "So_long ready!"
	
${OBJDIR}/%.o: ${SRCDIR}/%.c
			@[ ! -d ${OBJDIR} ] && mkdir -p ${OBJDIR} || true
			@$(CC) $(CFLAGS) -c ${INC} $< -o $@

${MLX}:
			@echo " [ .. ] | Compiling minilibx.."
			@make -s -C mlx
			@echo " [ OK ] | Minilibx ready!"

${LFT}:		
			@echo " [ .. ] | Compiling libft.."
			@make -s -C libft
			@echo " [ OK ] | Libft ready!"

clean:		
			@make -s $@ -C libft
			@make clean -s -C mlx
			@${RM} ${OBJS}
			@${RM} ${OBJDIR}
			@make clean -s -C mlx
			@echo "Object files removed."

fclean:		clean
			@${RM} libft/libft.a
			@${RM} mlx/libmlx.a
			@${RM} ${NAME}
			@echo "Binary files removed."

re:			fclean all

.PHONY: 	all clean fclean re