/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esir <esir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:48:39 by esir              #+#    #+#             */
/*   Updated: 2025/08/28 18:48:40 by esir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int ac, char *av[])
{
	t_thread		*philo_info;
	t_philo_table	**philo_table;

	if (init_program(ac, av, &philo_info, &philo_table))
		return (1);
	if (run_simulation(philo_info, philo_table))
		return (1);
	shut_program(philo_info, philo_table);
	return (0);
}
