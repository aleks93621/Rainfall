#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

char	c[68];		// Variable globale qui va stocker le flag

void	m(void)
{
	printf("%s - %ld\n", c, time(0));	// Affichage globale + temps
}

int 	main(int ac, char **av)
{
	char	*s1;	// Chaine qui va contenir l'argv[1]
	char	*s2;	// Chaine qui va contenir le modifieur (donc la fonction m())

	s1 = malloc(8);	// Premier malloc sur s1
	*s1 = 0x1;		// Première valeur de s1 = 0x1
	s1[1] = malloc(8);	// La deuxième case pointée est malloc de 8

	s2 = malloc(8);	// Même schéma qu'au dessus
	*s2 = 0x2;
	s2[1] = malloc(8);

	strcpy(&s1[1], av[1]);	// Strcpy de l'argv[1] dans la deuxième case de s1
	strcpy(&s2[1], av[2]);	// Strcpy pour modifier l'overflow tu strcpy 1
	fgets(c, 68, fopen("./flag", "r"));	// Ecriture dans le fichier passé dans fopen()
	puts("~~");	// Fonction qui affiche un message, c'est cette fonction qu'on modifie dans le GOT
}
