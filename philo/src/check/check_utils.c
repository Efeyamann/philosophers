#include "../../includes/philosophers.h"

static int	ft_isdigit(char *s)
{
	int	i;

	i = 0;
	if (!s[i])
		return (0);
	if (s[i] == '+')
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static long	ft_atol(char *s)
{
	long	num;
	int		i;

	i = 0;
	num = 0;
	if (s[i] == '+')
		i++;
	while (s[i])
	{
		num = num * 10 + (s[i] - '0');
		if (num > INT_MAX)
			return (-1);
		i++;
	}
	return (num);
}

int	check_args(int ac, char *av[])
{
	int		i;
	long	num;

	i = 1;
	while (i < ac)
	{
		if (!ft_isdigit(av[i]))
			return (0);
		num = ft_atol(av[i]);
		if (num <= 0)
			return (0);
		i++;
	}
	return (1);
}
