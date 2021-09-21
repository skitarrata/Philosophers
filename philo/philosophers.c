
#include "header/philosophers.h"

static void	ft_init(int i, char *str, t_time *time, t_philo *philo)
{
	if (i == 1)
			philo->n_philo = ft_atoi(str[i]);
	if (i == 2)
			time->t_die = ft_atoi(str[i]);
	if (i == 3)
			time->t_eat = ft_atoi(str[i]);
	if (i == 4)
			time->t_sleep = ft_atoi(str[i]);
	if (i == 5)
			philo->n_eat = ft_atoi(str[i]);
}

static void	ft_parse(char *str, t_time *time, t_philo *philo)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			ft_error(time, philo, BAD_PAR);
}

int	main(int argc, char *argv)
{
	int		i;
	t_time	*time;
	t_philo	*philo;

	i = 0;
	time = (t_time *)ft_calloc(1, sizeof(t_time));
	philo = (t_philo *)ft_calloc(1, sizeof(t_philo));
	if (!time || !philo)
		ft_error(time, philo, MALLOC_FAIL);
	if (argc >= 4 && argc <= 5)
		while (++i <= argc)
		{
			ft_parse(argv[i], time, philo);
			ft_init(i, argv[i], time, philo);
		}
	else
		ft_error(time, philo, PAR);
	ft_error(time, philo, END);
}