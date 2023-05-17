# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 15:00:46 by jsarabia          #+#    #+#              #
#    Updated: 2023/05/12 15:12:22 by jsarabia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc

LIBFT = libft
PRINTF = ft_printf

GREEN = \033[0;92m
RED = \033[0;91m
WHITE = \033[0;37m

LIBFTOUT = libft/libft.a
PRINTFOUT = ft_printf/libftprintf.a

OBJS = pipex.o free_elements.o create_arrays.o execution.o

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): compile_libft compile_printf $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTOUT) $(PRINTFOUT) -o $(NAME)
	@echo "$(GREEN)Pipex successfully compiled$(WHITE)"

compile_libft:
	@make bonus -C libft/

compile_printf:
	@make all -C ft_printf/

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C libft/
	@make clean -C ft_printf/
	@/bin/rm -f *.o

fclean: clean
	@make fclean -C libft/
	@make fclean -C ft_printf/
	@rm -rf pipex

re: fclean all

.PHONY: clean fclean re
