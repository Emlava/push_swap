NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror -I./libft
OBJECTS = ft_printf.o ft_csu_percent.o ft_p.o ft_d_i.o ft_xx.o

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
