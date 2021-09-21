NAME = philosophers
PAR =  5 2 4

#FLAGS = -Wall -Werror -Wextra

SRCS = 	$(shell find . -name '*.c')
FILES = $(shell find . -name '*.c' -name '*.h')

OBJ = $(SRCS:.c=.o)
CC	=	gcc

$(NAME): $(OBJ)
	@echo "[Removing last version...]"
	@rm -rf philosophers
	@echo "[philosophers compilation...]"
	@$(MAKE) bonus -C
	@$(CC) $(SRCS) -o $(NAME) -g -pthread
	@echo "[Done!]"
	@$(MAKE) clean
#-fsanitize=address

all : $(NAME)

norme:
	@norminette $(FILES)

leaks: $(MAKE) all
	@leaks --atExit -- ./$(NAME) $(PAR)

run: $(MAKE) re
	@./$(NAME) $(PAR)
clean:
	@rm -rf $(OBJ)
	@$(MAKE) clean -C

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) fclean -C

re : fclean all
