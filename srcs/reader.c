/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 19:17:54 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/19 19:57:42 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "get_next_line.h"

static void 	get_map_size(t_game *game)
{
	char	*line;

	if (!get_next_line(STDERR_FILENO, &line))
		exit(1);
	while (!ft_isdigit(*line))
		line++;
	game->rows = ft_atoi(line);
	while (!ft_isdigit(*line))
		line++;
	game->cols = ft_atoi(line);
	free(line);
}

static void		get_map(t_game *game)
{
	char	*line;
	int		i;

	i = -1;
	game->map = malloc(sizeof(char *) * game->rows);
	while (++i < game->rows)
	{
		gam
	}
}

void	get_data(t_game *game)
{
	get_map_size(game);
	get_map(game);
	return ;
}
