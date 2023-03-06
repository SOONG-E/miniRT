.DEFAULT_GOAL = all

RM			= 	rm -rf
CFLAGS		=	-Wall -Wextra -Werror -MMD -MP -g3
CPPFLAGS	= 	-Imlx -Iinclude
LDFLAGS		=	-Lmlx -framework OpenGL -framework AppKit -L src/util/libft -lft
LDLIBS 		=	-lmlx

OUTDIR		=	out/

SRCS = \
		src/miniRT.c						\
		src/util/get_next_line.c			\
		src/util/ft_count_array.c			\
		src/manage/manage_error.c       	\
		src/manage/manage_resource.c		\
		src/manage/manage_keyhook.c			\
		src/manage/manage_mlx.c				\
		src/parse/parse_line.c              \
		src/parse/parse_uppercase_type.c	\
		src/parse/parse_lowercase_type.c    \
		src/parse/parse_utils.c				\
		src/parse/parse_put_info.c			\
		src/vec/calculate_basic_vec.c		\
		src/vec/calculate_vec.c				\
		src/vec/calculate_util.c			\
		src/vec/init_attr.c					\
		src/vec/rotate_vec.c				\
		src/draw/ray_trace.c				\
		src/draw/ray_trace_util.c			\
		src/draw/check_is_hit.c				\
		src/draw/check_hit_cylinder.c		\
		src/draw/draw_light.c				\
		src/draw/draw_shadow.c				\

Q = @
ifdef DEBUG
	Q = 
endif

NAME = miniRT

OBJS		=	$(addprefix $(OUTDIR),$(SRCS:%.c=%.o))
DEPS		=	$(addprefix $(OUTDIR),$(SRCS:%.c=%.d))
-include $(DEPS)

$(OUTDIR)%.o : %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

all : $(NAME)

$(NAME) : $(OBJS)
	@make re -C src/util/libft
	$Q$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

clean :
	@make -C src/util/libft clean
	$Q$(RM) $(OUTDIR)

fclean : clean
	@make -C src/util/libft fclean
	$Q$(RM) $(NAME)
	
re : 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re