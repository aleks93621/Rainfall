#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>

int main(int ac, char **av)
{
	FILE	*pass;		// Fichier file pour fopen()
	char	buf[24];	// Buffer 1
	char	buf2[42];	// Buffer 2
	int		nb;			// Int qui va servir pour le atoi(av[1])
	
	pass = fopen("/home/user/end/.pass", "r");	// Fichier FILE qui va contenir le fichier passé en paramètre
	/*
		0x0804851f <+43>:	lea    ebx,[esp+0x18]
		0x08048523 <+47>:	mov    eax,0x0
		0x08048528 <+52>:	mov    edx,0x21
		0x0804852d <+57>:	mov    edi,ebx
		0x0804852f <+59>:	mov    ecx,edx
		0x08048531 <+61>:	rep stos DWORD PTR es:[edi],eax
	*/
	bzero(buf, 33);

	if (pass == 0 || ac != 2)	// Si fichier FILE est null ou si ac != 2
		return -1;				// On arrête le programme et on retourne -1
	fread(buf, 1, 66, pass);	// fread() qui va inscrire le FILE dans le premier buffer
	nb = atoi(av[1]);			// nb qui va contenir atoi(av[1])
	buf[nb] = 0x0;				// buffer[nb] = '\0'
	fread(buf2, 1, 65, pass);	// fread() qui va inscrire le FILE dans le deuxième buffer
	fclose(pass);				// On ferme la lecture du fichier
	if (strcmp(buf, av[1]) == 0)	// Comparaison entre buffer1 et av[1]
		execl("/bin/sh", "sh", 0x0);	// Si identiques on fait un execl()
	else
		puts(buf2);				// Sinon on affiche buf2

	return 0;					// Fin programme
}
