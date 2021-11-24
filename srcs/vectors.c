/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 21:49:40 by vaferrei          #+#    #+#             */
/*   Updated: 2021/11/22 21:14:53 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

static t_vector	init_vectors_x(t_fdf *fdf, t_vector vector, int i, int j);
static t_vector	init_vectors_y(t_fdf *fdf, t_vector vector, int i, int j);
static t_vector	*init_vectors_iteration(t_fdf *fdf, t_vector *vector, int j);

t_vector	*init_vectors(t_fdf *fdf)
{
	t_vector	*vector;
	int			j;
	int			k;
	int			count;

	j = 0;
	k = 0;
	fdf->actual_k = 0;
	count = vector_count(fdf);
	vector = (t_vector *)malloc(sizeof(t_vector) * count + 1);
	if (!vector)
		return (NULL);
	while (j < fdf->map->count_y)
	{
		vector = init_vectors_iteration(fdf, vector, j);
		j++;
	}
	return (vector);
}

static t_vector	init_vectors_x(t_fdf *fdf, t_vector vector, int i, int j)
{
	vector.x1 = fdf->map->pts[i][j].x;
	vector.y1 = fdf->map->pts[i][j].y;
	vector.z1 = fdf->map->pts[i][j].z * fdf->view->scale_z;
	vector.color1 = fdf->map->pts[i][j].color;
	vector.x2 = fdf->map->pts[i + 1][j].x;
	vector.y2 = fdf->map->pts[i + 1][j].y;
	vector.z2 = fdf->map->pts[i + 1][j].z * fdf->view->scale_z;
	vector.color2 = fdf->map->pts[i + 1][j].color;
	vector.z_pptve = max_value((fdf->map->max_z - fdf->map->min_z), \
	   max_value(fdf->map->count_x, fdf->map->count_y));
	return (vector);
}

static t_vector	init_vectors_y(t_fdf *fdf, t_vector vector, int i, int j)
{
	vector.x1 = fdf->map->pts[i][j].x;
	vector.y1 = fdf->map->pts[i][j].y;
	vector.z1 = fdf->map->pts[i][j].z * fdf->view->scale_z;
	vector.color1 = fdf->map->pts[i][j].color;
	vector.x2 = fdf->map->pts[i][j + 1].x;
	vector.y2 = fdf->map->pts[i][j + 1].y;
	vector.z2 = fdf->map->pts[i][j + 1].z * fdf->view->scale_z;
	vector.color2 = fdf->map->pts[i][j + 1].color;
	vector.z_pptve = max_value((fdf->map->max_z - fdf->map->min_z), \
	   max_value(fdf->map->count_x, fdf->map->count_y));
	return (vector);
}

static t_vector	*init_vectors_iteration(t_fdf *fdf, t_vector *vector, int j)
{
	int	i;
	int	k;

	i = 0;
	k = fdf->actual_k;
	while (i < fdf->map->count_x)
	{
		if (i < fdf->map->count_x - 1)
		{
			vector[k] = init_vectors_x(fdf, vector[k], i, j);
			k++;
		}
		if (j < fdf->map->count_y - 1)
		{
			vector[k] = init_vectors_y(fdf, vector[k], i, j);
			k++;
		}
		i++;
	}
	fdf->actual_k = k;
	return (vector);
}