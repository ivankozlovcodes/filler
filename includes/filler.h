/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:59:15 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/19 19:38:43 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

struct					s_game
{
	char				**map;
	int					rows;
	int					cols;
	char				player;
	char				opponent;
};
typedef struct s_game	t_game;

void					get_data(t_game *game);

#endif