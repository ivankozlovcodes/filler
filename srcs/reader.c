/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 19:17:54 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/20 14:48:16 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "get_next_line.h"

static void		get_matrix_size(t_matrix *matrix, int fd)
{
	char	*line;
	int		i;

	i = 0;
	if (!get_next_line(fd, &line))
		exit(1);
	while (!ft_isdigit(*(line + i)))
		i++;
	matrix->rows = ft_atoi(line + i);
	while (ft_isdigit(*(line + i)))
		i++;
	matrix->cols = ft_atoi(line + i);
	free(line);
}

static void		fill_matrix(t_matrix *matrix, int fd, int skip)
{
	char	*line;
	int		i;

	i = -1;
	while (++i < matrix->rows)
	{
		if (!get_next_line(fd, &line))
			exit(1);
		matrix->m[i] = ft_strdup(line + skip);
		free(line);
	}
}

static void		get_map(t_game *game)
{
	char	*line;
	int		i;

	i = -1;
	get_matrix_size(&game->map, g_fd);
	get_next_line(g_fd, &line);
	free(line);
	game->map.m = malloc(sizeof(char *) * game->rows);
	fill_matrix(&game->map, g_fd, 4);
}

static void		get_piece(t_game *game)
{
	get_matrix_size(&game->piece, g_fd);
	game->piece.m = malloc(sizeof(char *) * game->piece.rows);
	fill_matrix(&game->piece, g_fd, 0);
}

void	get_data(t_game *game)
{
	get_map(game);
	get_piece(game);
}
