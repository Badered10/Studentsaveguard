# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 17:33:58 by baouragh          #+#    #+#              #
#    Updated: 2023/11/16 17:55:19 by baouragh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c\
		ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c\
		ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c\
		 ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c 
		 
#ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c

SRC_B = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
		ft_lstclear_bonus.c
OBJS = $(SRCS:.c=.o)
BONUS = $(SRC_B:.c=.o)
NAME = libft.a

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

$(BONUS): 
	$(CC) $(CFLAGS) -c $(SRC_B)
	ar -rc $(NAME) $(BONUS)
	
bonus: all $(BONUS)

all: $(NAME)


clean:
	@echo "$(PROCESS)remove objects files ...$(RESET)"
	@rm -f $(OBJS)
	@rm -f $(BONUS)
	@sleep 1
	@echo "$(SUCCSSES)objects files removed$(RESET)"

fclean: clean
	@echo "$(PROCESS)remove libft.a ...$(RESET)"
	@rm -rf $(NAME)
	@sleep 1
	@echo "$(SUCCSSES)libft.a is removed$(RESET)"

re: fclean all
	@echo "$(PROCESS)rebuild ...$(RESET)"
	@sleep 1
	@echo "$(SUCCSSES)rebuild is Done!$(RESET)"

.PHONY: all re fclean clean

SUCCSSES = \033[1;32m
PROCESS = \033[1;33m
RESET = \033[0m