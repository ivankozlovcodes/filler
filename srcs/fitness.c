/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fitness.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 20:53:24 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/26 18:42:49 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_if_inmap(int i, int j, t_game *game)
{
	return (i >= game->piece.rows && j >= game->piece.cols
				&& i < game->piece.rows + game->map.rows
				&& j < game->piece.cols + game->map.cols);
}

int		get_fitness(int i, int j, t_game *game)
{
	char	c;
	int		res;
	t_point	p;

	p = game->critical_point;
	if (check_if_inmap(i, j, game))
		c = ft_tolower(MTX_TOCHAR(game->map.m)\
			[i - game->piece.rows][j - game->piece.cols]);
	else
		return (-1);
	if (c == game->player)
		res = 0;
	else if (c == game->opponent)
		res = -FITNESS_MAX;
	else
		res = FITNESS_MAX - ABS(game->piece.cols + p.x - j)
			- ABS(game->piece.rows + p.y - i);
	return (res);
}

void	build_fitness_matrix(t_game *game)
{
	int		**res;
	int		i;
	int		j;

	game->fitness.rows = game->map.rows + game->piece.rows * 2;
	game->fitness.cols = game->map.cols + game->piece.cols * 2;
	res = malloc(sizeof(int *) * game->fitness.rows);
	i = -1;
	while (++i < game->fitness.rows)
	{
		j = -1;
		res[i] = malloc(sizeof(int) * game->fitness.cols);
		while (++j < game->fitness.cols)
			res[i][j] = get_fitness(i, j, game);
	}
	game->fitness.m = (void **)res;
}
