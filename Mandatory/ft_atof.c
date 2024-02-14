/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lps <lps@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:45:33 by lps               #+#    #+#             */
/*   Updated: 2024/01/16 12:45:41 by lps              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_flag(char *str)
{
	int	x;

	x = -1;
	while (str[++x])
		if (str[x] == '.')
			return (x);
	return (0);
}

static int	is_valid(char *str, int x, int count)
{
	x = -1;
	count = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		if (!(str[1] >= '0' && str[1] <= '9'))
			return (42);
		x++;
	}
	if (str[0] == '.' || str[0] == '\0' || str[ft_strlen(str) - 1] == '.')
		return (42);
	while (str[++x])
	{
		if ((str[x] >= '0' && str[x] <= '9') || str[x] == '.')
		{
			if (str[x] == '.')
				count++;
		}
		else
			return (42);
	}
	if (!((str[x] >= '0' && str[x] <= '9') || str[x] == '\0'))
		return (42);
	if (count > 1)
		return (42);
	return (0);
}

static void	check_sign(t_atof *store, char *s)
{
	if (s[0] == '-' || s[0] == '+')
	{
		if (s[0] == '-')
			store->sign = -1;
		store->x++;
	}
}

double	ft_atof(char *s)
{
	t_atof		store;
	long double	res;

	if (is_valid(s, 0, 0) == 42)
		return (42);
	store.inde = 0;
	store.x = -1;
	res = 0.0;
	store.flag = check_flag(s);
	store.inde = check_flag(s);
	store.inde = ft_strlen(s) - store.inde;
	store.x = -1;
	store.sign = 1;
	check_sign(&store, s);
	while (s[++store.x])
		if (s[store.x] >= '0' && s[store.x] <= '9')
			res = (res * 10) + (s[store.x] - '0');
	if (store.flag > 0)
	{
		store.inde = pow(10, store.inde - 1);
		return ((res / store.inde) * store.sign);
	}
	return (res * store.sign);
}
