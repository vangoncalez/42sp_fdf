/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:10:50 by vaferrei          #+#    #+#             */
/*   Updated: 2021/11/14 21:27:11 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

static void	free_points(t_point **pts, int width);
static void	free_img(t_fdf *fdf);
static void	free_all(t_fdf *fdf);

void	free_error(t_fdf *fdf, int local)
{
	if (local == 4)
		free(fdf);
	else if (local == 5)
		free(fdf->map);
	else if (local == 6)
		free_img(fdf);
	else if (local == 7)
		free_all(fdf);
	error_exit (local);
}

void	free_success(t_fdf *fdf, int local)
{
	if (local == 10)
		free_all(fdf);
	success_exit (local);
}

static void	free_img(t_fdf *fdf)
{
	free_points (fdf->map->pts, fdf->map->count_x);
	free(fdf->map);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf);
	error_exit (6);
}

static void	free_points(t_point **pts, int count_x)
{
	int		i;

	i = 0;
	while (i < count_x)
	{
		if (pts[i])
		{
			free(pts[i]);
			i++;
		}
	}
	free(pts);
	return ;
}

static void	free_all(t_fdf *fdf)
{
	free(fdf->view);
	mlx_destroy_image(fdf->mlx, fdf->img->img);
	free(fdf->img);
	free_points (fdf->map->pts, fdf->map->count_x);
	free(fdf->map);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	free(fdf);
}
