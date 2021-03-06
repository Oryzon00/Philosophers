/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:38:56 by ajung             #+#    #+#             */
/*   Updated: 2022/05/11 17:10:33 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int				i;
	long long		output;

	i = 0;
	output = 0;
	if (ft_strlen(nptr) > 11)
		return (ATOI_FAILURE);
	while (((9 <= nptr[i]) && (nptr[i] <= 13)) || (nptr[i] == ' '))
		i++;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
		return (ATOI_FAILURE);
	if (!('0' <= nptr[i]) && (nptr[i] <= '9'))
		return (ATOI_FAILURE);
	while (('0' <= nptr[i]) && (nptr[i] <= '9'))
	{
		output = nptr[i] - '0' + (output * 10);
		i++;
		if (output > 2147483647)
			return (ATOI_FAILURE);
		else if (output < -2147483648)
			return (ATOI_FAILURE);
	}
	if (nptr[i] != '\0')
		return (ATOI_FAILURE);
	return (output);
}
