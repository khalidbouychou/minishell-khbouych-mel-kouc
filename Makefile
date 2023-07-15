# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/28 16:03:28 by khbouych          #+#    #+#              #
#    Updated: 2023/07/13 22:24:56 by khbouych         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell

SRC = 	./main.c lexer/expand.c ./utils/util.c ./utils/util_list.c \
		./lexer/lexer.c  ./lexer/tokens/token.c  ./lexer/tokens/white_space.c \
		./lexer/tokens/utils_space.c utils/ft_split.c ./lexer/tokens/util_token.c \
		./lexer/tokens/check_list.c utils/util_.c utils/util__.c ./lexer/tokens/free.c ./lexer/tokens/check_syntax.c \
		./parsing/parsing.c ./parsing/list_word.c

OSRC = $(SRC:.c=.o)
CC = cc  -g
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