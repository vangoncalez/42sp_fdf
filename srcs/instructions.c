/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:40:14 by vaferrei          #+#    #+#             */
/*   Updated: 2021/11/21 19:45:49 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

static void	draw_arrows(t_img *img);
static void	write_instructions_a(t_fdf *fdf);
static void	write_instructions_b(t_fdf *fdf);

void	instructions(t_fdf *fdf)
{
	clear_image(fdf->img, GREY6);
	rectangle(fdf->img, get_plot_vector(400, 180, 400, 60), GREEN3);
	rectangle(fdf->img, get_plot_vector(400, 260, 120, 120), GREY4);
	rectangle(fdf->img, get_plot_vector(400, 400, 120, 120), GREY4);
	rectangle(fdf->img, get_plot_vector(400, 539, 120, 120), GREY4);
	rectangle(fdf->img, get_plot_vector(400, 679, 400, 60), PINK3);
	rectangle(fdf->img, get_plot_vector(540, 260, 120, 120), GREY4);
	rectangle(fdf->img, get_plot_vector(540, 400, 120, 120), GREY4);
	rectangle(fdf->img, get_plot_vector(540, 539, 120, 120), GREY4);
	rectangle(fdf->img, get_plot_vector(680, 260, 120, 120), GREY4);
	rectangle(fdf->img, get_plot_vector(680, 400, 120, 258), GREY4);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
	draw_arrows(fdf->img);
	mlx_string_put(fdf->mlx, fdf->win, 528, 213, C_WHITE, \
			"Press TAB to start");
	mlx_string_put(fdf->mlx, fdf->win, 434, 712, C_WHITE, \
			"Press F1 anytime for these instructions or ESC to escape");
	mlx_string_put(fdf->mlx, fdf->win, 639, 760, PINK1, "by Vanessa Goncalez");
	write_instructions_a(fdf);
	write_instructions_b(fdf);
}

static void	draw_arrows(t_img *img)
{
	plot_vector(img, get_plot_vector(460, 450, 460, 460), ORANGE);
	plot_vector(img, get_plot_vector(460, 480, 460, 490), ORANGE);
	plot_vector(img, get_plot_vector(440, 470, 450, 470), ORANGE);
	plot_vector(img, get_plot_vector(470, 470, 480, 470), ORANGE);
	plot_vector(img, get_plot_vector(460, 450, 455, 455), ORANGE);
	plot_vector(img, get_plot_vector(460, 450, 465, 455), ORANGE);
	plot_vector(img, get_plot_vector(480, 470, 475, 465), ORANGE);
	plot_vector(img, get_plot_vector(480, 470, 475, 475), ORANGE);
	plot_vector(img, get_plot_vector(460, 490, 455, 485), ORANGE);
	plot_vector(img, get_plot_vector(460, 490, 465, 485), ORANGE);
	plot_vector(img, get_plot_vector(440, 470, 445, 465), ORANGE);
	plot_vector(img, get_plot_vector(440, 470, 445, 475), ORANGE);
}

static void	write_instructions_a(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 440, 284, GREEN1, "Rotate X");
	mlx_string_put(fdf->mlx, fdf->win, 578, 284, GREEN1, "Rotate Y");
	mlx_string_put(fdf->mlx, fdf->win, 717, 284, GREEN1, "Rotate Z");
	mlx_string_put(fdf->mlx, fdf->win, 450, 424, GREEN1, "Move");
	mlx_string_put(fdf->mlx, fdf->win, 586, 424, GREEN1, "Scale");
	mlx_string_put(fdf->mlx, fdf->win, 710, 424, GREEN1, "Projection");
	mlx_string_put(fdf->mlx, fdf->win, 426, 563, GREEN1, "Scale to fit");
	mlx_string_put(fdf->mlx, fdf->win, 576, 563, GREEN1, "Z Scale");
}

static void	write_instructions_b(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 445, 324, ORANGE, "\"W\"  +");
	mlx_string_put(fdf->mlx, fdf->win, 445, 344, ORANGE, "\"S\"  -");
	mlx_string_put(fdf->mlx, fdf->win, 583, 324, ORANGE, "\"Q\"  +");
	mlx_string_put(fdf->mlx, fdf->win, 583, 344, ORANGE, "\"E\"  -");
	mlx_string_put(fdf->mlx, fdf->win, 722, 324, ORANGE, "\"A\"  +");
	mlx_string_put(fdf->mlx, fdf->win, 722, 344, ORANGE, "\"D\"  -");
	mlx_string_put(fdf->mlx, fdf->win, 565, 464, ORANGE, "\"+\"  Zoom+");
	mlx_string_put(fdf->mlx, fdf->win, 565, 484, ORANGE, "\"-\"  Zoom-");
	mlx_string_put(fdf->mlx, fdf->win, 729, 464, ORANGE, "\"T\"");
	mlx_string_put(fdf->mlx, fdf->win, 729, 484, ORANGE, "TOP");
	mlx_string_put(fdf->mlx, fdf->win, 729, 524, ORANGE, "\"I\"");
	mlx_string_put(fdf->mlx, fdf->win, 710, 544, ORANGE, "ISOMETRIC");
	mlx_string_put(fdf->mlx, fdf->win, 729, 584, ORANGE, "\"P\"");
	mlx_string_put(fdf->mlx, fdf->win, 705, 604, ORANGE, "PERSPECTIVE");
	mlx_string_put(fdf->mlx, fdf->win, 450, 602, ORANGE, "Space");
	mlx_string_put(fdf->mlx, fdf->win, 570, 598, ORANGE, "\"L\"  Lower");
	mlx_string_put(fdf->mlx, fdf->win, 570, 618, ORANGE, "\"H\"  Higher");
	mlx_string_put(fdf->mlx, fdf->win, 570, 642, ORANGE, "Limit 200%");
}
