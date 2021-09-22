
#include "../header/philosophers.h"

void	ft_free_philo(t_arg *arg)
{
	if (arg->philos)
		free(arg->philos);
	if (arg)
		free(arg);
}