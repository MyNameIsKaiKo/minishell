NAME		= minishell
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address
RM			= rm -f

OBJ_DIR		= obj

VPATH		= env_var:built-in/cd:built-in/unset:built-in/pwd:built-in/export:built-in/echo:built-in/env:built-in/exit:expander:parser:parser/lexer:parser/lexer/lexerlst:parser/lexer/utils:parser/node:parser/exec:parser/*

SRCS 		=	maintest.c \
				prompt.c \
				pwd.c \
				unset.c \
				env.c  \
				echo.c \
				cd.c \
				cd_utils.c \
				export.c \
				print_export.c \
				export_utils.c \
				set_export.c \
				quick_string_sort.c \
				exit.c \
				env_variable.c \
				reverse_env.c \
				general_utils.c \
				wildcards.c \
				apply_wildcards.c \
				ast.c \
				ast_exec.c \
				ast_exec_cmd.c \
				ast_exec_cmd_utils.c \
				ast_exec_builtin.c \
				ast_exec_pipe.c \
				ast_exec_heredoc.c \
				ast_exec_redir.c \
				ast_exec_error_message.c \
				ast_utils.c \
				free_tools.c \
				cmd_error.c \
				nodenew.c \
				node_add.c \
				node_free.c \
				nodenew_data.c \
				lexer.c \
				handle_ponct.c \
				lexerlst_add.c \
				lexerlst_new.c \
				lexerlst_free.c \
				lexerlst_last.c \
				lexerlst_index.c \
				lexerlst_merge.c \
				lexerlst_delone.c \
				lexerlst_trim.c \
				handle_parr.c \
				handle_quote.c \
				lexer_utils.c \
				word_merger.c \
				word_and_ponct_merger.c \
				remove_rponct.c \
				expander.c \
<<<<<<< HEAD
				expand_var.c \
=======
				expand_utils.c \
>>>>>>> 7c73e54 (Fix expander with "", fix exit with LLONG overflow)
				apply_expend.c \
				expand_copy.c

OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR	= include/libft
LIBFT		= $(LIBFT_DIR)/libft.a
INCLUDES	= -I includes -I src -I $(LIBFT_DIR) -I./parser/lexer -I./parser

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
