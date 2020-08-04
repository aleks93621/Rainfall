#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int language;

void	greetuser(char *user)
{
	char	hello[72];	// Hello qui va stocker le boujour suivant la langue

	if (language == 1)		// Si language 1
		strcpy(hello, "Hyvää päivää ");	// On copy l'arg 2 dans hello
	else if (language == 2)	// Si language 2
		strcpy(hello, "Goedemiddag! ");	// On copy l'arg 2 dans hello
	else					// Sinon
		strcpy(hello, "Hello ");		// On copy l'arg 2 dans hello
	strcat(hello, user);	// On colle le hello à la string passée en paramètre
	puts(hello);			// Affichage de hello
}

int		main(int ac, char **av)
{
	char	buf[72];		// Buffer qui va nous servir de stockage pour nos av[1] et av[2]
	char	*env = NULL;	// String qui stocke l'env LANG
	char	*buf_to_fct;

	if (ac != 3)			// Si ac != 3 on quitte le programme
		return 1;
	
	strncpy(buf, av[1], 40);	// Copie de av[1] dans buf
	strncpy(&buf[40], av[2], 32);	// Copie de av[2] dans buf à partir de l'index 40
	env = getenv("LANG");		// String env est égal à la valeur de la variable d'environnement LANG
	if (env)
	{
		if (memcmp(env, "fi", 2) == 0)			// On compare l'env et et une string
			language = 1;						// Si env et fi correspondent , language = 1
		else if (memcmp(env, "nl", 2) == 0)		// On compare l'env et et une string
			language = 2;						// Si env et nl correspondent , language = 2
	}
	/*
		0x08048618 <+239>:	mov    edx,esp
		0x0804861a <+241>:	lea    ebx,[esp+0x50]
		0x0804861e <+245>:	mov    eax,0x13
		0x08048623 <+250>:	mov    edi,edx
		0x08048625 <+252>:	mov    esi,ebx
		0x08048627 <+254>:	mov    ecx,eax
		0x08048629 <+256>:	rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
	*/
	strncpy(buf_to_fct, buf, 19);
	greetuser(buf);			// On lance la fonction greetuser avec le buf
}
