# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 12:01:11 by atarchou          #+#    #+#              #
#    Updated: 2022/04/20 00:52:12 by atarchou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
FLAGS = -Wall -Werror -Wextra -pthread
SRCS = philo.c\
		philo_utils.c\
		philo_routine.c\
		philo_init.c\

$(NAME) : $(SRCS)
			$(CC) $(FLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

clean :
		rm -rf $(NAME)

fclean :
		rm -rf philo

re : fclean all

.PHONY : all clean fclean re