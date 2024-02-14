/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lps <lps@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:04:22 by lps               #+#    #+#             */
/*   Updated: 2024/01/16 12:45:13 by lps              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include <ctype.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 1080
# define HEIGHT 720
# define MAX_ITER 42

# define RESET "\x1B[0m"   // Reset color
# define RED "\x1B[31m"    // Red color
# define GREEN "\x1B[32m"  // Green color
# define YELLOW "\x1B[33m" // Yellow color

# define UP_ARROW 126
# define DOWN_ARROW 125
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define ESC 53
# define J_COLOR_UP 38
# define K_COLOR_DOWN 40

typedef struct s_gdata
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_gdata;

typedef struct s_plot
{
	int			x;
	int			y;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	double		real;
	double		imag;
	double		c_real;
	double		c_imag;
}				t_plot;

typedef struct s_custom_plot
{
	double		c_real;
	double		c_imag;
}				t_cus_plot;

typedef struct s_graphics
{
	void		*mlx;
	void		*win;
	int			set_num;
	double		zoom;
	int			color;
	int			cycle;
	t_gdata		*img;
	t_plot		*points;
	int			x;
	int			y;
	double		x_offset;
	double		y_offset;
	t_cus_plot	cus_pts;
}				t_graphics;

typedef struct s_atof
{
	long double	res;
	int			x;
	double		inde;
	int			flag;
	int			check;
	double		sign;
}				t_atof;

/* >>> drawing functions <<< */
void			julia_draw(t_graphics *graph);
int				julia_helper(t_plot points, int max_iter);
void			my_mlx_pixel_put(t_gdata *data, int x, int y, int color);
void			draw_set(int set_num, double real, double imag);
void			draw_fractal(t_graphics *graph);
void			mandel_draw(t_graphics *graph);
int				color_map(int value, int max_iter, int cycle);
int				mandel_helper(double real, double imag, int max_iter);
int				create_trgb(unsigned char t, unsigned char r, unsigned char g,
					unsigned char b);

/* >>> events functions <<< */
int				expose_hook(t_graphics *graph);
int				key_press(int keycode, t_graphics *graph);
int				close_window(t_graphics *graph);
int				mouse_hook(int mouse_code, int x, int y, t_graphics *graph);

/* >>> utils <<< */
void			show_usage(void);
void			ft_putstr(char *str);
int				ft_atoi(char *str);
double			ft_atof(char *s);
int				ft_strlen(char *str);

#endif
