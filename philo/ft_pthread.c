#include "header/philosophers.h"

void	*ft_death_loop(void *arg)
{
	t_philo	*p;

	p = (t_philo *) arg;
	while (1)
	{
		if (ft_time() - p->l_meal > p->t_die)
		{
			ft_print(p->start, p->pos, "has died");
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
	ft_print(p->start, 0, "Everyone has eaten enough !");
	pthread_mutex_unlock(p->state);
}
