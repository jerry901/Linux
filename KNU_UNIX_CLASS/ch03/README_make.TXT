
stdio.h: /usr/include

1)a single file
 - logest.c

$ gcc -o longest longest.c
$ ls
...	longest
$ longest
<user should input sentences>
...
$ longest < input.file
...

2)making multiple files
 - main.c copy.h copy.c
 - Makefile
 - copy: array-version
 - copyPtr: pointer-version

$ make
$ main 
...
$ main < input.file
...


