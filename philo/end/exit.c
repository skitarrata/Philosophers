
#include "../header/philosophers.h"

void	ft_error(t_philo *philo, char *text)
{
	printf("%s", text);
	ft_free_philo(philo);
	exit(0);
}
