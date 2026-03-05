COMPILE =	cc

CFLAGS =	-Werror -Wall -Wextra -g 

SOURCE = 	main.c \
			lexer.c \
			handle_ponct.c \
			./lexerlst/lexerlst_add.c \
			./lexerlst/lexerlst_new.c \
			./lexerlst/lexerlst_free.c \
			./lexerlst/lexerlst_last.c \
			./lexerlst/lexerlst_index.c \
			./lexerlst/lexerlst_merge.c \
			./utils/handle_parr.c \
			./utils/handle_quote.c \
			./utils/lexer_utils.c

LIBFT_DIR = ../../include/libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME =	lexer

INCLUDES =	-I. -Ilibft

OBJS =	$(SOURCE:.c=.o) \
		$(SOURCEPARSER:.c=.o) \
		$(SOURCESTACK:.c=.o)

all:	$(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(COMPILE) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(COMPILE) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
