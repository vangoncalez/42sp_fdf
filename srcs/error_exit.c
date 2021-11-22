/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:10:47 by vaferrei          #+#    #+#             */
/*   Updated: 2021/11/14 20:32:03 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	error_exit(int error)
{
	if (error == 1)
	{
		ft_putstr_fd("\033[31;1m\n   You need to insert: \033[0m\n", 1);
		ft_putstr_fd("\033[33;1m   ./fdf maps/<map_name>.fdf\033[0m\n\n", 1);
	}
	else if (error == 2)
		ft_putstr_fd("\033[31;1m\n   Wrong File Extension!\033[0m\n\n", 1);
	else if (error == 3)
	{
		ft_putstr_fd("\033[31;1m\n   File Problems!\033[0m\n", 1);
		ft_putstr_fd("\033[33;1m\n   Check the filename\033[0m\n\n", 1);
	}
	else if (error == 4)
		ft_putstr_fd("\033[32;1m\n   Cannot initialize fdf!!\033[0m\n\n", 1);
	else if (error == 5)
		ft_putstr_fd("\033[32;1m\n   Cannot initialize Map!!\033[0m\n\n", 1);
	else if (error == 6)
		ft_putstr_fd("\033[32;1m\n   Cannot initialize Img!!\033[0m\n\n", 1);
	else if (error == 7)
		ft_putstr_fd("\033[32;1m\n   Problemas with FDF!!\033[0m\n\n", 1);
	exit (1);
}

void	success_exit(int success)
{
	if (success == 10)
		ft_putstr_fd("\033[32;1m\n   FdF closed successfully!!\033[0m\n\n", 1);
	exit (0);
}
