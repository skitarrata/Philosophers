
#include "../header/philosophers.h"

int	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		s;
	long	res;

	i = 0;
	s = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\f' || str[i] == '\v' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = ((res * 10) + (str[i++] - '0'));
		if (res > 2147483648)
			break ;
	}
	if ((res == 2147483648 && s == -1) || res <= 2147483648)
		return (res * s);
	return (s == 1 ? -1 : 0);
}

static void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = 0;
	return ;
}

void	*ft_calloc(size_t count, size_t size)
{
	void *res;

	if (!(res = malloc(count * size)))
		return (0);
	ft_bzero(res, count * size);
	return (res);
}