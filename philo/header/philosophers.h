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

# define TAKE "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DEAD "is dead"

typedef struct		s_philo
{
	int				pos;
	int				state;
	int				cnt;
	//long int		time;
	long int		start;
	pthread_t		t;
	pthread_mutex_t	fork;
	long int		t_die;
	long int		t_eat;
	long int		t_sleep;
	int				n_philo;
	int				n_eat;
}					t_philo;

int			ft_strlen(const char *str);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
void		ft_free_philo(t_philo *philo);
void		ft_error(t_philo *philo, char *text);
long int	ft_time(void);
void		ft_usleep(int length);
void		ft_print(long int time, int phil, char *str);
void		*ft_state(void *arg);
//void		ft_putnbr(long int nb);

#endif