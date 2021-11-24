/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 22:13:25 by vaferrei          #+#    #+#             */
/*   Updated: 2021/11/23 23:58:33 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"
static int		gradiente(int color1, int color2, double percent);
static double	get_percent(double start, double end, double search);
static double	color(double start, double end, double percent);

void	clear_image(t_img *img, int color)
{
	int	x;
	int	y;

	ft_bzero(img->mem, W_WIDTH * W_HEIGHT * img->bits_pixel);
	y = 0;
	while (y < W_HEIGHT && color != 0)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			pixel_to_image(img, x, y, color);
			x++;
		}
		y++;
	}
}

int	get_color(t_vector vector, double x, double y)
{
	int		color;
	double	percent;
	double	percentx;
	double	percenty;

	percentx = get_percent(vector.x1, vector.x2, x);
	percenty = get_percent(vector.y1, vector.y2, y);
	if (x < y)
		percent = percentx;
	else
		percent = percenty;
	if (vector.x1 == vector.x2 || vector.y1 == vector.y2)
		percent = max_value(percentx, percenty);
	color = gradiente(vector.color1, vector.color2, percent);
	return (color);
}

static double	get_percent(double start, double end, double search)
{
	if (search == start)
		return (0.0);
	if (search == end)
		return (1.0);
	if (start == end)
		return (0.0);
	return ((search - start) / (end - start));
}

static int	gradiente(int color1, int color2, double percent)
{
	int	r;
	int	g;
	int	b;

	if (color1 == color2)
		return (color1);
	if (percent == 0.00)
		return (color1);
	if (percent == 1.00)
		return (color2);
	r = (int)color(((color1 >> 16) & 0xFF), ((color2 >> 16) & 0xFF), percent);
	g = (int)color(((color1 >> 8) & 0xFF), ((color2 >> 8) & 0xFF), percent);
	b = (int)color((color1 & 0xFF), (color2 & 0xFF), percent);
	return (r << 16 | g << 8 | b);
}

static double	color(double start, double end, double percent)
{
	if (start == end)
		return (start);
	return (start * (1.0 - percent) + (end * percent));
}
