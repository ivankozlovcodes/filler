/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 19:19:06 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/23 19:30:13 by ikozlov          ###   ########.fr       */
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

void	build_fitness_matrix(t_game *game, t_point p)
{
	int		**res;
	char	c;
	int		i;
	int		j;

	game->fitness.rows = game->map.rows + game->piece.field.rows * 2;
	game->fitness.cols = game->map.cols + game->piece.field.cols * 2;
	res = malloc(sizeof(int *) * game->fitness.rows);
	i = -1;
	while (++i < game->fitness.rows)
	{
		j = -1;
		res[i] = malloc(sizeof(int) * game->fitness.cols);
		while (++j < game->fitness.cols)
		{
			if (i >= game->piece.field.rows && j >= game->piece.field.cols
				&& i < game->piece.field.rows + game->map.rows && j < game->piece.field.cols + game->map.cols)
				c = ft_tolower(((char **)game->map.m)\
					[i - game->piece.field.rows][j - game->piece.field.cols]);
			else
				c = game->opponent;
			if (c == game->player)
				res[i][j] = 0;
			else if (c == game->opponent)
				res[i][j] = -FITNESS_MAX;
			else
				res[i][j] = FITNESS_MAX - ABS(game->piece.field.cols + p.x - j) - ABS(game->piece.field.rows + p.y - i);
		}
	}
	game->fitness.m = (void **)res;
}

int		get_sum(int **fitness, t_piece p, int row, int col)
{
	int		i;
	int		j;
	int		hit_self;
	int		sum;

	i = -1;
	sum = 0;
	hit_self = 0;
	while (++i < p.field.rows)
	{
		j = -1;
		while (++j < p.field.cols)
			if (((char **)p.field.m)[i][j] == '*')
			{
				if (fitness[p.field.rows + row + i][p.field.cols + col + j] == 0)
					hit_self++;
				sum += fitness[p.field.rows + row + i][p.field.cols + col + j];
			}
	}
	if (hit_self != 1)
		sum = 0;
	return (sum);
}

int		*get_move(t_game *game)
{
	int		i;
	int		j;
	int		sum;
	int		tmp;
	int		*res;

	i = -1;
	res = (int *)ft_memalloc(2);
	sum = 0;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.cols)
		{
			tmp = get_sum((int **)game->fitness.m, game->piece, i, j);
			// ft_log("%d %d sum %d\n", i, j, tmp);
			if (tmp > sum)
			{
				res[0] = i;
				res[1] = j;
				sum = tmp;
			}
		}
	}
	return (res);
}

int		gameon(t_game *game)
{
	t_point	*p;
	t_point	critical;
	int		*move;
	int		i;

	get_data(game);
	p = get_critical_points(*game);
	critical = get_main_critical_point(p);
	build_fitness_matrix(game, critical);
	ft_log("New trun\n");
	log_matrix(game->map);
	log_matrix(game->piece.field);
	log_critical_points(p);
	log_fitness_matrix((int **)game->fitness.m, game->fitness.rows, game->fitness.cols);
	move = get_move(game);
	send_move(move[0], move[1]);
	i = -1;
	while (++i < game->fitness.rows)
		ft_memdel(&(game->fitness.m[i]));
	free(game->fitness.m);
	free(move);
	free(p);
	return (1);
}
