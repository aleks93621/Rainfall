#include <stdio.h>

int		run(void)
{
	fwrite("Good... Wait what?\n", 19, 1, stdout);
	system("/bin/sh");
}

int		main()
{
    char str[76];

	gets(str);
    return 0;
}
