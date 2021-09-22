#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include "error.h"

# define EAT 1
# define SLEEP 2
# define THINK 3

typedef struct		s_philo
{
	int				pos;
	int				fork;
	int				state;
	long int		time;
	pthread_mutex_t	mut;
}					t_philo;

typedef struct		s_arg
{
	long int		t_die;
	long int		t_eat;
	long int		t_sleep;
	t_philo			*philos;
	int				n_philo;
	int				n_eat;
}					t_arg;

int		ft_strlen(const char *str);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	ft_error(t_arg *arg, char *text);
void	ft_free_philo(t_arg *arg);

#endif