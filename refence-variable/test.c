
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

enum hello {ONE, TWO, THREE};

int main(void)
{
	printf("%d\n", sizeof(enum));
	return 0;
}
