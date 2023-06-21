# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/28 16:03:28 by khbouych          #+#    #+#              #
#    Updated: 2023/06/21 21:27:14 by mel-kouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell

SRC = ./main.c ./utils/util.c ./utils/util_list.c  ./lexer/lexer.c  ./lexer/tokens/token.c  ./lexer/tokens/white_space.c ./lexer/tokens/utils_space.c utils/ft_split.c ./lexer/tokens/util_token.c ./lexer/tokens/check_list.c utils/util_.c ./lexer/tokens/free.c ./lexer/tokens/check_syntax.c parsing/list_word.c
# ./parsing/parsing.c
OSRC = $(SRC:.c=.o)
CC = cc
CFLAGS =   -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OSRC)
	@$(CC) -lreadline $(CFLAGS)  $(OSRC) -o $(NAME)
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