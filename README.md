![Logo](https://uploads-ssl.webflow.com/6105315644a26f77912a1ada/63eea844ae4e3022154e2878_Holberton.png)

# **C – Simple Shell**

## **Description**
This is a basic implementation of a shell in C . The shell allows users to execute commands, supports basic functionalities like navigating directories, and handles some built-in commands. It provides a command-line interface where users can interact with the operating system by entering commands.
![flowchart](https://github.com/EtienneAbeng/holbertonschool-simple_shell/assets/134635340/780cf242-ed87-4fc8-8ad4-13c038ffa895)


## **Requirements**
- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to (why?)
## **Authorized functions and macros**
- all functions from string.h
- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- getpid (man 2 getpid)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- printf (man 3 printf)
- fprintf (man 3 fprintf)
- vfprintf (man 3 vfprintf)
- sprintf (man 3 sprintf)
- putchar (man 3 putchar)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)
## **Process description**

Here's a brief description of how the shell works:

1. **Parent Process Creation:**
   When the user runs the program, the parent process is created.

2. **Terminal Check:**
   The `isatty()` function is used with the `STDIN_FILENO` file descriptor (fd) to test if there is an open file descriptor referring to a terminal. If `isatty()` returns 1, the prompt is shown using `write()` with `STDOUT_FILENO` as fd, and the program waits for user input.

3. **Command Parsing:**
   When the user types a command, the `getline()` function reads the entire line from the stream, and the `strtok()` function breaks the input command into a sequence of non-empty tokens.

4. **Child Process Creation:**
   A separate child process is created using `fork()` to execute the inputted command. Unless specified otherwise, the parent process waits for the child to exit before continuing.

5. **Command Execution:**
   After tokenizing the command, the `execve()` function is used to bring and execute it. Once executed, the program frees all allocated memory using `free()`.

6. **Return to Main Process:**
   Finally, the program returns to the main process. It prints the prompt and waits for another user input.
   ## **Compilation**
•	Your code will be compiled this way:
```
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c

```
## Authors
- [Etienne Abeng](https://www.github.com/EtienneAbeng)
- [abbassi mohamed ayoub](https://www.github.com/abbassimedayoub)

