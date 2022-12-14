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

LIBFT		:=	lib/libft/libft.a

MLX			:= lib/mlx/libmlx.a

SRC_DIR		:= srcs
SRCS		:= \
			main.c \
			clean/bin_coll.c \
			clean/bin_list.c \
			clean/clean.c \
			clean/clean_free_tabs.c \
			clean/clean_msg.c \
			draw/draw_colored_elem.c \
			draw/draw_line.c \
			parser/check_1_arg.c \
			parser/check_2_file.c \
			parser/check_elem.c \
			parser/check_map.c \
			parser/check_map_2.c \
			parser/init_base.c \
			parser/line_list.c \
			parser/update_base_1.c \
			parser/update_base_2_elem.c \
			parser/update_base_3_map.c \
			parser/update_base_game.c \
			rays/cast_rays.c \
			utils/utils.c \
			utils/utils_2.c \
			utils/utils_3.c \
			utils/utils_atoi_cub.c \
			utils/utils_itoa_cub.c \
			gen_3d_projection.c \
			init.c \
			init_2.c \
			render_map.c \
			render_player.c \

SRCS		:= $(addprefix $(SRC_DIR)/,$(SRCS))

OBJ_DIR		:= obj
OBJS		:= $(subst .c,.o,$(SRCS))
OBJS		:= $(subst $(SRC_DIR),$(OBJ_DIR),$(OBJS))


CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror -g3
CPPFLAGS	:=	-I lib/libft -I includes -I lib/mlx
LDFLAGS		:=	-L lib/libft
LDLIBS		:=	-lft -lXext -lX11 -lm -lz

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

$(MLX):
	$(MAKE) -C $(dir $(MLX))

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@
	$(info CREATED $(NAME))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

clean:
	$(MAKE) -C $(dir $(LIBFT)) clean
	$(MAKE) -C $(dir $(MLX)) clean
	$(RM) -r $(OBJ_DIR)
	@echo "REMOVED object files"

fclean: clean
	$(MAKE) -C $(dir $(LIBFT)) fclean
	$(RM) $(NAME)
	@echo "Cleaning done!"

re:
	$(MAKE) fclean
	$(MAKE) all

#------------------------------------------------#
#   SPEC                                         #
#------------------------------------------------#

.PHONY: 	all clean fclean re
.SILENT:

# # **************************************************

# NAME		:= cub3D

# #------------------------------------------------#
# #   INGREDIENTS                                  #
# #------------------------------------------------#
# # LIBFT		libft
# #
# # INCS		include directories
# #
# # SRC_DIR	source directory
# # SRCS		source files
# #
# # OBJ_DIR	build directory
# # OBJS		object files
# #
# # CC		compiler
# # CFLAGS	compiler flags
# # CPPFLAGS	preprocessor flags
# # LDFLAGS	linker flags
# # LDLIBS	library names

# LIBFT		:=	lib/libft/libft.a

# MLX			:= lib/mlx/libmlx.a

# SRC_DIR		:= srcs
# SRCS		:= \
# 			main.c \
# 			clean.c \
# 			init.c \
# 			draw_line.c \
# 			parse_1.c \
# 			parse_2.c \
# 			utils.c \

# SRCS		:= $(addprefix $(SRC_DIR)/,$(SRCS))

# OBJ_DIR		:= obj
# OBJS		:= $(subst .c,.o,$(SRCS))
# OBJS		:= $(subst $(SRC_DIR),$(OBJ_DIR),$(OBJS))


# CC			:=	cc
# CFLAGS		:=	-Wall -Wextra -Werror -g
# CPPFLAGS	:=	-I lib/libft -I includes -I lib/mlx
# LDFLAGS		:=	-L lib/libft
# LDLIBS		:=	-lft -lXext -lX11 -lm -lz

# #------------------------------------------------#
# #   UTENSILS                                     #
# #------------------------------------------------#
# # RM		cleaning command

# RM			:= rm -rf
# MAKE		:= $(MAKE) --silent --jobs --no-print-directory
# DIR_DUP		= mkdir -p $(@D)


# #------------------------------------------------#
# #   RECIPES                                      #
# #------------------------------------------------#
# # all		default goal
# # %.o		compilation .c -> .o
# # $(NAME)	link .o -> archive
# # clean		remove .o
# # fclean	remove .o + binary
# # re		remake default goal
# # run		run the program
# # info		print the default goal recipe

# all:		$(NAME)

# $(LIBFT):
# 	$(MAKE) -C $(dir $(LIBFT))

# $(MLX):
# 	$(MAKE) -C $(dir $(MLX))

# $(NAME): $(OBJS) $(LIBFT) $(MLX)
# 	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@
# 	$(info CREATED $(NAME))

# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
# 	$(DIR_DUP)
# 	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
# 	$(info CREATED $@)

# clean:
# 	$(MAKE) -C $(dir $(LIBFT)) clean
# 	$(MAKE) -C $(dir $(MLX)) clean
# 	$(RM) -r $(OBJ_DIR)
# 	@echo "REMOVED object files"

# fclean: clean
# 	$(MAKE) -C $(dir $(LIBFT)) fclean
# 	$(RM) $(NAME)
# 	@echo "Cleaning done!"

# re:
# 	$(MAKE) fclean
# 	$(MAKE) all

# #------------------------------------------------#
# #   SPEC                                         #
# #------------------------------------------------#

# .PHONY: 	all clean fclean re
# .SILENT:
