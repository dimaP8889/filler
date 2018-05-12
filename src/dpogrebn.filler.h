/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dpogrebn.filler.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:58:19 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/04/23 13:58:20 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DPOGREBN_FILLER_H
# define DPOGREBN_FILLER_H

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../libft/ft_printf/ft_printf.h"

typedef struct 	s_flr
{
	int			player;
	char		let;
	char		op;
	char		**map;
	char		**piece;
}				t_flr;

typedef	struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

int				ft_fill(t_flr flr);
void			ft_print(t_flr flr);
int				ft_put_det(t_flr flr);
void			set_params_pos(t_coord	*coord);
int				make_out(int min, int y, int x);
void			set_par_fig(int *x, int *y, int *cnt_shrp, int *sum);
void			ft_op_let(t_flr *flr);

#endif