/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 19:17:54 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/19 19:31:22 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "get_next_line.h"

void static		get_map_size(t_game *game)
{
	char	*line;

	if (!get_next_line(STDERR_FILENO, &line))
		exit(1);
}

void	get_data(t_game *game)
{
	get_map_size(game);
	return ;
}
