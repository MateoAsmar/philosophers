/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmar <masmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:08:39 by masmar            #+#    #+#             */
/*   Updated: 2025/01/21 20:46:11 by masmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				philo_id;
	int				forkone;
	int				forktwo;
	int				eatcount;
	unsigned long	last_meal_time;
	struct s_myenv	*env;
	pthread_t		t_id;
}	t_philo;

typedef struct s_myenv
{
	int					philocount;
	int					max_timestoeat;
	int					time_to_sleep;
	int					time_to_eat;
	int					time_to_die;
	int					stop_death;
	int					stop_eating;
	t_philo				*ph;
	pthread_mutex_t		*forks;
	pthread_mutex_t		writing_m;
	pthread_mutex_t		meal_m;
	pthread_mutex_t		death_m;
	unsigned long		start_time;
}	t_myenv;

// check.c:
void			*handler1(void *arg);
void			mem_clean(t_myenv *env);
void			philo_eat(t_philo *ph);
void			death_monitor(t_myenv *env);
int				philo_check(t_philo *ph);

// init.c:
void			initialize_philoshers(t_myenv *env, t_philo *philo, int pos);
int				initialize_mutex(t_myenv *env);
int				initialize_env(t_myenv *env);
void			printcustom(char *msg, t_philo *ph);
int				initialize_threadsallthreads(t_myenv *e);

// main.c:
int				main(int argc, char	**argv);

// philo_utils.c:
int				eating_count(t_myenv *env);
int				philo_died(t_philo *ph);
void			philo_thinking(t_philo *ph);
void			join_all_thread(t_myenv *env);
void			philo_sleeping(t_philo *philo);

// time.c:
unsigned long	get_time_in_ms(void);
void			mutex_destroy(t_myenv *env);
int				check_arg_validity(char	**argv, int argc, t_myenv *myenv);
void			*handler(void *arg);
void			take_fork(t_philo *ph);

// utils.c:
int				ft_atoi(char *nptr);
int				onlynumber(char *s);

#endif
