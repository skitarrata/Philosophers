
#include "header/philosophers.h"

static void	ft_parse(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			ft_error(BAD_PAR);
}

void		ft_init_philo(t_rules *rules)
{
	int i;

	i = -1;
	while (++i < rules->n_philo)
	{
		rules->philo[i].pos = i + 1;
		rules->philo[i].fork_left = i;
		rules->philo[i].fork_right = (i + 1) % rules->n_philo;
		rules->philo[i].rules = rules;
	}
}

void		ft_init_mutex(t_rules *rules)
{
	int i;

	i = -1;
	while (++i < rules->n_philo)
		pthread_mutex_init(&rules->forks[i], NULL);
}

static void	ft_init(t_rules *rules, int argc, char *argv[])
{
	rules->n_philo = ft_atoi(argv[1]);
	rules->t_die = ft_atoi(argv[2]);
	rules->t_eat = ft_atoi(argv[3]);
	rules->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		rules->n_eat = ft_atoi(argv[5]);
	else
		rules->n_eat = -1;
	ft_init_philo(rules);
	ft_init_mutex(rules);
}

void	*ft_thread (void *arg)
{
	t_philo *phi;
	t_rules *rules;

	phi = (t_philo *)arg;
	rules = phi->rules;
	if (phi->pos % 2 == 0)
		usleep(15000);
	while (!rules->dieded)
	{
		pthread_mutex_lock(&rules->forks[phi->fork_left]);
		ft_print(rules->start, phi->pos, TAKE);
		pthread_mutex_lock(&rules->forks[phi->fork_right]);
		ft_print(rules->start, phi->pos, TAKE);
		ft_print(rules->start, phi->pos, EATING);
		ft_usleep(rules->t_eat);
		pthread_mutex_unlock(&rules->forks[phi->fork_left]);
		pthread_mutex_unlock(&rules->forks[phi->fork_right]);
		ft_print(rules->start, phi->pos, SLEEPING);
		ft_usleep(rules->t_sleep);
		ft_print(rules->start, phi->pos, THINKING);
	}
	return (NULL);
}

void	ft_philo (t_rules *rules)
{
	int i;
	t_philo *phi;
	int err;

	phi = rules->philo;
	i = -1;
	rules->start = ft_time();
	while (++i < rules->n_philo)
	{
		err = pthread_create(&phi[i].t_id, NULL, ft_thread, &phi[i]);
		if (err != 0)
			ft_error(THREAD_FAIL);
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	int		len;
	t_rules	rules;

	i = 0;
	if (argc < 5 || argc > 6)
		ft_error(PAR);
	while (++i < argc)
		ft_parse(argv[i]);
	ft_init(&rules, argc, argv);
	ft_philo(&rules);
	ft_error(END);
}