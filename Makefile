# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/28 16:03:28 by khbouych          #+#    #+#              #
#    Updated: 2023/07/30 13:44:06 by mel-kouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell

SRC = 	./main.c lexer/expand.c ./utils/util.c ./utils/util_list.c \
		./lexer/lexer.c  ./lexer/tokens/token.c  ./lexer/tokens/white_space.c \
		./lexer/tokens/utils_space.c utils/ft_split.c ./lexer/tokens/util_token.c \
		./lexer/tokens/check_list.c utils/util_.c utils/util__.c ./lexer/tokens/free.c ./lexer/tokens/check_syntax.c \
		./parsing/parsing.c ./parsing/util_lst_parce.c  ./builtins/ftexit.c \
		./builtins/ftecho.c  ./builtins/ftexport.c ./parsing/handle_redir.c \
		./parsing/handle_herdoc.c ./execution/main_exec.c  ./execution/util_m_exec.c  \
	   	./utils/export_utils.c ./utils/export_utils_.c ./execution/simple_cmd.c \
		./utils/exit_utils.c ./builtins/ftpwd.c ./builtins/ftcd.c ./builtins/ftenv.c ./builtins/ftunset.c 
		

OSRC = $(SRC:.c=.o)
CC = cc  -g
CFLAGS =   -Wall -Wextra -Werror 
#-fsanitize=address

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