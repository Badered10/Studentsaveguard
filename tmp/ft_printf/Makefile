# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 12:39:30 by baouragh          #+#    #+#              #
#    Updated: 2023/12/16 13:14:26 by baouragh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

MAKE = make -C /Users/baouragh/Desktop/ALL/ft_printf_BONUS/libft


#SRC_DIR = /Users/baouragh/Desktop/ALL/ft_printf

SRCS1 =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c\
		ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c\
		ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c\
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
		ft_putunbr_fd.c ft_uitoa.c ft_putnstr_fd.c ft_itohexa.c ft_putptr_fd.c ft_puthexa_fd.c ft_isdigit_nz.c

SRCS2 = ft_dflags.c ft_cflags.c ft_specifier.c \
		ft_printf.c ft_isflag.c ft_uflags.c\
		ft_sflags.c ft_pflags.c ft_xsflags.c
BONUS_S = ft_dflags_bonus.c ft_cflags_bonus.c ft_specifier_bonus.c \
		ft_printf_bonus.c ft_isflag_bonus.c ft_uflags_bonus.c\
 		ft_sflags_bonus.c ft_pflags_bonus.c ft_xsflags_bonus.c

OBJS1 = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)
BONUS_O = $(BONUS_S:.c=.o)
#INCLUDES = -I $(SRCS2)

CP = cp /Users/baouragh/Desktop/ALL/ft_printf/libft/libft.a /Users/baouragh/Desktop/ALL/ft_printf

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS2) $(OBJS1)
	ar -rcs $(NAME) $(OBJS2) $(OBJS1)

$(OBJS2): $(SRCS2)
	$(CC) $(CFLAGS) -c $(SRCS2) 

$(OBJS1):
	$(MAKE)
	$(CP)
	ar x libft.a
	rm -f libft.a
	
bonus: $(BONUS_O)

$(BONUS_O): $(BONUS_S) $(OBJS1)
	$(CC) $(CFLAGS) -c $(BONUS_S)
	ar -rcs $(NAME) $(OBJS2) $(OBJS1)
clean:
	$(MAKE) clean
	rm -f $(OBJS2) $(OBJS1)

fclean: clean
	$(MAKE) fclean
	rm -rf $(NAME)

re: fclean all
 
.PHONY: all clean fclean re