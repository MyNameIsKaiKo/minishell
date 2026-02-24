# parser minishell

**bonus : yes**

Parsing order ->

First do Lexer :
 - Read char by char and create chained list of token
 - Check for quotes "" and '' -> if inside quote, everything is a WORD (even | or &&)
 - Check for redirection -> if < is followed by < it make << (HEREDOC)
 - Check for parentheses -> add PONCT token

Create tree :
 - Check for operator in the token list -> if exist LOGIC else PIPE
 - We only check operator that are NOT inside parentheses (depth == 0)
 - If no operator -> it's a command (or subshell)

 ```
 commande : ( cat file | grep "hello" ) && echo success
                [&&]
               /    \
     [subshell ()]  [cmd : echo]
           |
        [pipe]
        /   \
[cmd cat]   [cmd grep]
```

Operator LOGIC behavior :
 - && -> both need to be true in order to pass the door.
 - || -> only one need to be correct

 Pipe behavior -> take the result of the two command made in his left and right node and pipe the left one into the right one using fork
 
 () behavior -> fork a new process and execute the tree inside so it dont affect main shell <-- said by gpt need to check

 CMD behavior -> open redirection first (<< >> < >). Check if the cmd is built in or not. If not built in check if it exist otherwise return error.

 ----------------------------------------------------------

The make_tree function need to be recursiv in order to create everything without any node lost.

   1 -> find operator logic (need to be depth 0 to ignore parenthesis)
       2 -> create node if exist
       3 -> create left and right using recursive -> node->left = make_tree(...);
   4 -> find operator pipe (need to be depth 0)
       5 -> create node if exist
       6 -> create left and right using recursive.
   7 -> check if token are fully inside parenthesis ( )
       8 -> remove parenthesis and do make_tree on the inside
   9 -> if nothing found it is a function (CMD). Save redirection in the CMD node.

Need to reed the token chained list backward for LOGICAL operator
And in the right way for PIPE order

The exec_tree function
   1 -> if node is && or || -> exec left, check status, exec right
   2 -> if node is pipe -> fork twice, plug pipefd to left and right
   3 -> if node is CMD -> open redirection, remove quote, check built in or execve
