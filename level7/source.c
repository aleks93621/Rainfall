#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

char	c[68];

void	m(void)
{
	printf("%s - %ld\n", c, time(0));
}

int 	main(int ac, char **av)
{
	char	*s1;
	char	*s2;

	s1 = malloc(8);
	*s1 = 0x1;
	s1[1] = malloc(8);

	s2 = malloc(8);
	*s2 = 0x2;
	s2[1] = malloc(8);

	strcpy(&s1[1], av[1]);
	strcpy(&s2[1], av[2]);
	fgets(c, 68, fopen("./flag", "r"));
	puts("~~");
}
