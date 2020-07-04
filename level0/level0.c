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

	nbr = atoi(av[1]);
	if (nbr == 423)
	{
		cmd[0] = strdup("/bin/sh");
        cmd[1] = 0;
		egid = getegid();
		euid = geteuid();
		setresgid(egid, egid, egid);
		setresuid(euid, euid, euid);
		execv("/bin/sh", cmd);
	}
	else
		fwrite("No !\n", 1, 5, stderr);
	return 0;
}
