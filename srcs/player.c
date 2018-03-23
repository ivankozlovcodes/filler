/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 19:19:06 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/23 15:37:19 by ikozlov          ###   ########.fr       */
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
	char	c;
	int		i;
	int		j;

	res = malloc(sizeof(int *) * game->map.rows);
	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		res[i] = malloc(sizeof(int) * game->map.cols);
		while (++j < game->map.cols)
		{
			c = ft_tolower(game->map.m[i][j]);
			if (c == game->player)
				res[i][j] = 0;
			else if (c == game->opponent)
				res[i][j] = -FITNESS_MAX;
			else
				res[i][j] = FITNESS_MAX - ABS(p.x - j) - ABS(p.y - i);
		}
	}
	return (res);
}

int		get_sum(int **fitness, t_piece p, int row, int col)
{
	fitness++;
	p.field.cols++;
	row += col;
	return (0);
}

int		*get_move(t_game *game, int **fitness)
{
	int		i;
	int		j;
	int		sum;
	int		tmp;
	int		*res;

	i = -1;
	res = malloc(sizeof(int) * 2);
	sum = 0;
	res[0] = 0;
	res[1] = 0;
	while (++i < game->rows)
	{
		j = -1;
		while (++j < game->cols)
			if ((tmp = get_sum(fitness, game->piece, i, j) > sum))
			{
				res[0] = i;
				res[1] = j;
				sum = tmp;
			}
	}
	return (res);
}

int		gameon(t_game *game)
{
	t_point	*p;
	t_point	critical;
	int		**fitness;
	int		*move;

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
		move = get_move(game, fitness);
		send_move(move[0], move[1]);
		// free(all fitness)
		free(move);
		free(p);
	}
	return (0);
}
