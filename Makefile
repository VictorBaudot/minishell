# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 08:32:05 by vbaudot           #+#    #+#              #
#    Updated: 2018/02/24 09:24:04 by vbaudot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = minishell
SRC = main.c\
		print_usage.c\
		echo.c\
		ft_list.c\
		builtins.c\
		execute.c\
		help.c\
		getenv.c\
		launch.c\
		setenv.c\
		utils_env.c\
		cd.c\
		env.c\
		ft_list_del.c\

OBJ = $(SRC:.c=.o)
DEBUG = #-g3 -fsanitize=address

CFLAGS = -Wall -Werror -Wextra
LIBFT = -L./libft -lft

YEL="\\033[33m"
BLU="\\033[34m"
RED="\\033[31m"
NC="\\033[0m"
MAG="\\033[35m"
CYA="\\033[36m"
GRE="\\033[32m"
BOL="\\033[1m"
CHE="\\xE2\\x9C\\x94"
OK="$(GRE)$(CHE)$(NC)"

all: lli $(NAME)

lli:
	@make -C libft

$(NAME): ./libft/libft.a $(OBJ)
	@printf "\n[$(NAME)] linking $(CYA)$(BOL)$(OBJ)$(NC)\n"
	@printf "to make the binary $(MAG)$(BOL)$(NAME)$(NC)"
	@gcc $(CFLAGS) $(OBJ) $(LIBFT) $(DEBUG) -o $(NAME)
	@printf '\t\t'$(OK)'\n'

%.o: %.c
	@printf "\r\033[0K[$(NAME)] compile $(BOL)$(YEL)$<$(NC)..."
	@$(CC) $(CFLAGS) -I./libft -c $<
	@printf '\t'$(OK)

clean:
	@make -C libft clean
	@printf "[$(NAME)] rm all $(BOL)$(RED) obj file$(NC)"
	@rm -rf $(OBJ)
	@printf '\t\t'$(OK)'\n'

fclean: clean
	@make -C libft fclean
	@printf "[$(NAME)] rm $(BOL)$(CYA)$(NAME)$(NC)"
	@rm -rf $(NAME)
	@printf '\t\t'$(OK)'\n'

re: fclean all

proper: all clean

.PHONY: re proper
