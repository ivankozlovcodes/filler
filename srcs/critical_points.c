/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   critical_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:55:47 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/24 20:17:28 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "math.h"
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
	res[2].x = width - 1;
	res[2].y = 0;
	res[3].x = width - 1;
	res[3].y = height - 1;
	res[4].x = 0;
	res[4].y = height - 1;
	i = -1;
	while (++i < C_POINTS)
	{
		res[i].distances[0] = width + height;
		res[i].distances[1] = width + height;
	}
	return (res);
}

void	set_distances(t_point *cp, int x, int y, char p)
{
	int		i;
	int		d;
	int		player;

	i = -1;
	player = ft_tolower(p) == 'x';
	while (++i < C_POINTS)
	{
		d = DISTANCE(x, y, cp[i].x, cp[i].y);
		if (cp[i].distances[player] > d)
			cp[i].distances[player] = d;
	}
}

t_point	*get_critical_points(t_game *game)
{
	t_point		*points;
	char		**map;
	int			i;
	int			j;

	i = -1;
	map = (char **)game->map.m;
	points = intialize_critical_points(game->map.cols, game->map.rows);
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.cols)
			if (ft_strchr("xo", ft_tolower(map[i][j])))
				set_distances(points, j, i, map[i][j]);
	}
	return (points);
}

void	set_main_critical_point(t_game *game)
{
	int			i;
	int			player;
	int			opponent;
	int			distance;
	t_point		*p;

	player = game->player == PLAYER2;
	opponent = game->opponent == PLAYER2;
	distance = -1;
	p = get_critical_points(game);
	if (p[0].distances[player] > 0 && p[0].distances[opponent] != 0)
		game->critical_point = p[0];
	else
	{
		i = 0;
		while (++i < C_POINTS)
			if (p[i].distances[player] > p[i].distances[opponent]
				&& distance < p[i].distances[player])
				game->critical_point = p[i];
	}
	ft_log("Return critical point at pos %d, %d\n", game->critical_point.x,
		game->critical_point.y);
	free(p);
}
