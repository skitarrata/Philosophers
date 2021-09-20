/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:54:01 by svalenti          #+#    #+#             */
/*   Updated: 2021/06/17 16:54:17 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosophers.h"

void	ft_error(t_philo *philo, char *text)
{
	ft_putstr(text);
	ft_free_philo(philo);
	exit(0);
}
