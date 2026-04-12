NAME		= minishell
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -f

OBJ_DIR		= obj

VPATH		= env_var:built-in/cd:built-in/unset:built-in/pwd:built-in/export:built-in/echo:built-in/env:expander

SRCS 		=	main.c \
				prompt.c \
				cd.c \
				cd_utils.c \
				pwd.c \
				unset.c \
				env.c  \
				export.c \
				echo.c \
				print_export.c \
				export_utils.c \
				set_export.c \
				quick_string_sort.c \
				env_variable.c \
				general_utils.c \
				wildcards.c \
				expander.c \
				expand_var.c \
				expand_copy.c

OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR	= include/libft
LIBFT		= $(LIBFT_DIR)/libft.a
INCLUDES	= -I includes -I src -I $(LIBFT_DIR)

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