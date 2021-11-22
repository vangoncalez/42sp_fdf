/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:20:52 by vaferrei          #+#    #+#             */
/*   Updated: 2021/11/21 16:39:27 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

static void	init_map_vars(t_map *map);

t_fdf	*init_fdf(void)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		error_exit(4);
	fdf->img = NULL;
	fdf->map = NULL;
	fdf->view = NULL;
	fdf->mlx = NULL;
	fdf->win = NULL;
	fdf->actual_k = 0;
	return (fdf);
}

t_map	*init_map(char *file_map)
{
	t_map	*map;
	int		fd;
	char	*line;
	int		count_x;

	count_x = 0;
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	init_map_vars(map);
	fd = open(file_map, O_RDONLY, 0);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count_x = (int)ft_countwords(line, ' ');
		map->count_y++;
		free(line);
		map->count_x = count_x;
	}
	close(fd);
	return (map);
}

static void	init_map_vars(t_map *map)
{
	map->count_x = 0;
	map->count_y = 0;
	map->max_z = 0;
	map->min_z = 0;
	map->pts = NULL;
	map->vectors = NULL;
}

t_view	*init_view(void)
{
	t_view	*view;

	view = malloc(sizeof(t_view));
	if (!view)
		return (NULL);
	view->colors = 0;
	view->view = 0;
	view->scale_z = 1;
	view->scale = 1;
	view->move_x = 0;
	view->move_y = 0;
	view->angle_x = 0;
	view->angle_y = 0;
	view->angle_z = 0;
	return (view);
}

t_img	*init_img(t_fdf *fdf)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->img = mlx_new_image(fdf->mlx, W_WIDTH, W_HEIGHT);
	img->mem = mlx_get_data_addr(img->img, &img->bits_pixel, \
		&img->line_length, &img->endian);
	img->bits_pixel /= 8;
	return (img);
}
