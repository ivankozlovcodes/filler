/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:00:38 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/25 14:48:32 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>
#include <stdarg.h>

void	ft_log(char *msg, ...)
{
	va_list	args;
	FILE	*log_file;

	if (DEBUG != 0)
	{
		log_file = fopen("logs.txt", "a+");
		va_start(args, msg);
		vfprintf(log_file, msg, args);
		va_end(args);
		fclose(log_file);
	}
}

void	log_matrix(t_matrix m)
{
	int		i;

	i = -1;
	ft_log("Size: r%d c%d\n", m.rows, m.cols);
	while (++i < m.rows)
		ft_log("%s\n", m.m[i]);
}

void	log_critical_points(t_point *p)
{
	int		i;

	i = -1;
	ft_log("Critical points\n");
	while (++i < C_POINTS)
	{
		ft_log("[%d, %d]\n", p[i].x, p[i].y);
		ft_log("%c: %d\t\t", PLAYER1, p[i].distances[0]);
		ft_log("%c: %d\n", PLAYER2, p[i].distances[1]);
	}
}

void	log_fitness_matrix(int **m, int rows, int cols)
{
	int		i;
	int		j;

	i = -1;
	while (++i < rows)
	{
		j = -1;
		while (++j < cols)
			ft_log("%3d ", m[i][j]);
		ft_log(NEW_LINE);
	}
}
