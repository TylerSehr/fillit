# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsehr <tsehr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/16 10:58:25 by tsehr             #+#    #+#              #
#    Updated: 2019/09/09 04:56:17 by tsehr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = $(shell find ./srcs ! -name "._*" -regex ".*\\.[c]")

LIBDIR = ./libft
SRCDIR = ./srcs

all: $(NAME)

$(NAME):
	Make -C $(LIBDIR)
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRCS) -I $(SRCDIR) -I $(LIBDIR) -L $(LIBDIR) -lft 

clean:
	Make clean -C $(LIBDIR)
	/bin/rm -rf *.o

fclean: clean
	Make fclean -C $(LIBDIR)
	/bin/rm -rf $(NAME)

re: fclean all