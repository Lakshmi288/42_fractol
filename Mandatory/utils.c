/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lps <lps@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:06:22 by lps               #+#    #+#             */
/*   Updated: 2024/01/16 12:46:21 by lps              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdbool.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	long long	result;
	int			i;

	i = 0;
	result = 0;
	if (str == NULL)
		return (-42);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] && !(str[i] >= '0' && str[i] <= '9'))
		return (-42);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		if (result > UINT_MAX)
			return (-42);
		i++;
	}
	if (str[i] && !(str[i] >= '0' && str[i] <= '9'))
		return (-42);
	return (result);
}
