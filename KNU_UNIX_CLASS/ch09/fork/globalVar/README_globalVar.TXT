Child process is another complete process
diffrent from its parent process.

$ gcc proc-shared.c
$ a.out
CHILD: value = 20 
PARENT: value = 10

- value: located at diffrent memory addresses, but in the same image
- How can we send some values from the child process to the parent process?
 1)shared memory
 2)pipe

