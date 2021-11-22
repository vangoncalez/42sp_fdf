/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:26:37 by vaferrei          #+#    #+#             */
/*   Updated: 2021/11/14 23:12:15 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

static void	vector_view_iso(t_vector *vector, int i);
static void	vector_view_perspective(t_vector *vector, int i);

void	vector_view(t_vector *vector, int i, int view)
{
	if (view == 1)
		vector_view_iso(vector, i);
	if (view == 2)
		vector_view_perspective(vector, i);
}

static void	vector_view_iso(t_vector *vector, int i)
{
	t_vector	old;

	old.x1 = vector[i].x1;
	old.x2 = vector[i].x2;
	old.y1 = vector[i].y1;
	old.y2 = vector[i].y2;
	old.z1 = vector[i].z1;
	old.z2 = vector[i].z2;
	vector[i].x1 = (old.x1 - old.y1) * cos(ANG_30);
	vector[i].y1 = (old.x1 + old.y1) * sin(ANG_30) - old.z1;
	vector[i].x2 = (old.x2 - old.y2) * cos(ANG_30);
	vector[i].y2 = (old.x2 + old.y2) * sin(ANG_30) - old.z2;
}

static void	vector_view_perspective(t_vector *vector, int i)
{
	t_vector	new;
	float		z;

	vector_rotate_x(vector, 3 * -ANG_45, i);
	z = vector[i].z1 + vector[i].z_pptve;
	new.x1 = vector[i].x1 / z;
	new.y1 = vector[i].y1 / z;
	vector[i].x1 = new.x1;
	vector[i].y1 = -new.y1;
	z = vector[i].z2 + vector[i].z_pptve;
	new.x2 = vector[i].x2 / z;
	new.y2 = vector[i].y2 / z;
	vector[i].x2 = new.x2;
	vector[i].y2 = -new.y2;
	vector_scale(vector, vector[i].z_pptve, i);
}
