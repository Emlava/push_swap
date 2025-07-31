NAME = push_swap
NAME_BONUS = checker
CC = cc
FLAGS = -Wall -Wextra -Werror
LIBRARY = libft/libft.a
SOURCES = actions.c find_extremes.c main.c manage_chunks.c rules.c fill_stack_a.c manage_pa.c utilities.c
BONUS_SOURCES = checker_bonus.c rules_bonus.c fill_stack_a.c actions.c utilities_bonus.c 

.PHONY: all clean fclean re

all: $(NAME)

$(LIBRARY):
	$(MAKE) -C ./libft

$(NAME): $(LIBRARY)
	$(CC) $(FLAGS) $(SOURCES) $(LIBRARY) -o $(NAME)

bonus: $(LIBRARY)
	$(CC) $(FLAGS) $(BONUS_SOURCES) $(LIBRARY) -o $(NAME_BONUS)

clean:
	$(MAKE) -C ./libft clean

fclean:
	$(MAKE) -C ./libft fclean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all
