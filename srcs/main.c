/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:20:52 by vaferrei          #+#    #+#             */
/*   Updated: 2021/11/23 23:55:45 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

static void	check_input(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	check_input(argc, argv);
	fdf = init_fdf();
	fdf->map = init_map(argv[1]);
	if (!fdf->map)
		free_error(fdf, 4);
	fdf->map->pts = init_points(fdf);
	if (!fdf->map->pts)
		free_error(fdf, 5);
	get_points(argv[1], fdf->map);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, W_WIDTH, W_HEIGHT, W_TITLE);
	fdf->img = init_img(fdf);
	if (!fdf->img)
		free_error(fdf, 6);
	fdf->view = init_view();
	if (!fdf->view)
		free_error(fdf, 7);
	points_center(fdf);
	vector_process(fdf);
	mlx_key_hook(fdf->win, key_hook, fdf);
	mlx_expose_hook(fdf->win, expose_hook, fdf);
	mlx_loop(fdf->mlx);
}

static void	check_input(int argc, char **argv)
{
	char	*result;
	char	*extension;
	int		fd;

	extension = ".fdf";
	if (argc != 2)
		error_exit(1);
	result = ft_strchr(argv[1], '.');
	extension = ft_strdup(".fdf");
	if (ft_strncmp(result, extension, 5) != 0)
	{
		free(extension);
		error_exit(2);
	}
	free(extension);
	fd = open(argv[1], O_RDONLY);
	close(fd);
	if (fd == -1)
		error_exit(3);
}

int	expose_hook(t_fdf *fdf)
{
	vector_process(fdf);
	return (0);
}
