NAME = push_swap
NAME_BONUS = checker
CC = cc
FLAGS = -g -Wall -Wextra -Werror
LIBRARY = libft/libft.a
OBJECTS = actions.o find_extremes.o main.o manage_chunks.o rules.o fill_stack_a.o manage_pa.o general_utilities.o \
fill_stack_a_utilities.o
BONUS_OBJECTS = checker_bonus.o rules_bonus.o fill_stack_a.o actions.o utilities_bonus.o fill_stack_a_utilities.o

.PHONY: all bonus clean fclean re

all: $(NAME)

$(LIBRARY):
	$(MAKE) -C ./libft

$(NAME): $(LIBRARY) $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) $(LIBRARY) -o $(NAME)

$(NAME_BONUS): $(LIBRARY) $(BONUS_OBJECTS)
	$(CC) $(FLAGS) $(BONUS_OBJECTS) $(LIBRARY) -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

bonus: $(NAME_BONUS)

clean:
	$(MAKE) -C ./libft clean
	rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	$(MAKE) -C ./libft fclean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all
