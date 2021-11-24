/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:39:24 by vaferrei          #+#    #+#             */
/*   Updated: 2021/11/24 00:05:40 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

static void	plot_vector_high(t_img *img, t_vector vector);
static void	plot_vector_low(t_img *img, t_vector vector);
static void	plot_pixel(t_img *img, t_vector vector, t_plot plot);
static void	plot_size(t_img *img, t_vector vec, t_vector nv1, t_vector nv2);

static void	plot_vector_low(t_img *img, t_vector vector)
{
	t_plot	plot;

	plot.yi = 1;
	plot.x = vector.x1;
	plot.y = vector.y1;
	plot.delta_x = vector.x2 - vector.x1;
	plot.delta_y = vector.y2 - vector.y1;
	if (plot.delta_y < 0)
	{
		plot.yi = -1;
		plot.delta_y = -plot.delta_y;
	}
	plot.error_xy = (2 * plot.delta_y) - plot.delta_x;
	while (plot.x <= vector.x2)
	{
		plot_pixel(img, vector, plot);
		if (plot.error_xy > 0)
		{
			plot.y = plot.y + plot.yi;
			plot.error_xy = plot.error_xy + (2 * (plot.delta_y - plot.delta_x));
		}
		else
			plot.error_xy = plot.error_xy + 2 * plot.delta_y;
		plot.x++;
	}
}

static void	plot_pixel(t_img *img, t_vector vector, t_plot plot)
{
	int	new_color;

	if (vector.color1 == vector.color2)
		new_color = vector.color1;
	else
		new_color = get_color(vector, plot.x, plot.y);
	pixel_to_image(img, plot.x, plot.y, new_color);
}

static void	plot_vector_high(t_img *img, t_vector vector)
{
	t_plot	plot;

	plot.xi = 1;
	plot.delta_x = vector.x2 - vector.x1;
	plot.delta_y = vector.y2 - vector.y1;
	plot.x = vector.x1;
	plot.y = vector.y1;
	if (plot.delta_x < 0)
	{
		plot.xi = -1;
		plot.delta_x = -plot.delta_x;
	}
	plot.error_xy = (2 * plot.delta_x) - plot.delta_y;
	while (plot.y <= vector.y2)
	{
		plot_pixel(img, vector, plot);
		 if (plot.error_xy > 0)
		{
			plot.x = plot.x + plot.xi;
			plot.error_xy = plot.error_xy + (2 * (plot.delta_x - plot.delta_y));
		}
		else
			plot.error_xy = plot.error_xy + 2 * plot.delta_x;
		plot.y++;
	}
}

static void	plot_size(t_img *img, t_vector vec, t_vector nv1, t_vector nv2)
{
	if (ft_abs(vec.y2 - vec.y1) < ft_abs(vec.x2 - vec.x1))
	{
		if (vec.x1 > vec.x2)
			plot_vector_low(img, nv1);
		else
			plot_vector_low(img, nv2);
	}
	else
	{
		if (vec.y1 > vec.y2)
			plot_vector_high(img, nv1);
		else
			plot_vector_high(img, nv2);
	}
}

void	plot_vector(t_img *img, t_vector vector, int color)
{
	t_vector	new_vector1;
	t_vector	new_vector2;

	if (color == -2)
	{
		vector.color1 = BLUE;
		vector.color2 = GREEN;
	}
	else if (color != -1)
	{
		vector.color1 = color;
		vector.color2 = color;
	}
	new_vector1 = get_new_vector(vector.x2, vector.y2, vector.x1, vector.y1);
	new_vector1 = get_new_color(new_vector1, vector.color2, vector.color1);
	new_vector2 = get_new_vector(vector.x1, vector.y1, vector.x2, vector.y2);
	new_vector2 = get_new_color(new_vector2, vector.color1, vector.color2);
	plot_size(img, vector, new_vector1, new_vector2);
}
