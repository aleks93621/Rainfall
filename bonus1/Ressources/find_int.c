/*
	gcc find_int.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int main(int ac, char **av)
{
	int x = atoi(av[1]);

	for (int i = x; i > INT_MIN; i--) {
		int j = i * 4;
		printf("i  = %d, i * 4 = %d\n", i, j);
	}
	return 0;
}