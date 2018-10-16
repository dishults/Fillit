# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dshults <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/14 18:34:55 by dshults           #+#    #+#              #
#    Updated: 2018/01/04 14:32:12 by klouer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

OK_STRING    = "[OK]"
ERROR_STRING = "[ERROR]"
WARN_STRING  = "[WARNING]"
COM_STRING   = "Compiling"
RUN_STRING	 = "Running"

NAME = fillit

FLAGS = -Wall -Werror -Wextra

SRC_NAME = main.c	put.c	get.c	solve.c	tris.c	check_input.c color.c random.c ft_randomtab.c ft_gencolorcode.c ft_checkargs.c premadecolortab.c argparser.c
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC_PATH = ./src/
INC_PATH = ./src/
LFT_PATH = ./libft/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(SRC_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

## Compiles the libs and the project
all: $(NAME)

$(NAME): $(OBJ)
	@printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) libft" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n";
	@make -C $(LFT_PATH)
	@gcc -o $(NAME) $(OBJ) -L $(LFT_PATH) -lft
	@printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n";
	@printf "%-60b%b" "$(OK_COLOR)\nCompilation successful." "$(NO_COLOR)\n\n"
	@printf "%-60b%b" "$(WARN_COLOR)Usage: ./fillit (-cr) [mapfile] (-c is what happens\nwhen you have too much time on your hands... And there's even more.) - Have fun !" "$(NO_COLOR)\n";

$(SRC_PATH)%.o: $(SRC_PATH)%.c
	@gcc $(FLAGS) $(INC) -o $@ -c $<

## Cleans the previously generated object files
clean:
	@make -C $(LFT_PATH) clean
	@rm -rf $(OBJ)
	@printf "%-60b%b" "$(COM_COLOR)$(RUN_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n";

## Cleans the object files and the executable itself
fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -rf $(NAME)
	@printf "%-60b%b" "$(COM_COLOR)$(RUN_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n";

## Cleans everything first, then compiles the whole project
re: fclean all

## COLORS
GREEN  := $(shell tput -Txterm setaf 2)
YELLOW := $(shell tput -Txterm setaf 3)
WHITE  := $(shell tput -Txterm setaf 7)
RESET  := $(shell tput -Txterm sgr0)


TARGET_MAX_CHAR_NUM=20
## Show help
help:
	@echo ''
	@echo 'Usage:'
	@echo '  ${YELLOW}make${RESET} ${GREEN}<target>${RESET}'
	@echo ''
	@echo 'Targets:'
	@awk '/^[a-zA-Z\-\_0-9]+:/ { \
		helpMessage = match(lastLine, /^## (.*)/); \
		if (helpMessage) { \
			helpCommand = substr($$1, 0, index($$1, ":")-1); \
			helpMessage = substr(lastLine, RSTART + 3, RLENGTH); \
			printf "  ${YELLOW}%-$(TARGET_MAX_CHAR_NUM)s${RESET} ${GREEN}%s${RESET}\n", helpCommand, helpMessage; \
		} \
	} \
	{ lastLine = $$0 }' $(MAKEFILE_LIST)


define NEWLINE


endef

define TAB

endef

Authors=klouer and dshults
Version=1.4
Function=Tries to fit tetriminos into the smallest possible map
RunHelp = ------------------------- Run 'make help' to see usage ---------------------------
Git =https://github.com/Alkanna/42fillit
$(info ╔════════════════════════════════════════════════════════════════════════════════╗)
$(info ------------------------- ${YELLOW}Authors${RESET} : ${GREEN}$(Authors)${RESET} ---------------------------)
$(info ------------------------------- ${YELLOW}Version${RESET} : ${GREEN}$(Version)${RESET} ----------------------------------)
$(info ----------------- ${YELLOW}GitHub${RESET} : ${GREEN}$(Git)${RESET} -------------------)
$(info ------- ${YELLOW}Function${RESET} : ${GREEN}$(Function)${RESET} --------$(NEWLINE)$(RunHelp))
$(info ╚════════════════════════════════════════════════════════════════════════════════╝$(NEWLINE))
