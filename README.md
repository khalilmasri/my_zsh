 <!-- GETTING STARTED -->
## My_zsh (UNIX Shell)
### Task Description

Your interpreter will display a prompt: $> (for example)

You will have to wait for a command line to be written (ending by a newline character (enter))

You will have to parse the command line and format it in order to execute it.

The prompt must be displayed again only after the command execution.

For the execution you must use execve.

Only basic command lines are expected to be executed; no pipes, redirections or any other advanced features. The executables should be those found in the path, as indicated in the PATH variable.

If the executable cannot be found, you must display an error message and display the prompt again. Errors must be dealt with and must display the appropriate message on the error output. You must correctly handle the PATH and the environment (by copying and restoring the initial env).

You must implement the following builtins: 
* Echo
* cd
* setenv
* unsetenv
* env
* exit
* pwd
* which

### Approach Used

We approached this task by ......
### Program Usage

1. From the terminal move to "my_zsh" directory and type "make" to compile the program.

   ```sh
   make
   ```
2. You can then run the program with "./my_zsh" to run the shell and a prompt ">" will appearthen can use following built-ins: 
    * echo
    * cd
    * setenv
    * unsetenv
    * env
    * exit
    * pwd
    * which

    or binary executables:
    * touch
    * ls
    * etc....

   ```sh
   e.g './my_bc'
        'nnnnnnn'
   ```
3. The program will then run as a replication of zsh

4. You can clean up '.o' files by typing the following command after usage
    ```sh
   'make clean'
   ```

