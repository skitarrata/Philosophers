
#include "header/philosophers.h"

void	*ft_state(void *arg)
{
	t_philo	*p;

	p = (t_philo *) arg;
	while (p->n_eat >= p->cnt || !p->n_eat)
	{
		ft_print(p->start, p->pos, "has taken a fork");
		ft_print(p->start, p->pos, "has taken a fork");
		ft_print(p->start, p->pos, "is eating");
		ft_usleep(p->t_eat);
		p->cnt++;
		ft_print(p->start, p->pos, "is sleeping");
		ft_usleep(p->t_sleep);
		ft_print(p->start, p->pos, "is thinking");
	}
}

/* static void ft_init_philo(t_arg *arg)
{
	i = -1;
	while (++i < arg->n_philo)
		pthread_join(arg->[i].t, NULL);
} */

static void	ft_init(int i, int argc, char *str[], t_philo *philo)
{
	philo[i].n_philo = ft_atoi(str[1]);;
	philo[i].t_die = ft_atoi(str[2]);
	philo[i].t_eat = ft_atoi(str[3]);
	philo[i].t_sleep = ft_atoi(str[4]);
	if (argc == 6)
		philo[i].n_eat = ft_atoi(str[5]);
	philo[i].pos = i + 1;
	philo[i].state = THINK;
	//philo[i].time = ft_atoi(str[2]);
	philo[i].start = ft_time();
	pthread_create(&philo[i].t, NULL, ft_state, philo);
	pthread_mutex_init(&philo[i].fork, NULL);
}

static void	ft_parse(char *str, t_philo *philo)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			ft_error(philo, BAD_PAR);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		len;
	t_philo	*philo;

	i = 0;
	if (argc < 5 || argc > 6)
		ft_error(philo, PAR);
	while (++i < argc)
		ft_parse(argv[i], philo);
	len = ft_atoi(argv[1]);
	if (len < 2)
		ft_error(philo, PHILOERR);
	philo = (t_philo *)ft_calloc(len, sizeof(t_philo));
	if (!philo)
		ft_error(philo, MALLOC_FAIL);
	i = -1;
	while (++i < len)
	{
		ft_init(i, argc, argv, philo);
		pthread_join(philo[i].t, NULL);
	}
	//printf("%d\n", philo[2].n_eat);
	ft_error(philo, END);
}