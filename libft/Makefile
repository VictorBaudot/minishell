# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 10:33:26 by vbaudot           #+#    #+#              #
#    Updated: 2017/12/28 10:10:52 by vbaudot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Werror -Wextra
NAME=libft.a
NAME_P=$(shell echo $(NAME) | tr ' ' '\n' | sed "s/\.[acoh]$///g" | tr '\n' ' ' | sed "s/ $///g")
SRC=\
ft_abs.c str/ft_atoi.c str/ft_bzero.c is/ft_isalnum.c is/ft_isalpha.c\
is/ft_isascii.c is/ft_isdigit.c is/ft_islower.c is/ft_isprint.c is/ft_isupper.c\
str/ft_itoa.c lst/ft_lstadd.c lst/ft_lstdel.c lst/ft_lstdelone.c\
lst/ft_lstiter.c lst/ft_lstmap.c lst/ft_lstnew.c mem/ft_memalloc.c\
mem/ft_memccpy.c mem/ft_memchr.c mem/ft_memcmp.c mem/ft_memcpy.c\
mem/ft_memdel.c mem/ft_memmove.c mem/ft_memset.c put/ft_putchar.c\
put/ft_putchar_fd.c put/ft_putendl.c put/ft_putendl_fd.c put/ft_putnbr.c\
put/ft_putnbr_fd.c put/ft_putstr.c put/ft_putstr_fd.c str/ft_strcat.c\
str/ft_strchr.c str/ft_strclr.c str/ft_strcmp.c lst/ft_lstprint.c\
lst/ft_lstappend.c str/ft_strcpy.c str/ft_strdel.c str/ft_strdup.c\
str/ft_strequ.c str/ft_striter.c str/ft_striteri.c str/ft_strjoin.c\
str/ft_strlcat.c str/ft_strlen.c str/ft_strmap.c str/ft_strmapi.c\
str/ft_strncat.c str/ft_strncmp.c str/ft_strncpy.c str/ft_strnequ.c\
str/ft_strnew.c str/ft_strnstr.c str/ft_strrchr.c str/ft_strsplit.c\
str/ft_strstr.c str/ft_strsub.c str/ft_strtrim.c str/ft_tolower.c\
str/ft_toupper.c str/ft_strreverse.c get_next_line.c str/ft_split_whitespaces.c\
put/ft_print_words_tables.c put/ft_putlnbr.c put/ft_putllnbr.c put/ft_putfnbr.c\
put/putf/putf.c put/putf/ft_check.c put/putf/ft_init_tab.c put/putf/ft_args_1.c\
put/putf/ft_args_2.c put/putf/ft_args_3.c put/putf/ft_convert_base.c\
put/putf/print_usage.c str/ft_str3join.c str/ft_realloc.c\

OBJ=$(SRC:.c=.o)

YEL="\\033[33m"
BLU="\\033[34m"
RED="\\033[31m"
NC="\\033[0m"
CYA="\\033[36m"
GRE="\\033[32m"
BOL="\\033[1m"
CHE="\\xE2\\x9C\\x94"
OK="$(GRE)$(CHE)$(NC)"

all : $(NAME)

$(NAME) : $(OBJ)
	@printf "\n[$(NAME_P)] doing ar rc $(BOL)$(CYA)$@$(NC)"
	@ar rc $@ $^
	@printf '\t\t\t'$(OK)'\n'
	@printf "[$(NAME_P)] doing ranlib $(BOL)$(CYA)$@$(NC)"
	@ranlib	$@
	@printf '\t\t\t'$(OK)'\n'

%.o: %.c
	@printf "\r\033[0K[$(NAME_P)] compile $(BOL)$(YEL)$<$(NC)..."
	@$(CC) $(CFLAGS) -o $@ -c $<
	@printf '\t\t\t'$(OK)

clean :
	@printf "[$(NAME_P)] rm all $(BOL)$(RED) obj file$(NC)"
	@rm -f $(OBJ) */*.o
	@printf '\t\t\t'$(OK)'\n'

fclean : clean
	@printf "rm $(BOL)$(CYA)$(NAME)$(NC)"
	@rm -f $(NAME)
	@printf '\t'$(OK)'\n'

cleanf :
	@printf "[$(NAME)] rm $(BOL)$(CYA)$(NAME)$(NC)"
	@rm -f $(NAME)
	@printf '\t\t\t\t'$(OK)'\n'

proper : all clean

re : fclean all

.PHONY: proper re cleanf
