/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 21:24:40 by vaferrei          #+#    #+#             */
/*   Updated: 2021/11/21 16:08:32 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

static void	make_points(char **split, int i, int j, t_map *map);

t_point	**init_points(t_fdf *fdf)
{
	t_point	**pts;
	int		i;
	int		j;

	pts = malloc(fdf->map->count_x * sizeof(t_point *));
	if (!pts)
		return (NULL);
	i = 0;
	while (i < fdf->map->count_x)
	{
		pts[i] = malloc(fdf->map->count_y * sizeof(t_point));
		if (!pts[i])
			return (NULL);
		j = 0;
		while (j < fdf->map->count_y)
		{
			pts[i][j].x = 0;
			pts[i][j].y = 0;
			pts[i][j].z = 0;
			pts[i][j].color = 0;
			j++;
		}
		i++;
	}
	return (pts);
}

void	get_points(char *file_name, t_map *map)
{
	char	**split;
	int		fd;
	char	*line;
	int		i;
	int		j;

	j = 0;
	fd = open(file_name, O_RDONLY, 0);
	while (1)
	{
		i = 0;
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		split = ft_split(line, ' ');
		while (i < map->count_x)
		{
			make_points(split, i, j, map);
			i++;
		}
		free(split);
		free(line);
		j++;
	}
	close(fd);
}

static void	make_points(char **split, int i, int j, t_map *map)
{
	char	**color;
	int		a;

	map->pts[i][j].x = i;
	map->pts[i][j].y = j;
	if (ft_strchr(split[i], ','))
	{
		color = ft_split(split[i], ',');
		map->pts[i][j].z = (float)ft_atoi(color[0]);
		map->pts[i][j].color = ft_atoi_base(color[1], HEX_BASE);
		a = 0;
		while (color[a])
			free(color[a++]);
		free(color);
	}
	else
		map->pts[i][j].z = (float)ft_atoi(split[i]);
	if (map->max_z < map->pts[i][j].z && map->pts[i][j].z > 0)
		map->max_z = (float)map->pts[i][j].z;
	if (map->min_z < map->pts[i][j].z && map->pts[i][j].z < 0)
		map->min_z = (float)map->pts[i][j].z;
	free(split[i]);
}

void	points_center(t_fdf *fdf)
{
	int	i;
	int	j;

	j = 0;
	while (j < fdf->map->count_y)
	{
		i = 0;
		while (i < fdf->map->count_x)
		{
			fdf->map->pts[i][j].x -= fdf->map->count_x / 2;
			fdf->map->pts[i][j].y -= fdf->map->count_y / 2;
			i++;
		}
		j++;
	}
	move_scale(fdf);
}
