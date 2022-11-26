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

SRC_DIR		:= srcs
SRCS		:= \
			main.c \
			bin_collect/bin_coll.c \
			bin_collect/bin_list.c \
			parser/check_1_arg.c \
			parser/check_2_file.c \
			parser/check_colors.c \
			parser/check_elem.c \
			parser/check_map.c \
			parser/check_textures.c \
			parser/get_cub_base.c \
			parser/get_map_base.c \
			parser/init_base.c \
			parser/line_list.c \
			parser/utils.c \
			clean.c \
			draw_line.c \
			utils.c \

SRCS		:= $(addprefix $(SRC_DIR)/,$(SRCS))

OBJ_DIR		:= obj
OBJS		:= $(subst .c,.o,$(SRCS))
OBJS		:= $(subst $(SRC_DIR),$(OBJ_DIR),$(OBJS))


CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror -g
CPPFLAGS	:=	-I lib/libft -I includes
LDFLAGS		:=	-L lib/libft
LDLIBS		:=	-lft

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

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@
	$(info CREATED $(NAME))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

clean:
	$(MAKE) -C $(dir $(LIBFT)) clean
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
