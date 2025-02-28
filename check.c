/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:10:21 by masmar            #+#    #+#             */
/*   Updated: 2025/01/21 20:40:21 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*handler1(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	pthread_mutex_lock(&ph->env->forks[0]);
	printcustom(" has taken a fork", ph);
	usleep(ph->env->time_to_die * 1000);
	printcustom(" has died", ph);
	pthread_mutex_unlock(&ph->env->forks[0]);
	return (NULL);
}

void	mem_clean(t_myenv *env)
{
	mutex_destroy(env);
	if (env->forks)
		free(env->forks);
	if (env->ph)
		free(env->ph);
}

void	philo_eat(t_philo *ph)
{
	unsigned long	time;

	pthread_mutex_lock(&ph->env->meal_m);
	if (philo_died(ph))
	{
		pthread_mutex_unlock(&ph->env->meal_m);
		pthread_mutex_unlock(&ph->env->forks[ph->forkone]);
		pthread_mutex_unlock(&ph->env->forks[ph->forktwo]);
		return ;
	}
	time = get_time_in_ms();
	ph->last_meal_time = time;
	printcustom(" is eating", ph);
	ph->eatcount += 1;
	pthread_mutex_unlock(&ph->env->meal_m);
	usleep((ph->env->time_to_eat) * 1000);
	pthread_mutex_unlock(&ph->env->forks[ph->forkone]);
	pthread_mutex_unlock(&ph->env->forks[ph->forktwo]);
}

void	death_monitor(t_myenv *env)
{
	int	i;

	while (1)
	{
		i = 0;
		if (env->philocount == 1)
			return ;
		while (i < env->philocount)
		{
			if (philo_check(&env->ph[i]))
				return ;
			i++;
		}
		if (eating_count(env))
			return ;
		usleep(100);
	}
}

int	philo_check(t_philo *ph)
{
	unsigned long	time;

	pthread_mutex_lock(&ph->env->meal_m);
	time = get_time_in_ms();
	if ((time - ph->last_meal_time) > (unsigned long)ph->env->time_to_die)
	{
		if (ph->env->stop_death == 0)
		{
			pthread_mutex_lock(&ph->env->death_m);
			time = (get_time_in_ms() - ph->env->start_time);
			printf("%lu Philosopher %d has died\n", time, ph->philo_id);
			ph->env->stop_death = 1;
			pthread_mutex_unlock(&ph->env->death_m);
			pthread_mutex_unlock(&ph->env->meal_m);
			return (1);
		}
	}
	pthread_mutex_unlock(&ph->env->meal_m);
	return (0);
}
