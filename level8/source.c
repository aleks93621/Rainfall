/*
	Pour compiler le .c:
	gcc -m32 -fno-stack-protector -z execstack source.c -o level8
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	buffer[100]; // Globale buffer
char	*auth;		// Globale auth
char	*service;	// Globale service

int main(int ac, char **av)
{
	while (1)	// Boucle infinie
	{
		printf("%p, %p\n", auth, service);	// On affiche les adresses de auth et service

		if (fgets(buffer, 128, stdin) == 0)	// On inscrit dans buffer l'entrée standard
			break;							// Si erreur on quitte

		if (strncmp(buffer, "auth ", 5) == 0)	// Comparaison buffer avec "auth "
		{
			auth = malloc(4);	// Allocation malloc(4) auth.
			*auth = 0x0;		// auth[0] = 0x0;
			if (strlen(buffer + 5) <= 30)	// Si buffer est inférieur à 30
				strcpy(auth, buffer + 5);	// On copie le buffer dans l'auth
		}

		if (strncmp(buffer, "reset", 5) == 0)	// Comparaison buffer avec "reset"
			free(auth);							// Si vraie, on free auth.

		if (strncmp(buffer, "service", 6) == 0)	// Comparaison buffer avec "service"
			service = strdup(buffer + 7);		// Si vraie, on remplit service avec buffer + 7.

		if (strncmp(buffer, "login", 5) == 0)	// Comparaison buffer avec "login"
		{
			if (auth[32] == 0)					// Si auth[32] == NULL
				fwrite("Password:\n", 10, 1, stdout);	// On affiche avec fwrite
			else
				system("/bin/sh");				// Sinon on lance /bin/sh
		}
	}
	return 0;
}
