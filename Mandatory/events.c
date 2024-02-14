/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lps <lps@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:03:34 by lps               #+#    #+#             */
/*   Updated: 2024/01/16 12:45:01 by lps              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int mouse_code, int x, int y, t_graphics *graph)
{
	x = x * 1;
	y = y * 1;
	if (mouse_code == SCROLL_UP)
		graph->zoom *= 1.5;
	else if (mouse_code == SCROLL_DOWN)
		graph->zoom *= 0.5;
	draw_fractal(graph);
	return (0);
}

int	key_press(int keycode, t_graphics *graph)
{
	double	move_factor;

	move_factor = 1;
	move_factor /= graph->zoom * 10;
	if (keycode == ESC)
		close_window(graph);
	else if (keycode == J_COLOR_UP)
		graph->cycle += 4;
	else if (keycode == K_COLOR_DOWN)
		graph->cycle -= 4;
	else if (keycode == LEFT_ARROW)
		graph->x_offset -= move_factor;
	else if (keycode == UP_ARROW)
		graph->y_offset -= move_factor;
	else if (keycode == RIGHT_ARROW)
		graph->x_offset += move_factor;
	else if (keycode == DOWN_ARROW)
		graph->y_offset += move_factor;
	else
		return (1);
	draw_fractal(graph);
	return (0);
}

int	close_window(t_graphics *graph)
{
	ft_putstr(RED "... Program closing ...\n" RESET);
	mlx_destroy_image(graph->mlx, graph->img->img);
	mlx_clear_window(graph->mlx, graph->win);
	mlx_destroy_window(graph->mlx, graph->win);
	exit(0);
	return (0);
}
