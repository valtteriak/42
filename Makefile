# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkinnune <vkinnune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/26 13:48:02 by tpinola           #+#    #+#              #
#    Updated: 2021/07/28 20:01:28 by vkinnune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRCS = ft_strlen.c ft_putstr.c ft_putnbr.c ft_putchar.c ft_memcpy.c magic_box.c main.c
FLAGS = -Wall -Wextra -Werror -I. -o 
OBJ = *.o

.PHONY: all
all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(NAME) $(SRCS)

.PHONY: clean
clean:
	@rm	-f	$(OBJ)

.PHONY: fclean
fclean: clean
	@rm	-f	$(NAME)
	
.PHONY: re
re: fclean all