
#include "../header/philosophers.h"

void	ft_error(t_arg *arg, char *text)
{
	printf("%s", text);
	ft_free_philo(arg);
	exit(0);
}
