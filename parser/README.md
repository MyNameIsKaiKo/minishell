# parser minishell

**bonus : yes**

Parsing order ->

Create three :
 - Check for operator -> if exist LOGIC else PIPE
 - If no operator -> it's a command

 ```
 commande : < Makefile cat | ls -l > out && echo success
                    
                    [&&]
                   /    \
                [pipe]  [cmd : echo]
                /   \
        [cmd cat]   [cmd ls -l]
 ```

 Operator LOGIC behavior :
  - && -> both need to be true in order to pass the door.
  - || -> only one need to be correct

  Pipe behavior -> take the result of the two command made in his left and right node and pipe the left one into the right one using fork

  CMD behavior -> check if the cmd is built in or not. If not built in check if it exist otherwise return error.

  ----------------------------------------------------------

The make_three function need to be recursiv in order to create everything without any node lost.

    1 -> find operator logic
        2 -> create node if exist
        3 -> create left and right using recursive -> node->left = make_three(...);
    4 -> find operator pipe
        5 -> create node if exist
        6 -> create left and right using recursive.
    7 -> if nothing found it is a function

Need to reed the str backward for LOGICAL operator
And in the right way for PIPE order

The exec_three function

    
