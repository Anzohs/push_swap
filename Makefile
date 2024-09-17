# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 12:14:53 by hladeiro          #+#    #+#              #
#    Updated: 2024/09/12 13:03:02 by hladeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libftprintf.a
NAME = push_swap
lib = cd ft_printf && make
CP = cp ft_printf/libftprintf.a .
SRCS = main.c \ double_rrr.c \ double_rr.c \ double_ss.c \ stack_a.c \ stack_b.c
OBJS = $(SRCS:.c=.o)
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
    $(lib)
    $(CP)
    @mv $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	$(LIB) clean
fclean: clean
	$(RM) $(NAME) $(libft)
	$(LIB) fclean
