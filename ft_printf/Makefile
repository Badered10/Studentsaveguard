# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 12:39:30 by baouragh          #+#    #+#              #
#    Updated: 2023/12/11 18:09:41 by baouragh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

MAKE = make -C /Users/baouragh/Desktop/ALL/ft_printf/libft

SRC_DIR = /Users/baouragh/Desktop/ALL/ft_printf

SRCS = $(SRC_DIR)/ft_dflag.c $(SRC_DIR)/ft_flags.c $(SRC_DIR)/ft_printf.c $(SRC_DIR)/ft_specifier.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

INCLUDES = -I $(SRCS)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(MAKE)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCS)

clean:
	$(MAKE) clean
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean
	rm -rf $(NAME)

re: fclean all
 
.PHONY: all clean fclean re