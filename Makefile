NAME		:= cub3D

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#
# LIBFT		libft
#
# INCS		include directories
#
# SRC_DIR	source directory
# SRCS		source files
#
# OBJ_DIR	build directory
# OBJS		object files
#
# CC		compiler
# CFLAGS	compiler flags
# CPPFLAGS	preprocessor flags
# LDFLAGS	linker flags
# LDLIBS	library names

SRC_DIR		:= srcs
SRCS		:= \
			main.c \
			clean.c \
			parse_1.c \
			utils.c \

SRCS		:= $(addprefix $(SRC_DIR)/,$(SRCS))

OBJ_DIR		:= objs
OBJS		:= $(subst .c,.o,$(SRCS))
OBJS		:= $(subst $(SRC_DIR),$(OBJ_DIR),$(OBJS))

# SRCS	=	so_long \
			# sl_checks_map1.c \
			# sl_checks_map2.c \
			# sl_clean.c \
			# sl_draw_map.c \
			# sl_init.c \
			# sl_player_moves.c \
			# sl_utils.c \

# SRCDIR	=	srcs

# OBJDIR	=	objs

# SOURCES	:= 	${addprefix ${SRCDIR}/, ${SRCS}}
# OBJS	:=	${SOURCES:${SRCDIR}/%.c=${OBJDIR}/%.o}

LIBFT		:=	lib/libft/libft.a
# MLX			:=	lib/mlx/libmlx_Linux.a
# MLX		=	mlx/libmlx.a
# LFT		=	libft/libft.a

CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror #-g
CPPFLAGS	:=	-I lib/libft -I includes
LDFLAGS		:=	-L lib/libft
LDLIBS		:=	-lft
# CPPFLAGS	:=	-I lib/libft -I lib/mlx -I includes
# LDFLAGS		:=	-L lib/libft -L lib/mlx
# LDLIBS		:=	-lft -lmlx -lXext -lX11 -lm
# CC		=	cc
# CFLAGS	=	-Wall -Wextra -Werror -g
# INC		=	-I./includes -I./libft -I./mlx
# LIB		=	-L./libft -lft -L./mlx -lmlx -lXext -lX11 -lm

#------------------------------------------------#
#   UTENSILS                                     #
#------------------------------------------------#
# RM		cleaning command

RM			:= rm -rf
MAKE		:= $(MAKE) --silent --jobs --no-print-directory
DIR_DUP		= mkdir -p $(@D)


#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#
# all		default goal
# %.o		compilation .c -> .o
# $(NAME)	link .o -> archive
# clean		remove .o
# fclean	remove .o + binary
# re		remake default goal
# run		run the program
# info		print the default goal recipe

all:		$(NAME)

$(LIBFT):
			$(MAKE) -C $(dir $(LIBFT))
			@echo " [ OK ] | Libft ready!"
# ${LFT}:
# 			@echo " [ .. ] | Compiling libft.."
# 			@make -s -C libft
# 			@echo " [ OK ] | Libft ready!"

# $(MLX):
# 			$(MAKE) -C $(dir $(MLX))
# 			@echo " [ OK ] | Minilibx ready!"
# ${MLX}:
# 			@echo " [ .. ] | Compiling minilibx.."
# 			@make -s -C mlx
# 			@echo " [ OK ] | Minilibx ready!"

# $(NAME): 	$(OBJS) $(LIBFT) $(MLX)
$(NAME): 	$(OBJS) $(LIBFT)
			$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@
			$(info CREATED $(NAME))
# ${NAME}:	${MLX} ${LFT} ${OBJS}
# 			@echo "Object files created."
# 			@${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${LIB}
# 			@echo "So_long ready!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
			$(DIR_DUP)
			$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
			$(info CREATED $@)
# ${OBJDIR}/%.o: ${SRCDIR}/%.c
# 			@[ ! -d ${OBJDIR} ] && mkdir -p ${OBJDIR} || true
# 			@$(CC) $(CFLAGS) -c ${INC} $< -o $@

clean:
			$(MAKE) -C $(dir $(LIBFT)) clean
			$(RM) $(OBJ_DIR)
			@echo "REMOVED object files"
# clean:
# 			$(MAKE) $@ -C lib/libft
# 			@${RM} -r ${OBJ_DIR}
# 			@echo "Object files removed."			
# clean:
# 			@make -s $@ -C libft
# 			@make clean -s -C mlx
# 			@${RM} ${OBJS}
# 			@${RM} ${OBJDIR}
# 			@make clean -s -C mlx
# 			@echo "Object files removed."

# fclean: 	clean
# 			$(MAKE) -C $(dir $(LIBFT)) fclean
# 			$(RM) $(NAME)
fclean:		clean
			@${RM} lib/libft/libft.a
			@${RM} ${NAME}
			@echo "REMOVED binary files"

# re:
# 			$(MAKE) fclean
# 			$(MAKE) all
re:			fclean all

#------------------------------------------------#
#   SPEC                                         #
#------------------------------------------------#

.PHONY: 	all clean fclean re
.SILENT:
