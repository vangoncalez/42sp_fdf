/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:39:24 by vaferrei          #+#    #+#             */
/*   Updated: 2021/11/21 23:12:46 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

static void	plotVectorHigh(t_img *img, t_vector vector, int color);
static void	plotVectorLow(t_img *img, t_vector vector, int color);
static void	plot_pixel(t_img *img, t_vector vector, t_plot	plot, int color);

void	rectangle(t_img *img, t_vector vector, int color)
{
	int	i;
	int	x;
	int	y;
	int	w;
	int	h;

	x = vector.x1;
	y = vector.y1;
	w = vector.x2;
	h = vector.y2;
	i = y + 1;
	plot_vector(img, get_plot_vector(x, y, x + w, y), GREY5);
	plot_vector(img, get_plot_vector(x, y + h, x + w, y + h), GREY5);
	plot_vector(img, get_plot_vector(x, y, x, y + h), GREY5);
	plot_vector(img, get_plot_vector(x + w, y, x + w, y + h), GREY5);
	while (i < y + h)
	{
		plot_vector(img, get_plot_vector(x + 1, i, x + w - 1, i), color);
		i++;
	}
}

t_vector	get_plot_vector(float x1, float y1, float x2, float y2)
{
	t_vector	vector;

	vector.x1 = x1;
	vector.x2 = x2;
	vector.y1 = y1;
	vector.y2 = y2;
	return (vector);
}

static void	plotVectorLow(t_img *img, t_vector vector, int color)
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
		plot_pixel(img, vector, plot, color);
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

static void	plot_pixel(t_img *img, t_vector vector, t_plot	plot, int color)
{
	int	new_color;

	if (color == -1)
		new_color = get_color(vector, plot.x, plot.y);
	else
		new_color = color;
	pixel_to_image(img, plot.x, plot.y, new_color);

}

static void	plotVectorHigh(t_img *img, t_vector vector, int color)
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
		plot_pixel(img, vector, plot, color);
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



void	plot_vector(t_img *img, t_vector vector, int color)
{
	int			new_color;
	t_vector	new_vector1;
	t_vector	new_vector2;

	new_vector1 = get_plot_vector(vector.x2, vector.y2, vector.x1, vector.y1);
	new_vector2 = get_plot_vector(vector.x1, vector.y1, vector.x2, vector.y2);
	if (color == -1)
		new_color = get_color(vector, vector.x1, vector.y1);
	else
		new_color = color;
	if (ft_abs(vector.y2 - vector.y1) < ft_abs(vector.x2 - vector.x1))
	{
		if (vector.x1 > vector.x2)
			plotVectorLow(img, new_vector1, new_color);
		else
			plotVectorLow(img, new_vector2, new_color);
	}
	else
	{
		if (vector.y1 > vector.y2)
			plotVectorHigh(img, new_vector1, new_color);
		else
			plotVectorHigh(img, new_vector2, new_color);
	}
}
