##
## EPITECH PROJECT, 2019
## makefile
## File description:
## match
##

SRC		= 		./src/main.c 							\
				./src/link/basic_link.c 				\
				./src/link/link_env.c 					\
				./src/link/link_path.c 					\
				./src/init/init_env.c 					\
				./src/init/init_path_link.c 			\
				./src/tool.c 							\
				./src/prompt/prompt.c 					\
				./src/prompt/command.c 					\
				./src/env/setenv.c 						\
				./src/env/unsetenv.c 					\
				./src/link/binary_tree.c 				\
				./src/cd/cd.c 							\
				./src/cd/cd2.c 							\
				./src/env/tool_env.c					\
				./src/is_alphanumeric.c 				\
				./src/prompt/execute_binary.c 			\
				./src/prompt/basic.c 					\

OBJ		= $(SRC:.c=.o)
CC 		= gcc
CLANG	=
RM		= rm -f
NAME	= mysh
LIB		= make -C ./lib/my
TEST 	= make -C ./tests
CFLAGS	= -W -Wall -Wextra -g3 -Wno-deprecated -I./include/
CSFML	= -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system
LDFLAGS		=  -L. lib/libmy.a

### COLORS ###
NOC			= \033[0m
BOLD		= \033[1m
UNDERLINE	= \033[4m
BLACK		= \033[1;30m
RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
VIOLET		= \033[1;35m
CYAN		= \033[1;36m
WHITE		= \033[1;37m

all: 		start $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]"

$(NAME):	$(OBJ)
		@echo "$(BOLD)Creating LIB $(GREEN)[IN PROGRESS]"
			$(LIB)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS) -lncurses
		@echo "$(GREEN)[$(NAME)] was successfully created$(NOC)"
		make clean

test_run:
			$(TEST)
		./tests/unit_tests

retest:
	$(TEST) re
	./tests/unit_tests

clean:
		$(LIB) clean
		$(RM) $(OBJ)
		@echo "\033[5m\033[3m\033[33mEtat for -> $(NAME) -> clean -> OK\033[0m"

fclean: clean
		$(RM) $(NAME)
		$(LIB) fclean
		@echo "\033[5m\033[3m\033[33mEtat for -> $(NAME) -> fclean -> OK\033[0m"

end:
	@echo "\033[5m\033[1m\033[32mEtat for -> $(NAME) -> compil -> OK\033[0m"

start:
	@echo "\033[5m\033[1m\033[32mWe compil your project\033[0m"

re:		fclean all
