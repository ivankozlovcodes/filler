/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 19:19:06 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/23 15:10:52 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <limits.h>

void	send_move(int row, int column)
{
	ft_log("Placing a piece at %d %d\n", row, column);
	ft_putnbr(row);
	write(STDOUT_FILENO, SPACE, 1);
	ft_putnbr(column);
	write(STDOUT_FILENO, NEW_LINE, 1);
}

int		**build_fitness_matrix(t_game *game, t_point p)
{
	int		**res;
	int		i;
	int		j;

	res = malloc(sizeof(int *) * game->map.rows);
	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		res[i] = malloc(sizeof(int) * game->map.cols);
		while (++j < game->map.cols)
			res[i][j] = 100 - ABS(p.x - j) - ABS(p.y - i);
	}
	return (res);
}

int		gameon(t_game *game)
{
	t_point	*p;
	t_point	critical;
	int		**fitness;

	while (1)
	{
		get_data(game);
		ft_log("Got data\n");
		log_matrix(game->map);
		log_matrix(game->piece.field);
		p = get_critical_points(*game);
		log_critical_points(p);
		critical = get_main_critical_point(p);
		fitness = build_fitness_matrix(game, critical);
		log_fitness_matrix(fitness, game->map.rows, game->map.cols);
		// build fitness matrix
		// make a move
		free(p);
	}
	return (0);
}
