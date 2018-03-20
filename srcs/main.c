/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:47:36 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/19 19:18:03 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "get_hext_line.h"

void	whoami(t_game *game)
{
	char	*line;
	char	*head;
	
	if (!get_next_line(STDERR_FILENO, &line))
		exit(0);
	head = line;
	line = ft_strchr(line, 'p');
	if (*(line + 1) == '1')
		game->player = 'o';
	else
		game->player = 'x';
	free(head);
}
}

int		main(void)
{
	t_game	game;
	
	whoami(&game);
	while (gameon(&game))
		continue ;
	return (0);
}