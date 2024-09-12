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

NAME = push_swap
LIB = cd 42_libft && make 
libft = libft.a
CP = cp 42_libft/libft.a .
SRCS = main.c \ functions.c \ stack_fun.c
OBJS = $(SRCS:.c=.o)
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)
$(NAME): $(OBJS)
	$(CP)
	$(CC) $(CFLAGS) $(OBJS) $(libft) -o $(NAME)

clean:
	$(RM) $(OBJS)
	$(LIB) clean
fclean: clean
	$(RM) $(NAME) $(libft)
	$(LIB) fclean
