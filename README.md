# C-Shell
Custom shell similar to bash implemented with the help of system calls in linux and used files for storing history of commands executed.

### Commands (inbuilt)
| Commands | Uses                                                                                           |
|----------|------------------------------------------------------------------------------------------------|
| cd       | Used to change to the specified directory. |
| alias    | Used to create a short alias for long commands and also able to view the currently set aliases. |
| unalias  | Used to remove the alias set for a command. |
| help     | Used to get the information about the shell and set of inbuilt commands. |
| history  | Used to view the history of commands executed. |
| clear    | Used to clear the console. |
| exit     | Exit out of the shell. |

And all other commands other the inbuilt ones are executed using execve system call.

### Compilation
Change directiory into src folder
```
    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell -w
```
This generates the binary named as shell. 

### Easy Access
* Create a folder in current user home directory
```
    mkdir -p /home/$USER/.bin
```
* Add the binary to this folder
```
    mv shell /home/$USER/.bin/
```
* Add the path of the folder to the environment variable to access easily.
```
    export PATH=$PATH:/home/$USER/.bin
```

The export does the change to env PATH variable only in the current session. 

To make it permanent:
* Add this export command to your .bashrc file
```
    export PATH=$PATH:/home/$USER/.bin
```

Now you can easily access the binary from anywhere in the system logged in using the current user. 

### Features
> Stores the history of commands executed.

> Custom shell prompt

> Built-in commands similar to bash.


###### In case if there is a mismatch between the precompiled version, download the source code and recompile it using your gcc compiler.
