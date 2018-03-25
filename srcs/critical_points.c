/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   critical_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:55:47 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/25 15:02:35 by ikozlov          ###   ########.fr       */
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

void	set_distance(t_point point, int x, int y, char p)
{
	int		d;
	int		player;

	player = ft_tolower(p) == PLAYER2;
	d = DISTANCE(x, y, point.x, point.y);
	if (point.distances[player] > d)
		point.distances[player] = d;
}

void	set_distances(t_point *cp, int x, int y, char p)
{
	int		i;

	i = -1;
	while (++i < C_POINTS)
		set_distance(cp[i], x, y, p);
}

t_point	get_opponents_last_move(t_game *game)
{
	int			i;
	int			j;
	char		**map;
	t_point		end;
	t_point		start;

	i = -1;
	SETXY(end, -1, -1);
	SETXY(start, -1, -1);
	map = MTX_TOCHAR(game->map.m);
	while (++i < game->map.rows && game->old_map.m != NULL)
	{
		j = -1;
		while (++j < game->map.cols)
			if (map[i][j] != MTX_TOCHAR(game->old_map.m)[i][j]
				&& ft_tolower(map[i][j]) == game->opponent)
			{
				start.x == -1 ? SETXY(start, j, i) : (void)0;
				end.x < j || end.y < i ? SETXY(end, j, i) : (void)0;
			}
	}
	SETXY(start, (start.x + end.x) / 2, (start.y + end.y) / 2);
	return (start);
}

void	set_main_critical_point(t_game *game)
{
	int			player;
	int			opponent;
	int			distance;
	t_point		*p;

	player = game->player == PLAYER2;
	opponent = game->opponent == PLAYER2;
	distance = -1;
	p = get_critical_points(game);
	game->critical_point = get_opponents_last_move(game);
	ft_log("Return critical point at pos %d, %d\n", game->critical_point.x,
		game->critical_point.y);
	free(p);
}
