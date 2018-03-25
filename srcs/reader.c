/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:46:10 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/24 20:27:55 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "get_next_line.h"

void	whoami(t_game *game, int fd)
{
	char	*line;
	int		i;

	if (!get_next_line(fd, &line))
		die("whoami");
	i = 0;
	while (line[i] && line[i] != 'p')
		i++;
	if (line[i + 1] == '1')
		game->player = PLAYER1;
	else
		game->player = PLAYER2;
	game->opponent = game->player == PLAYER1 ? PLAYER2 : PLAYER1;
	ft_strdel(&line);
}
{
	char	*line;
	int		i;

	i = 0;
	if (!get_next_line(STDIN_FILENO, &line))
		die("get_matrix_size");
	while (!ft_isdigit(*(line + i)))
		i++;
	mtx->rows = ft_atoi(line + i);
	while (ft_isdigit(*(line + i)))
		i++;
	mtx->cols = ft_atoi(line + i);
	ft_strdel(&line);
}

void	get_matrix(t_matrix *mtx, int skip)
{
	char	*line;
	int		i;

	i = -1;
	ft_log("getting matrix %d %d\n", mtx->rows, mtx->cols);
	while (++i < mtx->rows)
	{
		if (get_next_line(STDIN_FILENO, &line) < 0)
			die("get_matrix");
		mtx->m[i] = ft_strdup(line + skip);
		ft_log("Read line: |%s|\n", line);
		ft_strdel(&line);
	}
	ft_log("got matrix\n");
}

void	get_data(t_game *game)
{
	char	*line;

	get_matrix_size(&game->map);
	game->map.m = malloc(sizeof(char *) * game->map.rows);
	get_next_line(STDIN_FILENO, &line);
	ft_strdel(&line);
	get_matrix(&game->map, 4);
	get_matrix_size(&game->piece);
	game->piece.m = malloc(sizeof(char *) * game->piece.rows);
	get_matrix(&game->piece, 0);
}
