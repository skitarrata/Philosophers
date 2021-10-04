
#include "header/philosophers.h"

static void	ft_init(int i, int argc, char *str[], t_philo *p)
{
	p[i].n_philo = ft_atoi(str[1]);;
	p[i].t_die = ft_atoi(str[2]);
	p[i].t_eat = ft_atoi(str[3]);
	p[i].t_sleep = ft_atoi(str[4]);
	if (argc == 6)
		p[i].n_eat = ft_atoi(str[5]);
	else
		p[i].n_eat = -1;
	p[i].pos = i + 1;
	p[i].start = ft_time();
	p[i].l_meal = p[i].start;
	pthread_mutex_init(&p[i].fork, NULL);
	if (i)
		p[i].prev = &p[i - 1].fork;
	else
		p[i].prev = NULL;
}

static void	ft_parse(char *str, t_philo *philo)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			ft_error(philo, BAD_PAR);
}

void	*ft_state(void *arg)
{
	t_philo		*p;
	pthread_t	t;

	p = (t_philo *) arg;
	pthread_create(&t, NULL, ft_death_loop, p);
	if (p->pos % 2 == 0)
		ft_usleep((float)p->t_eat * 0.9 + 1);
	while (p->n_eat > p->cnt || p->n_eat == -1)
	{
		pthread_mutex_lock(&p->fork);
		ft_print(p->start, p->pos, "has taken a fork");
		pthread_mutex_lock(p->prev);
		ft_print(p->start, p->pos, "has taken a fork");
		p->l_meal = ft_time();
		ft_print(p->start, p->pos, "is eating");
		ft_usleep(p->t_eat);
		pthread_mutex_unlock(&p->fork);
		pthread_mutex_unlock(p->prev);
		p->cnt++;
		ft_print(p->start, p->pos, "is sleeping");
		ft_usleep(p->t_sleep);
		ft_print(p->start, p->pos, "is thinking");
	}
}

static void	ft_philo(t_philo *p)
{
	int				i;
	pthread_t		t;
	pthread_mutex_t	state;
	pthread_mutex_t meal;

	i = -1;
	pthread_mutex_init(&state, NULL);
	pthread_mutex_init(&meal, NULL);
	pthread_mutex_lock(&state);
	p[0].prev = &p[p[0].n_philo - 1].fork;
	while (++i < p[0].n_philo)
	{
		p[i].state = &state;
		p[i].meal = &meal;
		pthread_create(&t, NULL, ft_state, &p[i]);
		//pthread_mutex_destroy(&p[i].fork);
	}
	if (p[0].n_eat > -1)
		pthread_create(&t, NULL, ft_meal_loop, &p[0]);
	pthread_mutex_lock(&state);
	i = -1;
	while (++i < p[0].n_philo)
		pthread_mutex_destroy(&p[i].fork);
	pthread_mutex_destroy(&state);
	pthread_mutex_destroy(&meal);
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
		ft_init(i, argc, argv, philo);
	ft_philo(philo);
	ft_error(philo, END);
}