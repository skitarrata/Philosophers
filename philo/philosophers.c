
#include "header/philosophers.h"

static void ft_init_philo(t_arg *arg)
{
	int i;

	i = -1;
	arg->philos = (t_philo *)ft_calloc(arg->n_philo, sizeof(t_philo));
	if (!arg->philos)
		ft_error(arg, MALLOC_FAIL);
	while (++i < arg->n_philo)
	{
		arg->philos[i].pos = i;
		arg->philos[i].fork = i;
		arg->philos[i].state = THINK;
		arg->philos[i].time = arg->t_die * 1000;
		pthread_create(&(arg->philos[i].t), NULL, nomefunc, NULL);
		pthread_mutex_init(&arg->philos[i].mut, NULL);
	}
}

static void	ft_init(int i, char *str, t_arg *arg)
{
	if (i == 1)
			arg->n_philo = ft_atoi(str);
	if (i == 2)
			arg->t_die = ft_atoi(str);
	if (i == 3)
			arg->t_eat = ft_atoi(str);
	if (i == 4)
			arg->t_sleep = ft_atoi(str);
	if (i == 5)
			arg->n_eat = ft_atoi(str);
}

static void	ft_parse(char *str, t_arg *arg)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			ft_error(arg, BAD_PAR);
}

int	main(int argc, char *argv[])
{
	int		i;
	t_arg	*arg;

	i = 0;
	arg = (t_arg *)ft_calloc(1, sizeof(t_arg));
	if (!arg)
		ft_error(arg, MALLOC_FAIL);
	if (argc >= 5 && argc <= 6)
		while (++i < argc)
		{
			ft_parse(argv[i], arg);
			ft_init(i, argv[i], arg);
			ft_init_philo(arg);
		}
	else
		ft_error(arg, PAR);
	//printf("%d\n", arg->philos[1].state);
	ft_error(arg, END);
}