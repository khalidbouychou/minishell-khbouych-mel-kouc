# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 11:34:21 by mel-kouc          #+#    #+#              #
#    Updated: 2023/05/28 16:01:04 by khbouych         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = ./main.c ./utils/util.c ./utils/util_list.c  ./lexer/lexer.c ./parsing/parsing.c ./tokens/token.c

OSRC = $(SRC:.c=.o)
CC = cc
CFLAGS =   -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OSRC)
	@$(CC) -lreadline $(CFLAGS) $(OSRC) -o $(NAME)
	@echo "*** {Compaling Mandatory ...} ***"

%.o: %.c ../incld/minishell.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "*** {Compaling Files ...} ***"

clean :
	@rm -rf $(OSRC)
	@echo "*** {remove objects files ...} ***"
fclean : clean
	@rm -rf $(NAME)
	@echo "*** {remove executable files and clean all files...} ***"

re : fclean all