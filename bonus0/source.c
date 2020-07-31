#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	p(char	*s, char	*delim)
{
	char	buffer[4096];	// Définition de buffer (0x080484d0 <+28>:	lea    eax,[ebp-0x1008])

	puts(delim);	// On affiche ' - '
	read(0, buffer, 4096);	// On attend une entrée du user
	*strchr(buffer, '\n') = 0;	// Renvoi un pointeur sur la première occurence et on met à \0
	strncpy(s, buffer, 20);	// Copie buffer dans arg1
}

void	pp(char *buffer)	// Disas pp
{
	char	s1[20];	// Définition de buffer (0x0804852e <+16>:	lea    eax,[ebp-0x30])
	char	s2[20];	// Définition de buffer (0x08048541 <+35>:	lea    eax,[ebp-0x1c]

	p(s1, " - ");	// Appel fonction p() (0x08048534 <+22>:	call   0x80484b4 <p>)
	p(s2, " - ");	// Appel fonction p() (0x08048547 <+41>:	call   0x80484b4 <p>)
	strcpy(buffer, s1);	// Buffer s1 copié dans buffer
	buffer[strlen(buffer)] = ' ';	// On met à la fin de buffer un espace
	strcat(buffer, s2);	// On ajoute à buffer le deuxième buffer
}

int		main(int ac, char **av)	// Disas main
{
	char	buffer[22];	// Défintion de buffer (0x080485ad <+9>:	lea    eax,[esp+0x16])

	pp(buffer);			// Appel fonction pp() (0x080485b4 <+16>:	call   0x804851e <pp>)
	puts(buffer);		// Fonction puts() qui va afficher le buffer

	return 0;
}
