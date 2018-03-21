/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:47:36 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/20 19:44:48 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "get_next_line.h"
#include "ft_printf.h"
#include <fcntl.h>

void	whoami(t_game *game, int fd)
{
	char	*line;
	char	*head;
	
	if (!get_next_line(fd, &line))
	{
		ft_log("Read line: %s\n", line);
		die(0);
	}
	head = line;
	line = ft_strchr(line, 'p');
	if (*(line + 1) == '1')
		game->player = 'o';
	else
		game->player = 'x';
	free(head);
}

void	print_matrix(t_matrix m)
{
	int		i;

	i = -1;
	while (++i < m.rows)
		ft_printf("%s\n", m.m[i]);
}

void	print_game(t_game game)
{
	ft_printf("Map:\n");
	print_matrix(game.map);
	ft_printf("Piece:\n");
	print_matrix(game.piece);
}

void	die(int fd)
{
	ft_printf("Dying... fd: %d\n", fd);
	if (DEBUG == 1)
		close(fd);
	exit(fd);
}

int		main(void)
{
	t_game	game;
	int		fd;
	
	fd = DEBUG == 1 ? open("test2", O_RDONLY) : 0;
	whoami(&game, fd);
	ft_log("Finished init players\n");
	gameon(&game, fd);
	print_game(game);
	// while (gameon(&game))
	// 	continue ;
	close(fd);
	return (0);
}