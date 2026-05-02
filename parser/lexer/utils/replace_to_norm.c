#include "lexer.h"

static int is_redir(t_token_type type)
{
    if (type == REDIR_IN || type == REDIR_OUT || type == HEREDOC || type == APPEND)
        return (1);
    return (0);
}

static void relink_lexer(lex, t_lexer *previous, t_lexer *curr)
{
    to_replace = curr->next->next;
    lexer_set_next(&(curr->next), to_replace->next);
    if (previous == NULL)
    {
        lexer_set_next(&to_replace, curr);
        *lex = to_replace;
    }
    else
    {
        lexer_set_next(&previous, to_replace);
        lexer_set_next(&to_replace, curr);
    }
}

static int  to_replace_word(t_lexer **lex)
{
    t_lexer *curr;
    t_lexer *previous;

    curr = *lex;
    previous = NULL;
    while (curr && curr->next && curr->next->next)
    {
        if (is_redir(curr->type) && curr->next->type == WORD && curr->next->next->type == WORD)
        {
            relink_lexer(lex, previous, curr);
            return (1);
        }
        previous = curr;
        curr = curr->next;
    }
    return (0);
}

void    replace_to_norm(t_lexer **lex)
{
    int is_normed;

    if (!lex || !*lex)
        return ;
    is_normed = 1;
    while (is_normed)
    {
        is_normed = to_replace_word(lex);
        indexing_lex(lex);
    }
}