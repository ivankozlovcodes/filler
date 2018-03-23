/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:00:38 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/22 21:32:15 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>
#include <stdarg.h>

void	ft_log(char *msg, ...)
{
	va_list	args;
	FILE	*log_file;

	log_file = fopen("logs.txt", "a+");
	va_start(args, msg);
	vfprintf(log_file, msg, args);
	va_end(args);
	fclose(log_file);
}

void	log_matrix(t_matrix m)
{
	int		i;

	i = -1;
	ft_log("Size: r%d c%d\n", m.rows, m.cols);
	while (++i < m.rows)
		ft_log("%s\n", m.m[i]);
}
