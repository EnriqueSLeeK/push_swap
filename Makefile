# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 19:12:10 by ensebast          #+#    #+#              #
#    Updated: 2022/02/18 11:26:15 by ensebast         ###   ########.br        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
BONUS := checker

CC := clang
CFLAG := -Wextra -Werror -Wall
INCLUDE := ./include/

FILES := check_input.c check_stack.c error.c init.c main.c\
		 push.c rotate_down.c rotate_up.c sort.c swap.c find.c\
		 insert.c align.c partition.c cost.c

FILES_B := check_input_bonus.c check_stack_bonus.c error_bonus.c\
		   init_bonus.c main_bonus.c push_bonus.c rotate_down_bonus.c\
		   rotate_up_bonus.c swap_bonus.c

MISC := ft_atoi.c ft_isdigit.c ft_putchar_fd.c ft_putendl_fd.c\
		ft_split.c ft_strlen.c ft_strncmp.c ft_calloc.c ft_putstr_fd.c\
		ft_bzero.c

SRC_DIR := ./src/
SRC = $(addprefix $(SRC_DIR), $(FILES))

SRC_DIR_B := ./bonus/
SRC_B := $(addprefix $(SRC_DIR_B), $(FILES_B))

SRC_DIR_M := ./misc/
SRC_M := $(addprefix $(SRC_DIR_M), $(MISC))

all: $(NAME) $(BONUS)

$(NAME): $(SRC) $(SRC_M)
	$(CC) -I$(INCLUDE) $(CFLAG) $(SRC_M) $(SRC) $(LIBFT) -o $(NAME)

$(BONUS): $(SRC_B) $(SRC_M)
	$(CC) -I$(INCLUDE) $(CFLAG) $(SRC_M) $(SRC_B) $(LIBFT) -o $(BONUS)

clean:
	rm $(NAME)

fclean: clean
	rm $(BONUS)

re: fclean $(NAME)

.PHONY: clean fclean re all
