NAME			= minishell
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g
RM				= rm -f

OBJ_DIR			= obj

# VPATH			= 

SRCS 			=	prompt.c

OBJS			= $(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR		= include/libft
LIBFT			= $(LIBFT_DIR)/libft.a
INCLUDES		= -I includes -I src -I $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) -lreadline $(OBJS) $(LIBFT) -o $(NAME)
	@echo "Minishell OK\n"

$(LIBFT):
	@make -C $(LIBFT_DIR) all

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean: 
	@$(RM) -r $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "Objects removed\n"

fclean: clean
	@$(RM) -r $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "Minishell removed\n"

re: fclean all

.PHONY : all clean fclean re