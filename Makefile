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

LIBFT = cp ft_printf/libftprintf.a .
lib = cd ft_printf && make
liib = libftprintf.a

SRCS = main.c  double_rrr.c  double_rr.c double_ss.c \
		stack_a.c stack_b.c ft_init.c ft_sort.c

OBJS = $(SRCS:.c=.o)

CP = cp
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
NAME = push_swap

all:
	$(lib)
	$(LIBFT)
	@make start

start: $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(liib) -o $(NAME)

clean:
	$(RM) $(OBJS)
	$(lib) clean
fclean: clean
	$(RM) $(NAME) $(liib)
	$(lib) fclean

re: fclean all
