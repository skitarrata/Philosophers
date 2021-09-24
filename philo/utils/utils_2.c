#include "../header/philosophers.h"

long int	ft_time(void)
{
	struct timeval	sec;

	gettimeofday(&sec, NULL);
	return (sec.tv_sec * 1000 + sec.tv_usec / 1000);
}

void	ft_usleep(int length)
{
	long int	time;

	time = ft_time();
	while (ft_time() < time + length)
		usleep(length);
}

void	ft_print(long int time, int phil, char *str)
{
	long int nb;

	nb = ft_time() - time;
	printf("%ld           philosopher %d: %s\n", nb, phil, str);
}