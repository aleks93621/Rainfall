#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **av)
{
	int		x;			// int correspondant au av[1]
	char	buff[40];	// memcpy() dans buff

	x = atoi(av[1]);	// Conversion de char* à int
	/*
		0x08048441 <+29>:	cmp    DWORD PTR [esp+0x3c],0x9
   		0x08048446 <+34>:	jle    0x804844f <main+43>
	*/
	if (x <= 9)			// test si x est inférieur ou égal à 9
	{
		memcpy(buff, av[2], x * 4);	// Copie de av[2] dans buff
		/*
			0x08048478 <+84>:	cmp    DWORD PTR [esp+0x3c],0x574f4c46
   			0x08048480 <+92>:	jne    0x804849e <main+122>
		*/
		if (x == 0x574f4c46)		// test si x est égal à 0x574f4c46
			execl("/bin/sh", "sh", 0x0);	// On lance execl()
	}
	else
		return 1;
	return 0;
}

