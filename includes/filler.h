/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:59:15 by ikozlov           #+#    #+#             */
/*   Updated: 2018/03/22 21:45:52 by ikozlov          ###   ########.fr       */
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

struct					s_piece
{
	t_matrix			field;
	int					weight;
};
typedef struct s_piece	t_piece;

struct					s_game
{
	int					rows;
	int					cols;
	char				player;
	char				opponent;
	t_piece				piece;
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

void					get_data(t_game *game);
int						gameon(t_game *game);
void					die(char *msg);

void					ft_log(char *msg, ...);
void					log_matrix(t_matrix m);
void					log_critical_points(t_point *p);

#endif
