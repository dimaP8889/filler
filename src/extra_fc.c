/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_fc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:15:56 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/05/12 17:24:06 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dpogrebn.filler.h"

void	set_par_fig(int *x, int *y, int *cnt_shrp, int *sum)
{
	*x = 0;
	*y = 0;
	*cnt_shrp = 0;
	*sum = 0;
}

int		make_out(int min, int y, int x)
{
	if (min == 0)
	{
		ft_printf("%i %i\n", 0, 0);
		return (0);
	}
	ft_printf("%i %i\n", y, x);
	return (1);
}

void	set_params_pos(t_coord	*coord)
{
	coord->x = 0;
	coord->y = 0;
}

void	ft_op_let(t_flr *flr)
{
	if (flr->player == 1)
	{
		flr->let = 'O';
		flr->op = 'X';
	}
	else if (flr->player == 2)
	{
		flr->let = 'X';
		flr->op = 'O';
	}
}