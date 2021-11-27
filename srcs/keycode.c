/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:39:07 by vaferrei          #+#    #+#             */
/*   Updated: 2021/11/26 22:45:26 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

static int	kc_move(int keycode, t_fdf *fdf);
static int	kc_rotate(int keycode, t_fdf *fdf);
static int	kc_zoom_scale(int keycode, t_fdf *fdf);
static int	kc_project(int keycode, t_fdf *fdf);

static int	kc_project(int keycode, t_fdf *fdf)
{
	if (keycode == K_T && fdf->view->view != 0)
	{
		fdf->view->view = 3;
		fdf->view->angle_x = 0;
		fdf->view->angle_y = 0;
	}
	if (keycode == K_I && fdf->view->view != 0)
		fdf->view->view = 1;
	if (keycode == K_P && fdf->view->view != 0)
		fdf->view->view = 2;
	if (keycode == K_C)
	{
		if (fdf->view->colors == 0)
			fdf->view->colors = 1;
		else
			fdf->view->colors = 0;
		fdf->view->view -= 10;
	}
	return (0);
}

static int	kc_move(int keycode, t_fdf *fdf)
{
	if (keycode == K_LEFT)
		fdf->view->move_x -= 20;
	if (keycode == K_RIGHT)
		fdf->view->move_x += 20;
	if (keycode == K_TOP)
		fdf->view->move_y -= 20;
	if (keycode == K_BOTTOM)
		fdf->view->move_y += 20;
	fdf->view->view -= 10;
	return (0);
}

static int	kc_rotate(int keycode, t_fdf *fdf)
{
	if (keycode == K_A)
		fdf->view->angle_z += (5 * ANG_1);
	if (keycode == K_D)
		fdf->view->angle_z -= (5 * ANG_1);
	if (keycode == K_W)
		fdf->view->angle_x += (5 * ANG_1);
	if (keycode == K_S)
		fdf->view->angle_x -= (5 * ANG_1);
	if (keycode == K_Q)
		fdf->view->angle_y += (5 * ANG_1);
	if (keycode == K_E)
		fdf->view->angle_y -= (5 * ANG_1);
	fdf->view->view -= 10;
	return (0);
}

static int	kc_zoom_scale(int keycode, t_fdf *fdf)
{
	if (keycode == K_PLUS)
		fdf->view->scale += 1;
	if (keycode == K_MINUS)
		fdf->view->scale -= 1;
	if (keycode == K_L && fdf->view->scale_z > -3)
	{
		fdf->map->min_z = fdf->map->min_z / fdf->view->scale_z;
		fdf->map->max_z = fdf->map->max_z / fdf->view->scale_z;
		fdf->view->scale_z -= 0.1;
		fdf->map->min_z = fdf->map->min_z * fdf->view->scale_z;
		fdf->map->max_z = fdf->map->max_z * fdf->view->scale_z;
	}
	if (keycode == K_H && fdf->view->scale_z < 3)
	{
		fdf->map->min_z = fdf->map->min_z / fdf->view->scale_z;
		fdf->map->max_z = fdf->map->max_z / fdf->view->scale_z;
		fdf->view->scale_z += 0.1;
		fdf->map->min_z = fdf->map->min_z * fdf->view->scale_z;
		fdf->map->max_z = fdf->map->max_z * fdf->view->scale_z;
	}
	fdf->view->view -= 10;
	return (0);
}

int	key_hook(int keycode, t_fdf *fdf)
{
	int	kc;

	kc = keycode;
	if (fdf->view->view == 10 && keycode != TAB && keycode != ESC)
		return (0);
	if (keycode == ESC)
		free_success(fdf, 10);
	if (keycode == K_F1)
		fdf->view->view = 0;
	if (kc == K_LEFT || kc == K_RIGHT || kc == K_TOP || kc == K_BOTTOM)
		kc_move(keycode, fdf);
	if (kc == K_A || kc == K_D || kc == K_W || kc == K_S || kc == K_Q || \
			kc == K_E || kc == K_SPACE)
		kc_rotate(keycode, fdf);
	if (kc == K_PLUS || kc == K_MINUS || kc == K_L || kc == K_H \
			|| kc == K_I || kc == K_P)
		kc_zoom_scale(keycode, fdf);
	if (kc == K_T || kc == K_I || kc == K_P || kc == K_C)
		kc_project(keycode, fdf);
	if (keycode == TAB)
		fdf->view->view = 1;
	vector_process(fdf);
	return (0);
}
