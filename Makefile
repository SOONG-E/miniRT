.DEFAULT_GOAL = all

RM			= 	rm -rf
CFLAGS		=	-Wall -Wextra -Werror -MMD -MP 
CPPFLAGS	= 	-Imlx -Iincludes
LDFLAGS		=	-Lmlx -framework OpenGL -framework AppKit
LDLIBS 		=	-lmlx

OUTDIR		=	out/

SRCS = \
		miniRT.c		\
		get_next_line.c	\
		manage_error.c

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
	$Q$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

clean :
	$Q$(RM) $(OUTDIR)

fclean : clean
	$Q$(RM) $(NAME)
	
re : 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re