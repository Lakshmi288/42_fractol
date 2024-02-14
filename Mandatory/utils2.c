/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lps <lps@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:06:40 by lps               #+#    #+#             */
/*   Updated: 2024/01/16 12:46:30 by lps              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	expose_hook(t_graphics *graph)
{
	mlx_put_image_to_window(graph->mlx, graph->win, graph->img->img, 0, 0);
	return (0);
}

void	my_mlx_pixel_put(t_gdata *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(unsigned char t, unsigned char r, unsigned char g,
		unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

int	color_map(int value, int max_iter, int cycle)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (!(cycle >= -max_iter && cycle < max_iter))
		cycle = 0;
	t = (double)value / (max_iter - cycle);
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (create_trgb(0, r, g, b));
}
