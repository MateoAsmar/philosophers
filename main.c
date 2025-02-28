/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:11:18 by masmar            #+#    #+#             */
/*   Updated: 2025/01/21 20:40:13 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char	**argv)
{
	t_myenv	myenv;

	myenv.start_time = get_time_in_ms();
	if (argc < 5 || argc > 6)
		printf("Number of arguments should be either 4 or 5.\n");
	else
	{
		if (check_arg_validity(argv, argc, &myenv) != 0)
		{
			printf("Include only postive numbers!\n");
			return (1);
		}
		else
		{
			if (initialize_env(&myenv) < 0)
			{
				printf("An error occured during initialisation");
			}
			death_monitor(&myenv);
			join_all_thread(&myenv);
			if (myenv.stop_eating)
				printf("No Philospher Died!!\n");
		}
	}
	return (0);
}
