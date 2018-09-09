/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   critical_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:55:47 by ikozlov           #+#    #+#             */
/*   Updated: 2018/09/09 18:00:57 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "math.h"
#include <limits.h>

t_list	*get_enemy(t_game *game)
{
	int			i;
	int			j;
	char		**map;
	t_point		tmp;
	t_list		*res;

	res = NULL;
	map = MTX_TOCHAR(game->map.m);
	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.cols)
			if (ft_tolower(map[i][j]) == game->opponent)
			{
				SETXY((&tmp), j, i);
				if (res == NULL)
					res = ft_lstnew(&tmp, sizeof(tmp));
				else
					ft_lstadd(&res, ft_lstnew(&tmp, sizeof(tmp)));
			}
	}
	return (res);
}

t_point	get_opponents_last_move(t_game *game)
{
	int			i;
	int			j;
	char		**map;
	t_point		end;
	t_point		start;

	i = -1;
	SETXY((&end), -1, -1);
	SETXY((&start), -1, -1);
	map = MTX_TOCHAR(game->map.m);
	while (++i < game->map.rows && game->old_map.m != NULL)
	{
		j = -1;
		while (++j < game->map.cols)
			if (map[i][j] != MTX_TOCHAR(game->old_map.m)[i][j]
				&& ft_tolower(map[i][j]) == game->opponent)
			{
				start.x == -1 ? SETXY((&start), j, i) : (void)0;
				end.x < j || end.y < i ? SETXY((&end), j, i) : (void)0;
			}
	}
	SETXY((&start), (start.x + end.x) / 2, (start.y + end.y) / 2);
	return (start);
}

void	set_main_critical_point(t_game *game)
{
	game->critical_point = get_opponents_last_move(game);
	game->enemy = get_enemy(game);
	if (game->critical_point.x < 0 || game->critical_point.y < 0)
		SETXY((&game->critical_point), game->map.cols / 2, game->map.rows / 2);
}
