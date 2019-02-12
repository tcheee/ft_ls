# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcherret <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/07 12:35:44 by tcherret          #+#    #+#              #
#    Updated: 2019/02/08 18:16:11 by tcherret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

NAMELIB = ./libft/libftprintf.a

CC = @gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/ft_inspect.c\
		srcs/get_option.c\
		srcs/ft_ls.c\
		srcs/ft_ls_recur.c\
		srcs/managerror.c\
		srcs/check_error.c\
		srcs/get_padding.c\
		srcs/ft_sort.c\

INCS = push_swap.h

LIBDIR = ./libft/
INCDIR = ./includes/

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		@echo "\033[33mCompiling...\033[0m"
		@make -C $(LIBDIR)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(NAMELIB)
		@echo "\033[32m$(NAME) compiled ✔ ✔ ✔ ✔\033[0m"
		@make clean

clean :
		@rm -rf $(OBJ)
		@make -C $(LIBDIR) clean
		@echo "\033[31mObjects deleted ✕\033[0m"

fclean : clean
	@rm -f $(NAME)
	@make -C $(LIBDIR) fclean
	@echo "\033[31m$(NAME) deleted ✕\033[0m"

re : fclean all

.PHONY : all clean fclean re
