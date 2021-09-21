
#include "../header/philosophers.h"

void	ft_error(t_time *time, t_philo *philo, char *text)
{
	printf("%s", text);
	ft_free_philo(time, philo);
	exit(0);
}
