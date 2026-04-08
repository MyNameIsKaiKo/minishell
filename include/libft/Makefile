NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES =	ft_is.c \
			ft_is2.c \
			ft_memmodif.c \
			ft_strlen.c \
			ft_strmanip.c \
			ft_alphaswitch.c \
			ft_strsearch.c \
			ft_memscan.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_strcmp.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_put.c \
			ft_tab_size.c \
			ft_tab_char_copy.c \
			ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c \
			get_next_line/get_next_line_bonus.c \
			get_next_line/get_next_line_utils_bonus.c

OBJ = $(SOURCES:.c=.o)

LIBFTPRINTF = ft_printf/libftprintf.a

all: $(LIBFTPRINTF) $(NAME)

$(LIBFTPRINTF):
	@make -C ft_printf all
	@cp $(LIBFTPRINTF) $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $@ $^

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	@rm -f $(OBJ)
	@make -C ft_printf clean

fclean: clean
	@rm -f $(NAME)
	@make -C ft_printf fclean

re: fclean all

.PHONY : all clean fclean re bonus
