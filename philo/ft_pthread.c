#include "header/philosophers.h"

void	*ft_death_loop(void *arg)
{
	int i;
	t_philo	*p;

	i = -1;
	p = (t_philo *) arg;
	while (1)
	{
		if (ft_time() - p->l_meal > p->t_die)
		{
			ft_print(p->start, p->pos, "is dead");
			pthread_mutex_unlock(p->state);
			return (NULL);
		}
		else if (p->n_eat != -1 && p->cnt >= p->n_eat)
		{
			ft_usleep((float)p->pos);
			pthread_mutex_unlock(p->meal);
			return (NULL);
		}
	}
	return (NULL);
}

void	*ft_meal_loop(void *arg)
{
	int		i;
	t_philo	*p;

	i = -1;
	p = (t_philo *) arg;
	if (p->n_eat)
		pthread_mutex_lock(p->meal);
	while (p->n_eat != 0 && ++i < p->n_philo)
		pthread_mutex_lock(p->meal);
	printf("Everyone has eaten enough !\n");
	pthread_mutex_unlock(p->state);
	return (NULL);
}
