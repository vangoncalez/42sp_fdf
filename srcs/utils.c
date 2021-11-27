/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:39:11 by vaferrei          #+#    #+#             */
/*   Updated: 2021/11/26 23:05:49 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

float	ft_abs(float number)
{
	if (number < 0)
		return (-number);
	else
		return (number);
}

float	max_value(float number1, float number2)
{
	if (number1 > number2)
		return (number1);
	else
		return (number2);
}

float	min_value(float number1, float number2)
{
	if (number1 < number2)
		return (number1);
	else
		return (number2);
}

void	move_scale(t_fdf *fdf)
{
	float	max_x;
	float	max_y;
	float	max_z;
	float	delta_z;
	float	gama_z;

	if (fdf->view->view == 3)
	{
		max_x = (W_WIDTH - P_HORIZONTAL * 2) / (float)fdf->map->count_x;
		max_y = (W_HEIGHT - P_VERTICAL * 2) / (float)fdf->map->count_y;
		fdf->view->scale = min_value(max_x, max_y);
		fdf->view->move_x = W_WIDTH / 2;
		fdf->view->move_y = W_HEIGHT / 2;
	}
	else
	{
		delta_z = fdf->map->max_z - fdf->map->min_z;
		gama_z = fdf->map->max_z + fdf->map->min_z;
		max_x = (W_WIDTH) / (float)fdf->map->count_x;
		max_y = (W_HEIGHT) / (float)fdf->map->count_y;
		max_z = (W_HEIGHT) / delta_z;
		fdf->view->scale = min_value(min_value(max_x, max_y), max_z) / 2;
		fdf->view->move_x = W_WIDTH / 2;
		fdf->view->move_y = (W_HEIGHT / 2) + ((gama_z * fdf->view->scale) / 2);
	}
}

int	idx(int row, int col, int dim)
{
	return (row * dim + col);
}
