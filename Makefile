# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/28 16:03:28 by khbouych          #+#    #+#              #
#    Updated: 2023/08/25 22:51:21 by mel-kouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell

SRC = 	./minishell.c lexer/expand.c ./utils/util.c ./utils/util_list.c \
		./lexer/lexer.c  ./lexer/tokens/token.c  ./lexer/tokens/white_space.c \
		./lexer/tokens/utils_space.c utils/ft_split.c ./lexer/tokens/util_token.c \
		./lexer/tokens/check_list.c utils/util_.c utils/util__.c ./lexer/tokens/free.c ./lexer/tokens/check_syntax.c \
		./parsing/parsing.c ./parsing/util_lst_parce.c  ./builtins/ftexit.c \
		./builtins/ftecho.c  ./builtins/ftexport.c ./parsing/handle_redir.c \
		./parsing/handle_herdoc.c ./execution/main_exec.c  ./utils/util_m_exec.c  \
		./utils/export_utils.c ./utils/export_utils_.c ./execution/simple_cmd.c ./utils/cd_utils.c \
		./utils/exit_utils.c ./builtins/ftpwd.c ./builtins/ftcd.c ./builtins/ftenv.c ./builtins/ftunset.c \
		./execution/complex_cmd.c ./execution/one_pipe.c ./execution/multiple_pipe.c \
		./execution/signals.c ./utils/ft_utils___.c ./utils/simple_cmd_utils.c ./utils/expand_utils.c \
		./utils/utl_multi_p.c ./utils/herdoc_utils.c ./utils/cd_utils_.c ./utils/expand_utils_.c \
		./utils/handle_redir_utils.c ./utils/echo_utils.c ./utils/rest_function.c

LIB = -L/Users/mel-kouc/.brew/opt/readline/lib
INCLUDE = -I/Users/mel-kouc/.brew/opt/readline/include

# LIB = -L/Users/khbouych/.brew/opt/readline/lib
# INCLUDE = -I/Users/khbouych/.brew/opt/readline/include

OSRC = $(SRC:.c=.o)
CC = cc
C_flagS =   -Wall -Wextra -Werror

all: $(NAME)
$(NAME) : $(OSRC)
	@$(CC) -lreadline  $(C_flagS) $(OSRC)  ${LIB} -o $(NAME)
	@echo "*** {Compaling Mandatory ...} ***"

%.o: %.c ./incld/minishell.h ./incld/builtins.h ./incld/execution.h ./incld/lexer.h ./incld/parsing.h ./incld/token.h
	@$(CC) $(C_flagS) -c $< -o $@ ${INCLUDE}
	@echo "*** {Compaling Files ...} ***"

clean :
	@rm -rf $(OSRC)
	@echo "*** {remove objects files ...} ***"
fclean : clean
	@rm -rf $(NAME)
	@echo "*** {remove executable files and clean all files...} ***"

re : fclean all