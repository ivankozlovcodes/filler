/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 19:19:06 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/22 21:31:06 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "ft_printf.h"
#include <limits.h>

t_point	*intialize_critical_points(int width, int height)
{
	t_point		*res;
	int			i;

	res = malloc(sizeof(t_point) * C_POINTS);
	res[0].x = width / 2;
	res[0].y = height / 2;
	res[1].x = 0;
	res[1].y = 0;
	res[2].x = width;
	res[2].y = 0;
	res[3].x = width;
	res[3].y = height;
	res[4].x = 0;
	res[4].y = height;
	i = -1;
	while (++i < C_POINTS)
	{
		res[i].distances[0] = INT_MAX;
		res[i].distances[1] = INT_MAX;
	}
	return (res);
}

void	set_point_owner(t_point *cp, int x, int y, char p)
{
	int		i;
	int		d;
	int		player;

	i = -1;
	player = ft_tolower(p) == 'x';
	while (++i < C_POINTS)
	{
		d = DISTANCE(cp[i].x, cp[i].y, x, y);
		if (cp[i].distances[player] > d)
		{
			cp[i].distances[player] = d;
			return ;
		}
	}
}

t_point	*get_critical_points(t_game game)
{
	t_point		*points;
	int			*distance;
	int			i;
	int			j;

	points = intialize_critical_points(game.map.cols, game.map.rows);
	distance = malloc(sizeof(int) * C_POINTS);
	i = -1;
	while (++i < game.map.rows)
	{
		j = -1;
		while (++j < game.map.cols)
			if (ft_strchr("xo", ft_tolower(game.map.m[i][j])))
				set_point_owner(points, j, i, game.map.m[i][j]);
	}
	return (points);
}

void	send_move(int row, int column)
{
	ft_log("Placing a piece at %d %d\n", row, column);
	ft_putnbr(row);
	write(STDOUT_FILENO, SPACE, 1);
	ft_putnbr(column);
	write(STDOUT_FILENO, NEW_LINE, 1);
}

int		gameon(t_game *game)
{
	t_point	*critical;

	get_data(game);
	ft_log("Got data\n");
	log_matrix(game->map);
	log_matrix(game->piece.field);
	critical = get_critical_points(*game);
	// set main critical point
	// build fitness matrix
	// make a move
	free(critical);
	return (0);
}
