/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 08:35:15 by vaferrei          #+#    #+#             */
/*   Updated: 2021/11/26 08:37:06 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_plot {
	float	x;
	float	y;
	float	z;
	float	xi;
	float	yi;
	float	delta_x;
	float	delta_y;
	float	error_xy;
}				t_plot;

typedef struct s_point {
	float	x;
	float	y;
	float	z;
	int		color;
}				t_point;

typedef struct s_vector {
	float	x1;
	float	y1;
	float	z1;
	int		color1;
	float	x2;
	float	y2;
	float	z2;
	int		color2;
	float	z_pptve;
}				t_vector;

typedef struct s_view
{
	int		colors;
	int		view;
	float	scale;
	float	scale_z;
	float	move_x;
	float	move_y;
	float	angle_x;
	float	angle_y;
	float	angle_z;
}	t_view;

typedef struct s_map
{
	int			count_x;
	int			count_y;
	float		min_z;
	float		max_z;
	t_point		**pts;
	t_vector	*vectors;
}				t_map;

typedef struct s_img {
	void	*img;
	char	*mem;
	int		bits_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_fdf {
	void		*mlx;
	void		*win;
	t_img		*img;
	t_map		*map;
	t_view		*view;
	int			actual_k;
}				t_fdf;

#endif
