/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 21:56:46 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/22 21:37:37 by ikozlov          ###   ########.fr       */
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

void	die(char *msg)
{
	ft_printf("Died in %s\n", msg);
	exit(0);
}

int		main(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	ft_log("*********************START************************\n");
	whoami(game);
	ft_log("I am %c or %c\n", game->player, game->player - 32);
	while (gameon(game))
		continue ;
	return (0);
}
