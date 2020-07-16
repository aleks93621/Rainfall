#include <stdio.h>

int		run(void)
{
	fwrite("Good... Wait what?\n", 19, 1, stdout);	// Si la fonction est bien appelée grâce au buffer overflow un message est affiché
	system("/bin/sh");	// Un shell est lancé
}

int		main()
{
	char str[68];	// Définition du buffer

	gets(str);		// Saisie de caractères et de chaînes
	return 0;
}
