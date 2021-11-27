/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:26:45 by vaferrei          #+#    #+#             */
/*   Updated: 2021/11/26 22:42:28 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	vector_rotate_x(t_vector *vector, float angle, int i)
{
	t_vector	new;

	new.y1 = vector[i].y1 * cos(angle) - vector[i].z1 * sin(angle);
	new.z1 = vector[i].y1 * sin(angle) + vector[i].z1 * cos(angle);
	vector[i].y1 = new.y1;
	vector[i].z1 = new.z1;
	new.y2 = vector[i].y2 * cos(angle) - vector[i].z2 * sin(angle);
	new.z2 = vector[i].y2 * sin(angle) + vector[i].z2 * cos(angle);
	vector[i].y2 = new.y2;
	vector[i].z2 = new.z2;
}

void	vector_rotate_y(t_vector *vector, float angle, int i)
{
	t_vector	new;

	new.x1 = vector[i].x1 * cos(angle) + vector[i].z1 * sin(angle);
	new.z1 = -vector[i].x1 * sin(angle) + vector[i].z1 * cos(angle);
	vector[i].x1 = new.x1;
	vector[i].z1 = new.z1;
	new.x2 = vector[i].x2 * cos(angle) + vector[i].z2 * sin(angle);
	new.z2 = -vector[i].x2 * sin(angle) + vector[i].z2 * cos(angle);
	vector[i].x2 = new.x2;
	vector[i].z2 = new.z2;
}

void	vector_rotate_z(t_vector *vector, float angle, int i)
{
	t_vector	new;

	new.x1 = vector[i].x1 * cos(angle) - vector[i].y1 * sin(angle);
	new.y1 = vector[i].x1 * sin(angle) + vector[i].y1 * cos(angle);
	vector[i].x1 = new.x1;
	vector[i].y1 = new.y1;
	new.x2 = vector[i].x2 * cos(angle) - vector[i].y2 * sin(angle);
	new.y2 = vector[i].x2 * sin(angle) + vector[i].y2 * cos(angle);
	vector[i].x2 = new.x2;
	vector[i].y2 = new.y2;
}
