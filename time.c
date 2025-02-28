/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:09:43 by masmar            #+#    #+#             */
/*   Updated: 2025/01/21 20:39:56 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((unsigned long)(tv.tv_sec * 1000 + tv.tv_usec / 1000));
}

void	mutex_destroy(t_myenv *env)
{
	int	i;

	i = 0;
	while (i < env->philocount)
	{
		pthread_mutex_destroy(&env->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&env->writing_m);
	pthread_mutex_destroy(&env->meal_m);
	pthread_mutex_destroy(&env->death_m);
}

int	check_arg_validity(char	**argv, int argc, t_myenv *myenv)
{
	int	i;

	i = 1;
	while (i <= argc - 1)
	{
		if (onlynumber(argv[i]) == 1)
			return (1);
		i++;
	}
	myenv->philocount = ft_atoi(argv[1]);
	myenv->time_to_die = ft_atoi(argv[2]);
	myenv->time_to_eat = ft_atoi(argv[3]);
	myenv->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		myenv->max_timestoeat = ft_atoi(argv[5]);
	else
		myenv->max_timestoeat = -1;
	if (myenv->philocount < 1 || myenv->time_to_die <= 0
		|| myenv->time_to_eat <= 0
		|| myenv->time_to_sleep <= 0
		|| ((myenv->max_timestoeat <= 0) && argc == 6))
		return (1);
	return (0);
}

void	*handler(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	while (1)
	{
		if (philo_died(ph))
			break ;
		take_fork(ph);
		philo_eat(ph);
		philo_sleeping(ph);
		philo_thinking(ph);
	}
	return (NULL);
}

void	take_fork(t_philo *ph)
{
	if (ph->philo_id % 2 == 0)
	{
		pthread_mutex_lock(&ph->env->forks[ph->forkone]);
		printcustom(" has taken a fork", ph);
		pthread_mutex_lock(&ph->env->forks[ph->forktwo]);
		printcustom(" has taken a fork", ph);
	}
	else
	{
		usleep(100);
		pthread_mutex_lock(&ph->env->forks[ph->forktwo]);
		printcustom(" has taken a fork", ph);
		pthread_mutex_lock(&ph->env->forks[ph->forkone]);
		printcustom(" has taken a fork", ph);
	}
}
