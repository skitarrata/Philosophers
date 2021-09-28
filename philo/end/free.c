
#include "../header/philosophers.h"

void	ft_free_philo(t_philo *philo)
{
	if (philo)
		free(philo);
}