#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	gid_t	egid;
	uid_t	euid;
	int		nbr;
	char	*cmd[2];

	nbr = atoi(av[1]);	// Conversion char* à int
	if (nbr == 423)		// Check si valeur == 423
	{
		cmd[0] = strdup("/bin/sh");		// On ajoute "/bin/sh" à cmd[0]
		cmd[1] = 0;						// On met un /0 à la fin (la fonction execv le demande)
		egid = getegid();				// Egid = egid actuel
		euid = geteuid();				// Euid = euid actuel
		setresgid(egid, egid, egid);	// On définit le gid actuel avec les valeurs mises précedemment
		setresuid(euid, euid, euid);	// On définit le uid actuel avec les valeurs mises précedemment
		execv("/bin/sh", cmd);			// On lance un shell
	}
	else
		fwrite("No !\n", 1, 5, stderr);	// Si la valeur est différente de 423 on affiche ce message.
	return 0;
}
