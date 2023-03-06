# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 16:30:05 by yujelee           #+#    #+#              #
#    Updated: 2023/03/06 16:30:06 by yujelee          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_atoi.c\
				ft_atod.c\
				ft_calloc.c\
				ft_split.c\
				ft_strcmp.c\
				ft_strlcat.c\
				ft_strlcpy.c\
				ft_strlen.c\
				ft_substr.c\
				ft_strdup.c

OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

NAME		=	libft.a
RM			=	rm -f
AR			=	ar rcus
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

ifdef WITH_BONUS
	OBJ_SWITCH = $(OBJS) $(OBJS_BONUS) 
else
	OBJ_SWITCH = $(OBJS)
endif

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< 

$(NAME)		:	$(OBJ_SWITCH)
			$(AR) $@ $^

all		:	$(NAME)

clean		:
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean		:	clean
			$(RM) $(NAME)

re		:	
			make fclean 
			make all

bonus		:
			make WITH_BONUS=1 $(NAME)

.PHONY		:	all clean fclean re bonus