/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 21:56:46 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/23 15:40:30 by ikozlov          ###   ########.fr       */
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

	game = malloc(sizeof(t_game));
	ft_log("*********************START************************\n");
	whoami(game);
	ft_log("I am %c or %c\n", game->player, game->player - 32);
	while (gameon(game))
		continue ;
	return (0);
}
