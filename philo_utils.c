/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:12:06 by masmar            #+#    #+#             */
/*   Updated: 2025/01/21 20:47:21 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating_count(t_myenv *env)
{
	int	i;
	int	eat_stop;

	i = 0;
	eat_stop = 1;
	if (env->max_timestoeat < 0)
		return (0);
	while (i < env->philocount)
	{
		pthread_mutex_lock(&env->meal_m);
		if (env->ph[i].eatcount < env->max_timestoeat)
			eat_stop = 0;
		pthread_mutex_unlock(&env->meal_m);
		i++;
	}
	if (eat_stop)
	{
		pthread_mutex_lock(&env->death_m);
		env->stop_eating = 1;
		pthread_mutex_unlock(&env->death_m);
		return (1);
	}
	return (0);
}

int	philo_died(t_philo *ph)
{
	pthread_mutex_lock(&ph->env->death_m);
	if (ph->env->stop_death || ph->env->stop_eating)
	{
		pthread_mutex_unlock(&ph->env->death_m);
		return (1);
	}
	pthread_mutex_unlock(&ph->env->death_m);
	return (0);
}

void	philo_thinking(t_philo *ph)
{
	printcustom(" is thinking", ph);
}

void	join_all_thread(t_myenv *env)
{
	int	i;

	i = 0;
	while (i < env->philocount)
	{
		pthread_join(env->ph[i].t_id, NULL);
		i++;
	}
	mem_clean(env);
}

void	philo_sleeping(t_philo *philo)
{
	printcustom(" is sleeping", philo);
	usleep((philo->env->time_to_sleep) * 1000);
}
