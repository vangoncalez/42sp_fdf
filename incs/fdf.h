/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:39:18 by vaferrei          #+#    #+#             */
/*   Updated: 2021/11/23 23:51:56 by vaferrei         ###   ########.fr       */
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

////apagar
# include <stdio.h>
////apagar

typedef struct	s_plot {
	float	x;
	float	y;
	float	xi;
	float	yi;
	float	delta_x;
	float	delta_y;
	float	error_xy;
}				t_plot;

/////apagar

typedef struct	s_point {
	float	x;
	float	y;
	float	z;
	int		color;
}				t_point;

typedef struct	s_vector {
	float	x1;
	float	y1;
	float	z1; //nao usa para imprimir
	int		color1;
	float	x2;
	float	y2;
	float	z2; //nao usa para imprimir
	int		color2;
	float	z_pptve;
}				t_vector;

typedef struct s_view
{
	int		colors; //se ativar a letra c
	int		view; //0: nada 1: iso, 2: perspective, 3: top
	float	scale;
	float	scale_z;
	float	move_x;
	float	move_y;
	float	angle_x;
	float	angle_y;
	float	angle_z;
}	t_view;

typedef struct	s_map
{
	int			count_x;
	int			count_y;
	float		min_z;
	float		max_z;
	t_point		**pts;
	t_vector 	*vectors;
}				t_map;

typedef struct	s_img {
	void	*img;
	char	*mem;
	int		bits_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_fdf {
	void		*mlx;
	void		*win;
	t_img		*img;
	t_map		*map;
	t_view		*view;
	// t_vector	plot;
	int			actual_k;
}				t_fdf;

//error_exit
void		error_exit (int error);
void		success_exit (int success);
// void		error (int error);

//free
void free_error(t_fdf *fdf, int local);
void free_success(t_fdf *fdf, int local);

//init
t_fdf		*init_fdf(void);
t_view		*init_view(void);
t_map		*init_map(char *file_map);
t_point 	**init_points(t_fdf *fdf);
t_vector	*init_vectors(t_fdf *fdf);
t_img		*init_img(t_fdf *fdf);

//instructions
void		instructions(t_fdf *fdf);

///keycode
int			key_hook(int keycode, t_fdf *fdf);
int			expose_hook(t_fdf *fdf);


int			get_color(t_vector vector, double x, double y);
//main

////plot
// void	plotVectorLow(t_img *img, int x0, int y0, int x1, int y1, int color);
// void	plotVectorHigh(t_img *img, int x0, int y0, int x1, int y1, int color);
// void	plotVector(t_img *img, int x0, int y0, int x1, int y1, int color);
void	clear_image(t_img *img, int color);
void	pixel_to_image(t_img *img, float x, float y, int color);
void	rectangle(t_img *img, t_vector vector, int color);
void	plot_vector(t_img *img, t_vector vector, int color);
t_vector get_new_vector(float x1, float y1, float x2, float y2);
t_vector	get_new_color(t_vector	 vector, int color1, int color2);

//utils
float	ft_abs(float number);
float	max_value(float number1, float number2);
float	min_value(float number1, float number2);
void	points_center(t_fdf *fdf);
void	move_scale(t_fdf *fdf);
int		idx(int row, int col, int dim);

//vector_process
void	get_points(char *file_name, t_map *map);
void	vector_process(t_fdf *fdf);
void	vector_scale(t_vector *vector, float scale_factor, int i);
void	vector_move(t_vector *vector, int move_x, int move_y, int i);
int		vector_count(t_fdf *fdf);

//vector_rotate
void	vector_rotate_x(t_vector *vector, float angle, int i);
void	vector_rotate_y(t_vector *vector, float angle, int i);
void	vector_rotate_z(t_vector *vector, float angle, int i);

//vector_view
void	vector_view(t_vector *vector, int i, int view);

#endif



