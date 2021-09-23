NAME = philosophers
PAR =  5 2 4 6

#FLAGS = -Wall -Werror -Wextra

SRCS = 	$(shell find . -name '*.c')
FILES = $(shell find . -name '*.c' -name '*.h')

OBJ = $(SRCS:.c=.o)
CC	=	gcc

$(NAME): $(OBJ)
	@echo "[Removing last version...]"
	@rm -rf philosophers
	@echo "[philosophers compilation...]"
	@$(CC) $(SRCS) -o $(NAME) -lpthread
	@echo "[Done!]"
	@$(MAKE) clean
#-fsanitize=address

all : $(NAME)

norme:
	@norminette $(FILES)

leaks: $(MAKE) all
	@leaks --atExit -- ./$(NAME) $(PAR)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re : fclean all
