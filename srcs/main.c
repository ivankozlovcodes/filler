/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:47:36 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/20 15:03:05 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "get_next_line.h"
#include "ft_printf.h"

void	whoami(t_game *game)
{
	char	*line;
	char	*head;
	
	if (!get_next_line(g_fd, &line))
		exit(0);
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

int		main(void)
{
	t_game	game;
	
	g_fd = DEBUG == 1 ? open('test') : 0;
	whoami(&game);
	gameon(&game);
	print_game(game);
	// while (gameon(&game))
	// 	continue ;
	return (0);
}