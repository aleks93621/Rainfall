/*
	Pour compiler le .c:
	gcc -m32 -fno-stack-protector -z execstack source.c -o level8
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	buffer[100];
char	*auth;
char	*service;

int main(int ac, char **av)
{
	while (1)
	{
		printf("%p, %p\n", auth, service);

		if (fgets(buffer, 128, stdin) == 0)
			break;

		if (strncmp(buffer, "auth ", 5) == 0)
		{
			auth = malloc(4);
			*auth = 0x0;
			if (strlen(buffer + 5) <= 30)
				strcpy(auth, buffer + 5);
		}

		if (strncmp(buffer, "reset", 5) == 0)
			free(auth);

		if (strncmp(buffer, "service", 6) == 0)
			service = strdup(buffer + 7);

		if (strncmp(buffer, "login", 5) == 0)
		{
			if (auth[32] == 0)
				fwrite("Password:\n", 10, 1, stdout);
			else
				system("/bin/sh");
		}
	}
	return 0;
}
