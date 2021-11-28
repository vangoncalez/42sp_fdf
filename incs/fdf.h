/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:39:18 by vaferrei          #+#    #+#             */
/*   Updated: 2021/11/26 23:16:54 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../libs/libft/libft.h"
# include "../libs/mlx_linux/mlx.h"
# include "macro.h"
# include "structs.h"
# include <stdio.h>

void		clear_image(t_img *img, int color);
int			get_color(t_vector vector, double x, double y);
void		make_pallet(t_vector *vector, t_fdf *fdf, int color, int i);
void		error_exit(int error);
void		success_exit(int success);
void		free_error(t_fdf *fdf, int local);
void		free_success(t_fdf *fdf, int local);
t_fdf		*init_fdf(void);
t_map		*init_map(char *file_map);
t_view		*init_view(void);
t_img		*init_img(t_fdf *fdf);
void		instructions(t_fdf *fdf);
int			key_hook(int keycode, t_fdf *fdf);
int			expose_hook(t_fdf *fdf);
void		rectangle(t_fdf *fdf, t_vector vector, int color);
t_vector	get_new_vector(float x1, float y1, float x2, float y2);
t_vector	get_new_color(t_vector vector, int color1, int color2);
void		pixel_to_image(t_img *img, float x, float y, int color);
double		get_percent(double start, double end, double search);
void		plot_vector(t_fdf *fdf, t_vector vector, int color);
t_vector	make_new_vector(t_vector vector, int side);
t_point		**init_points(t_fdf *fdf);
void		get_points(char *file_name, t_map *map);
void		points_center(t_fdf *fdf);
float		ft_abs(float number);
float		max_value(float number1, float number2);
float		min_value(float number1, float number2);
void		move_scale(t_fdf *fdf);
int			idx(int row, int col, int dim);
void		vector_process(t_fdf *fdf);
void		vector_scale(t_vector *vector, float scale_factor, int i);
void		vector_move(t_vector *vector, int move_x, int move_y, int i);
int			vector_count(t_fdf *fdf);
void		vector_rotate_x(t_vector *vector, float angle, int i);
void		vector_rotate_y(t_vector *vector, float angle, int i);
void		vector_rotate_z(t_vector *vector, float angle, int i);
void		vector_view(t_vector *vector, int i, int view);
t_vector	*init_vectors(t_fdf *fdf);

#endif
