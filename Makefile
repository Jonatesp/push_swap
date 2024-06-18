# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/29 21:31:25 by anbourge          #+#    #+#              #
#    Updated: 2021/09/28 15:59:21 by anbourge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_P = push_swap
NAME_C = checker

_SRCS_C = ft_checker.c ft_checker_utils.c ft_operations.c get_next_line.c\
get_next_line_utils.c ft_create_stack.c
_SRCS_P = ft_push_swap.c ft_push_swap_utils.c ft_operations.c \
ft_sort_algorithms.c ft_algo_100.c ft_algo_100_pos_push.c ft_push_swap_utils2.c

SRCS_C_DIR = check
SRCS_C = $(addprefix $(SRCS_C_DIR)/, $(_SRCS_C))
SRCO_C = $(SRCS_C:.c=.o)

SRCS_P_DIR = srcs
SRCS_P = $(addprefix $(SRCS_P_DIR)/, $(_SRCS_P))
SRCO_P = $(SRCS_P:.c=.o)


FLAG = -Wall -Wextra -Werror -D BUFFER_SIZE=42
INC = -I includes/

all : $(NAME_C) $(NAME_P)

$(NAME_C) : $(SRCO_C)
	make -C libft
	gcc -o $(NAME_C) -Llibft -lft $(SRCO_C)

$(NAME_P) : $(SRCO_P)
	make -C libft
	gcc -o $(NAME_P) -Llibft -lft $(SRCO_P)

%.o : %.c
	gcc $(FLAG) -c $< -o $@ $(INC)

clean :
	/bin/rm -f $(SRCO_C)
	/bin/rm -f $(SRCO_P)
	make clean -C libft

fclean : clean
	/bin/rm -f $(NAME_C)
	/bin/rm -f $(NAME_P)
	/bin/rm -f libft/libft.a

re :
	make fclean
	make