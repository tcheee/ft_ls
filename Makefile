# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcherret <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/07 12:35:44 by tcherret          #+#    #+#              #
#    Updated: 2019/02/22 12:09:06 by tcherret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

NAMELIB = ./libft/libftprintf.a

CC = @gcc

CFLAGS =-Wall -Wextra -Werror

SRCS = srcs/ft_inspect.c\
		srcs/get_option.c\
		srcs/ft_ls.c\
		srcs/ft_ls_recur.c\
		srcs/managerror.c\
		srcs/check_error.c\
		srcs/check_error_param.c\
		srcs/get_padding.c\
		srcs/ft_sort.c\
		srcs/ft_reverse_sort.c\
		srcs/ft_time_sort.c\
		srcs/ft_time_sort_param.c\
		srcs/display_list.c\
		srcs/get_num_elem.c\
		srcs/create_list.c\
		srcs/inspect_get_mode.c\
		srcs/inspect_get_time.c\
		srcs/ft_rtime_sort_param.c\
		srcs/ft_rtime_sort.c\
		srcs/get_new_name.c\

INCS = push_swap.h

LIBDIR = ./libft/
INCDIR = ./includes/

OBJ = $(addprefix objs/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)

$(NAME) : $(OBJ)
		@echo "\033[33mCompiling...\033[0m"
		@make -C $(LIBDIR)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(NAMELIB)
		@echo "\033[32m$(NAME) compiled ✔ ✔ ✔ ✔\033[0m"

objs/%.o : srcs/%.c
	@mkdir -p $(@D)
	@$(CC) -c $(CFLAGS) $< -I./includes -o $@

clean :
		@rm -rf $(OBJ) objs
		@make -C $(LIBDIR) clean
		@echo "\033[31mObjects deleted ✕\033[0m"

fclean : clean
	@rm -f $(NAME)
	@make -C $(LIBDIR) fclean
	@echo "\033[31m$(NAME) deleted ✕\033[0m"

re : fclean all

.PHONY : all clean fclean re
