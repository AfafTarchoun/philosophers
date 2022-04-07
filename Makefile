# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 12:01:11 by atarchou          #+#    #+#              #
#    Updated: 2022/04/07 20:44:56 by atarchou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers
CC = gcc
FLAGS = -Wall -Werror -Wextra
SRCS = philo.c\
		philo_utils.c\
		philo_routine.c\

$(NAME) : $(SRCS)
			$(CC) $(FLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

clean :
		rm -rf $(NAME)

fclean :
		rm -rf philosophers

re : fclean all

.PHONY : all clean fclean re