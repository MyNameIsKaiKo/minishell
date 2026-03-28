COMPILE =	cc

CFLAGS =	-Wall -Wextra -g 

SOURCE = 	main.c \
			./lexer/lexer.c \
			./lexer/handle_ponct.c \
			./lexer/lexerlst/lexerlst_add.c \
			./lexer/lexerlst/lexerlst_new.c \
			./lexer/lexerlst/lexerlst_free.c \
			./lexer/lexerlst/lexerlst_last.c \
			./lexer/lexerlst/lexerlst_index.c \
			./lexer/lexerlst/lexerlst_merge.c \
			./lexer/lexerlst/lexerlst_delone.c \
			./lexer/lexerlst/lexerlst_trim.c \
			./lexer/utils/handle_parr.c \
			./lexer/utils/handle_quote.c \
			./lexer/utils/lexer_utils.c \
			./lexer/utils/word_merger.c \
			./lexer/utils/word_and_ponct_merger.c \
			./lexer/utils/remove_rponct.c \
			./ast.c \
			./ast_utils.c \
			./node/nodenew.c \
			./node/node_add.c \
			./node/node_free.c \
			./node/nodenew_data.c 

LIBFT_DIR = ../include/libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME =	ast

INCLUDES =	-I. -Ilibft

OBJS =	$(SOURCE:.c=.o) \

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
