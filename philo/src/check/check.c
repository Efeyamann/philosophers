#include "../../includes/philosophers.h"

int check(int ac, char *av[])
{
	if (!check_args(ac, av))
	{
		printf("Error: invalid arguments\n");
		return (1);
	}
}