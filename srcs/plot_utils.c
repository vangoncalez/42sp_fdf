/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 23:45:45 by vaferrei          #+#    #+#             */
/*   Updated: 2021/11/26 23:15:03 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	rectangle(t_fdf *fdf, t_vector vector, int color)
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
	plot_vector(fdf, get_new_vector(x, y, x + w, y), GREY5);
	plot_vector(fdf, get_new_vector(x, y + h, x + w, y + h), GREY5);
	plot_vector(fdf, get_new_vector(x, y, x, y + h), GREY5);
	plot_vector(fdf, get_new_vector(x + w, y, x + w, y + h), GREY5);
	while (i < y + h)
	{
		plot_vector(fdf, get_new_vector(x + 1, i, x + w - 1, i), color);
		i++;
	}
}

t_vector	get_new_vector(float x1, float y1, float x2, float y2)
{
	t_vector	vector;

	vector.x1 = x1;
	vector.x2 = x2;
	vector.y1 = y1;
	vector.y2 = y2;
	return (vector);
}

t_vector	get_new_color(t_vector	 vector, int color1, int color2)
{
	vector.color1 = color1;
	vector.color2 = color2;
	return (vector);
}

void	pixel_to_image(t_img *img, float x, float y, int color)
{
	if (x >= 0 && x < W_WIDTH && y >= 0 && y < W_HEIGHT)
		*(int *)(img->mem + (int)(idx(y, x, W_WIDTH) * img->bits_pixel)) =
			color;
}

double	get_percent(double start, double end, double search)
{
	if (search == start)
		return (0.0);
	if (search == end)
		return (1.0);
	if (start == end)
		return (0.0);
	return ((search - start) / (end - start));
}
