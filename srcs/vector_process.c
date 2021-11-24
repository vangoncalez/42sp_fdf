/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:29:00 by vaferrei          #+#    #+#             */
/*   Updated: 2021/11/24 00:15:15 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

static void vector_plot(t_fdf *fdf);

void vector_process(t_fdf *fdf)
{
	if (fdf->view->view == 0)
	{
		clear_image(fdf->img, GREY6);
		instructions(fdf);
		fdf->view->view = 10;
	}
	else if (fdf->view->view >= 1 && fdf->view->view <= 3)
	{
		clear_image(fdf->img, GREY6);
		vector_plot(fdf);
		fdf->view->view += 10;
	}
	return;
}

static void vector_plot(t_fdf *fdf)
{
	int i;
	int count;
	int color;

	fdf->map->vectors = init_vectors(fdf);
	count = vector_count(fdf);
	if (fdf->view->colors == 1)
		color = -2;
	else
		color = -1;
	i = 0;
	while (i < count)
	{
		vector_rotate_x(fdf->map->vectors, fdf->view->angle_x, i);
		vector_rotate_y(fdf->map->vectors, fdf->view->angle_y, i);
		vector_rotate_z(fdf->map->vectors, fdf->view->angle_z, i);
		vector_view(fdf->map->vectors, i, fdf->view->view);
		vector_scale(fdf->map->vectors, fdf->view->scale, i);
		vector_move(fdf->map->vectors, fdf->view->move_x, fdf->view->move_y, i);
		plot_vector(fdf->img, fdf->map->vectors[i], color);
		i++;
	}
	free(fdf->map->vectors);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
}

void vector_scale(t_vector *vector, float scale_factor, int i)
{
	vector[i].x1 *= scale_factor;
	vector[i].y1 *= scale_factor;
	vector[i].x2 *= scale_factor;
	vector[i].y2 *= scale_factor;
}

void vector_move(t_vector *vector, int move_x, int move_y, int i)
{
	vector[i].x1 += move_x;
	vector[i].y1 += move_y;
	vector[i].x2 += move_x;
	vector[i].y2 += move_y;
}

int vector_count(t_fdf *fdf)
{
	int i;
	int j;
	int k;

	j = 0;
	k = 0;
	while (j < fdf->map->count_y)
	{
		i = 0;
		while (i < fdf->map->count_x)
		{
			if (i < fdf->map->count_x - 1)
				k++;
			if (j < fdf->map->count_y - 1)
				k++;
			i++;
		}
		j++;
	}
	return (k);
}
