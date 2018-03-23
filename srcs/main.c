/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 21:56:46 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/22 19:53:36 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include <stdio.h>

void	whoami(t_game *game)
{
	char	*line;
	int		i;

	if (!get_next_line(STDIN_FILENO, &line))
		die("whoami");
	i = 0;
	while (line[i] && line[i] != 'p')
		i++;
	if (line[i + 1] == '1')
		game->player = 'o';
	else
		game->player = 'x';
	ft_strdel(&line);
}

void	log_matrix(t_matrix m)
{
	int		i;

	i = -1;
	ft_log("Size: r%d c%d\n", m.rows, m.cols);
	while (++i < m.rows)
		ft_log("%s\n", m.m[i]);
}

void	die(char *msg)
{
	ft_printf("Died in %s\n", msg);
	exit(0);
}

int		main()
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	ft_log("*********************START************************\n");
	whoami(game);
	ft_log("I am %c or %c\n", game->player, game->player - 32);
	while (1)
	{
		get_data(game);
		ft_log("Got data\n");
		log_matrix(game->map);
		log_matrix(game->piece.field);
		// int	i;
		// int	j;
		int	r,c;
		r = 8; c = 2;
		// i = -1;
		// while (++i < game.map.rows)
		// {
		// 	j = -1;
		// 	while (++j < game.map.cols)
		// 	{
		// 		if (game.map.m[i][j] == game.player
		// 			|| game.map.m[i][j] == game.player - 32)
		// 		{
		// 			ft_log("Checking %c at r:%d c:%d\n", game.map.m[i][j], i, j);
		// 			ft_log("Found match\n");
		// 			r = i;
		// 			c = j;
		// 		}
		// 		// ft_log("Sending1 %d %d\n", i, j);
		// 		// printf("%d %d\n", i, j);
		// 	}
		// }
		ft_log("Sending %d %d\n", r, c);
		// printf("%d %d", r, c);
		ft_putnbr(r);
		write(1, " ", 1);
		ft_putnbr(c);
		write(1, "\n", 1);
	}
	return (0);
}