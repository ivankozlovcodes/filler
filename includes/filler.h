/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:59:15 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/20 16:07:05 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

# define PLAYER1 'o'
# define PLAYER2 'x'
# define C_POINTS 5

# define DEBUG 1

struct					s_matrix
{
	char				**m;
	int					rows;
	int					cols;
};
typedef struct s_matrix	t_matrix;

struct					s_game
{
	int					rows;
	int					cols;
	char				player;
	char				opponent;
	t_matrix			piece;
	t_matrix			map;
};
typedef struct s_game	t_game;

struct					s_point
{
	int					x;
	int					y;
	int					distances[2];
};
typedef struct s_point	t_point;

void					get_data(t_game *game, int fd);
int						gameon(t_game *game, int fd);
void					die(int fd);

void					ft_log(char *msg, ...);

#endif