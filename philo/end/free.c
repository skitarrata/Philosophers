
#include "../header/philosophers.h"

void	ft_free_philo(t_time *time, t_philo *philo)
{
	if (time)
		free(time);
	if (philo)
		free(philo);
}