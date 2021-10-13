#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include "error.h"

# define TAKE "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DEAD "is dead"

typedef struct		s_philo
{
	int				pos;
	int				cnt;
	int				fork_left;
	int				fork_right;
	pthread_mutex_t	*state;
	pthread_mutex_t	*meal;
	long int		l_meal;
	pthread_t		t_id;
	struct s_rules	*rules;
}					t_philo;

typedef struct		s_rules
{
	int				n_philo;
	long int		t_die;
	long int		t_eat;
	long int		t_sleep;
	int				n_eat;
	long int		start;
	int				dieded;
	pthread_mutex_t	forks[250];
	t_philo			philo[250];
}					t_rules;


int			ft_strlen(const char *str);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
void		ft_free_philo(t_philo *philo);
void		ft_error(char *text);
long int	ft_time(void);
void		ft_usleep(int length);
void		ft_print(long int time, int phil, char *str);
void		*ft_death_loop(void *arg);
void		*ft_meal_loop(void *arg);

#endif