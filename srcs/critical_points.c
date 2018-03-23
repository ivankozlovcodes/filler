/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   critical_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:55:47 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/23 15:00:10 by ikozlov          ###   ########.fr       */
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

t_point	get_main_critical_point(t_point *p)
{
	return (p[0]);
}

t_point	*get_critical_points(t_game game)
{
	t_point		*points;
	int			*distance;
	int			i;
	int			j;

	points = intialize_critical_points(game.map.cols, game.map.rows);
	log_critical_points(points);
	distance = malloc(sizeof(int) * C_POINTS);
	i = -1;
	while (++i < game.map.rows)
	{
		j = -1;
		while (++j < game.map.cols)
			if (ft_strchr("xo", ft_tolower(game.map.m[i][j])))
				set_distances(points, j, i, game.map.m[i][j]);
	}
	return (points);
}
