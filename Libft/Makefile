NAME = libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror
OBJECTS = ft_isalpha.o ft_itoa.o ft_memmove.o ft_putnbr_fd.o ft_strdup.o ft_strlcpy.o ft_strnstr.o \
	ft_tolower.o ft_bzero.o ft_isascii.o ft_memchr.o ft_memset.o ft_putstr_fd.o ft_striteri.o ft_strlen.o \
	ft_strrchr.o ft_toupper.o ft_calloc.o ft_isdigit.o ft_memcmp.o ft_putchar_fd.o ft_split.o ft_strjoin.o \
	ft_strmapi.o ft_strtrim.o ft_isalnum.o ft_isprint.o ft_memcpy.o ft_putendl_fd.o ft_strchr.o ft_strlcat.o \
	ft_strncmp.o ft_substr.o

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C ft_printf
	ar rcs $(NAME) $(OBJECTS) ft_printf/ft_csu_percent.o ft_printf/ft_d_i.o ft_printf/ft_p.o \
	ft_printf/ft_xx.o ft_printf/ft_printf.o

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

.PHONY: all clean fclean re

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ft_printf fclean

re: fclean
	$(MAKE) -C ft_printf re
	$(MAKE) all
