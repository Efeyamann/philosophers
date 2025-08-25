#include "../includes/philosophers.h"

int main(int ac, char *av[])
{
    if(ac < 5 || ac > 6)
        return(0);
    check(ac, av);
}