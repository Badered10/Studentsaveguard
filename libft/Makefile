# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 17:33:58 by baouragh          #+#    #+#              #
#    Updated: 2023/11/23 18:27:46 by baouragh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c\
		ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c\
		ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c\
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRC_B = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
		
OBJS = $(SRCS:.c=.o)
BONUS = $(SRC_B:.c=.o)
NAME = libft.a

all: $(NAME) 

$(NAME): $(OBJS)
	@echo "$(PROCESS)Create libft.a ...$(RESET)"
	@ar -rc $(NAME) $(OBJS)
	@sleep 1
	@echo "$(SUCCSSES)libft.a is created!$(RESET)"

$(OBJS): $(SRCS)
	@echo "$(PROCESS)Create part (1 & 2) object files ...$(RESET)"
	@$(CC) $(CFLAGS) -c $(SRCS)
	@sleep 1
	@echo "$(SUCCSSES)Object files is created!$(RESET)"
	

$(BONUS): $(SRC_B)
	@echo "$(PROCESS)Create (bonus part) object files ...$(RESET)"
	@$(CC) $(CFLAGS) -c $(SRC_B)
	@sleep 1
	@echo "$(SUCCSSES)Object files is created!$(RESET)"
	@echo "$(PROCESS)Create  libft.a ...$(RESET)"
	@ar -rc $(NAME) $(BONUS)
	@sleep 1
	@echo "$(SUCCSSES)libft.a is created!$(RESET)"
	
bonus: $(BONUS)



clean:
	@echo "$(PROCESS)Remove all object files ...$(RESET)"
	@rm -f $(OBJS) $(BONUS)
	@sleep 1
	@echo "$(SUCCSSES)Object files removed$(RESET)"

fclean: clean
	@echo "$(PROCESS)Remove libft.a ...$(RESET)"
	@rm -rf $(NAME)
	@sleep 1
	@echo "$(SUCCSSES)libft.a is removed$(RESET)"

re: fclean all
	@echo "$(SUCCSSES)Rebuild is done!$(RESET)"

.PHONY: all re clean fclean bonus

SUCCSSES = \033[1;32m
PROCESS = \033[1;33m
RESET = \033[0m