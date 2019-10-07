#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	struct stat buf;

	printf("1. stat: %s ---\n", argv[1]);
	stat(argv[1], &buf);
	printf("%s: Link count = %d\n", argv[1], (int)buf.st_nlink);
	printf("%s: i-node = %d\n", argv[1], (int)buf.st_ino);


	printf("2. stat: %s ---\n", argv[2]);
	stat(argv[2], &buf);
	printf("%s: Link count = %d\n", argv[2], (int)buf.st_nlink);
	printf("%s: i-node = %d\n", argv[2], (int)buf.st_ino);

	printf("3. lstat: %s ---\n", argv[3]);
	lstat(argv[3], &buf);
	printf("%s: Link count = %d\n", argv[3], (int)buf.st_nlink);
	printf("%s: i-node = %d\n", argv[3], (int)buf.st_ino);

	return 0;
}

