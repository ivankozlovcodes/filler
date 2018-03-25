/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 21:56:46 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/25 14:28:56 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include <fcntl.h>

void	die(char *msg)
{
	ft_printf("Died in %s\n", msg);
	exit(0);
}

int		main(void)
{
	t_game	*game;
	int		fd;

	game = malloc(sizeof(t_game));
	ft_log("*********************START************************\n");
	if (READ_FROM_FAKE)
		fd = open("fake.txt", O_RDONLY);
	else
		fd = STDIN_FILENO;
	whoami(game, fd);
	game->old_map.m = NULL;
	ft_log("I am %c or %c\n", game->player, game->player - 32);
	while (gameon(game, fd))
		continue ;
	return (0);
}
