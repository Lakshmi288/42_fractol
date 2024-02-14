/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lps <lps@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:06:03 by lps               #+#    #+#             */
/*   Updated: 2024/01/16 13:09:01 by lps              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mandel_init(t_graphics *graph, t_plot *p)
{
	p->y = -1;
	p->x_min = -2.0 / graph->zoom + graph->x_offset;
	p->x_max = 1.0 / graph->zoom + graph->x_offset;
	p->y_min = -1.0 / graph->zoom + graph->y_offset;
	p->y_max = 1.0 / graph->zoom + graph->y_offset;
}

void	mandel_draw(t_graphics *graph)
{
	t_gdata	*img;
	t_plot	p;
	int		value;

	img = graph->img;
	mandel_init(graph, &p);
	while (++p.y < HEIGHT)
	{
		p.x = -1;
		while (++p.x < WIDTH)
		{
			p.real = p.x_min + (double)p.x / WIDTH * (p.x_max - p.x_min);
			p.imag = p.y_min + (double)p.y / HEIGHT * (p.y_max - p.y_min);
			value = mandel_helper(p.real, p.imag, MAX_ITER);
			graph->color = color_map(value, MAX_ITER, graph->cycle);
			my_mlx_pixel_put(img, p.x, p.y, graph->color);
		}
	}
	mlx_put_image_to_window(graph->mlx, graph->win, graph->img->img, 0, 0);
}

int	mandel_helper(double real, double imag, int max_iter)
{
	double	r;
	double	i;
	double	temp;
	int		iter;

	r = 0;
	i = 0;
	iter = 0;
	while (r * r + i * i <= 4 && iter < max_iter)
	{
		temp = r * r - i * i + real;
		i = 2 * r * i + imag;
		r = temp;
		iter++;
	}
	return (iter);
}
