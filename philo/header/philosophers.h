#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include "error.h"

typedef struct	s_philo
{
	int			n_philo;
	int			n_eat;
}				t_philo;

typedef struct	s_time
{
	long int	t_die;
	long int	t_eat;
	long int	t_sleep;
}				t_time;

int		ft_strlen(const char *str);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	ft_error(t_time *time, t_philo *philo, char *text);
void	ft_free_philo(t_time *time, t_philo *philo);

#endif