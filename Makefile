NAME = push_swap
NAME_BONUS = checker
CC = cc
FLAGS = -Wall -Wextra -Werror
LIBRARY = libft/libft.a
OBJECTS = actions.o find_extremes.o main.o manage_chunks.o rules.o fill_stack_a.o manage_pa.o utilities.o
BONUS_OBJECTS = checker_bonus.o rules_bonus.o fill_stack_a.o actions.o utilities_bonus.o

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBRARY) $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) $(LIBRARY) -o $(NAME)

$(LIBRARY):
	$(MAKE) -C ./libft

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

bonus: $(LIBRARY) $(BONUS_OBJECTS)
	$(CC) $(FLAGS) $(BONUS_OBJECTS) $(LIBRARY) -o $(NAME_BONUS)

clean:
	$(MAKE) -C ./libft clean
	rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	$(MAKE) -C ./libft fclean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all
