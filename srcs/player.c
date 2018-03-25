/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 19:19:06 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/24 20:34:01 by ikozlov          ###   ########.fr       */
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

void	build_fitness_matrix(t_game *game)
{
	t_point	p;
	int		**res;
	char	c;
	int		i;
	int		j;

	game->fitness.rows = game->map.rows + game->piece.rows * 2;
	game->fitness.cols = game->map.cols + game->piece.cols * 2;
	res = malloc(sizeof(int *) * game->fitness.rows);
	p = game->critical_point;
	i = -1;
	while (++i < game->fitness.rows)
	{
		j = -1;
		res[i] = malloc(sizeof(int) * game->fitness.cols);
		while (++j < game->fitness.cols)
		{
			if (i >= game->piece.rows && j >= game->piece.cols
				&& i < game->piece.rows + game->map.rows && j < game->piece.cols + game->map.cols)
				c = ft_tolower(MTX_TOCHAR(game->map.m)\
					[i - game->piece.rows][j - game->piece.cols]);
			else
				c = game->opponent;
			if (c == game->player)
				res[i][j] = 0;
			else if (c == game->opponent)
				res[i][j] = -FITNESS_MAX;
			else
				res[i][j] = FITNESS_MAX - ABS(game->piece.cols + p.x - j) - ABS(game->piece.rows + p.y - i);
		}
	}
	game->fitness.m = (void **)res;
}

int		get_sum(int **fitness, t_matrix p, int row, int col)
{
	int		i;
	int		j;
	int		hit_self;
	int		sum;

	i = -1;
	sum = 0;
	hit_self = 0;
	while (++i < p.rows)
	{
		j = -1;
		while (++j < p.cols)
			if (MTX_TOCHAR(p.m)[i][j] == '*')
			{
				if (fitness[p.rows + row + i][p.cols + col + j] == 0)
					hit_self++;
				sum += fitness[p.rows + row + i][p.cols + col + j];
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
			tmp = get_sum(MTX_TOINT(game->fitness.m), game->piece, i, j);
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
	int		*move;

	get_data(game);
	set_main_critical_point(game);
	build_fitness_matrix(game);
	ft_log("New trun\n");
	log_matrix(game->map);
	log_matrix(game->piece);
	log_fitness_matrix(MTX_TOINT(game->fitness.m),
		game->fitness.rows, game->fitness.cols);
	move = get_move(game);
	send_move(move[0], move[1]);
	free_matrix(&game->map);
	free_matrix(&game->piece);
	free_matrix(&game->fitness);
	free(move);
	return (1);
}
