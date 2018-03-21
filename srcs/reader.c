/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:46:10 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/21 13:55:50 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "get_next_line.h"

void	get_map_size(t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	if (!get_next_line(STDIN_FILENO, &line))
		exit(0);
	while (!ft_isdigit(line[i]))
		i++;
	game->rows = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	game->cols = ft_atoi(&line[i + 1]);
	free(line);
}

void	get_map(t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	game->map = (char**)malloc(sizeof(char*) * (game->rows + 1));
	get_next_line(STDIN_FILENO, &line);
	free(line);
	i = 0;
	while (i < game->rows)
	{
		get_next_line(STDIN_FILENO, &line);
		game->map[i] = ft_strdup(line + 4);
		free(line);
		i++;
	}
	game->map[i] = NULL;
}

void	get_piece(t_game *game)
{
	char	*line;
	int		i;
	int		size;

	i = 0;
	get_next_line(STDIN_FILENO, &line);
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	if (line[i] == '0')
		size = 0;
	else
		size = ft_atoi(&line[i]);
	free(line);
	game->piece = (char**)malloc(sizeof(char*) * (size + 1));
	i = 0;
	while (i < size)
	{
		get_next_line(STDIN_FILENO, &line);
		game->piece[i] = ft_strdup(line);
		free(line);
		i++;
	}
	game->piece[i] = NULL;
}

void	get_data(t_game *game)
{
	get_map_size(game);
	get_map(game);
	get_piece(game);
}