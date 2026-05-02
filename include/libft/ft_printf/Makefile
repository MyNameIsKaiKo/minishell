NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_printf.c \
			utils_printf.c \
			ft_putnbr_base.c \
			ft_putchar_count.c \
			ft_putnbr_count.c \
			ft_putstr_count.c \
			ft_print_ptr.c

OBJ = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $@ $^

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean: 
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
