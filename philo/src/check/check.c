/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:47:43 by esir              #+#    #+#             */
/*   Updated: 2025/08/28 18:47:44 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	check(int ac, char *av[])
{
	if (!check_args(ac, av))
	{
		printf("Error: invalid arguments\n");
		return (1);
	}
	return (0);
}
