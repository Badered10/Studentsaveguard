# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 12:39:30 by baouragh          #+#    #+#              #
#    Updated: 2023/12/14 10:42:53 by baouragh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

MAKE = make -C /Users/baouragh/Desktop/ALL/ft_printf/libft

SRC_DIR = /Users/baouragh/Desktop/ALL/ft_printf

SRCS = $(SRC_DIR)/ft_dflags.c $(SRC_DIR)/ft_cflags.c $(SRC_DIR)/ft_specifier.c \
		$(SRC_DIR)/ft_printf.c $(SRC_DIR)/ft_isflag.c $(SRC_DIR)/ft_uflags.c\
		$(SRC_DIR)/ft_sflags.c $(SRC_DIR)/ft_pflags.c $(SRC_DIR)/ft_xsflags.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I $(SRCS) -I /Users/baouragh/Desktop/ALL/ft_printf/libft/libft.a

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS) /Users/baouragh/Desktop/ALL/ft_printf/libft/libft.a

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