/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lps <lps@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:01:29 by lps               #+#    #+#             */
/*   Updated: 2024/01/16 13:08:33 by lps              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	julia_init(t_graphics *graph, t_plot *p)
{
	p->y = -1;
	p->x_min = -2.0 / graph->zoom + graph->x_offset;
	p->x_max = 2.0 / graph->zoom + graph->x_offset;
	p->y_min = -2.0 / graph->zoom + graph->y_offset;
	p->y_max = 2.0 / graph->zoom + graph->y_offset;
	if (graph->cus_pts.c_real && graph->cus_pts.c_imag)
	{
		p->c_real = graph->cus_pts.c_real;
		p->c_imag = graph->cus_pts.c_imag;
	}
	else
	{
		p->c_real = -0.835;
		p->c_imag = -0.2321;
	}
}

void	julia_draw(t_graphics *graph)
{
	t_plot	p;
	int		value;

	julia_init(graph, &p);
	while (++p.y < HEIGHT)
	{
		p.x = -1;
		while (++p.x < WIDTH)
		{
			p.real = p.x_min + ((p.x - graph->x) * (p.x_max - p.x_min) / WIDTH
					+ (double)graph->x / WIDTH * (p.x_max - p.x_min));
			p.imag = p.y_min + ((p.y - graph->y) * (p.y_max - p.y_min) / HEIGHT
					+ (double)graph->y / HEIGHT * (p.y_max - p.y_min));
			value = julia_helper(p, MAX_ITER);
			graph->color = color_map(value, MAX_ITER, graph->cycle);
			my_mlx_pixel_put(graph->img, p.x, p.y, graph->color);
		}
	}
	mlx_put_image_to_window(graph->mlx, graph->win, graph->img->img, 0, 0);
}

int	julia_helper(t_plot points, int max_iter)
{
	double	r;
	double	i;
	double	temp;
	int		iter;

	r = points.real;
	i = points.imag;
	iter = 0;
	while (r * r + i * i <= 4 && iter < max_iter)
	{
		temp = r * r - i * i + points.c_real;
		i = 2 * r * i + points.c_imag;
		r = temp;
		iter++;
	}
	return (iter);
}
