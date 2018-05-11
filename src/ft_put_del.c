/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 20:02:24 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/05/10 17:52:57 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define	MAP	flr.map[y + coord.y][x + coord.x]
#define	PC	flr.piece[y + y_mv][x + x_mv]

#include "dpogrebn.filler.h"

/* 
Count minus for y 
*/

int		ft_count_min_y(t_flr flr)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (flr.piece[y])
	{
		while (flr.piece[y][x])
		{
			if (flr.piece[y][x] == '*')
				return (y);
			x++;
		}
		x = 0;
		y++;
	}
	return(0);
}

/* 
Count minus for x 
*/

int		ft_count_min_x(t_flr flr)
{
	int	x;
	int	y;
	int	x_mv;

	y = 0;
	x = 0;
	x_mv = ft_strlen(flr.piece[0]);
	while (flr.piece[y])
	{
		while (flr.piece[y][x])
		{
			if (flr.piece[y][x] == '*')
				if (x < x_mv)
					x_mv = x;
			x++;
		}
		x = 0;
		y++;
	}
	return(x_mv);
}

/* 
Try to put figure on map and count it sum 
*/

int		ft_put_figure(t_flr flr, int x_mv, int y_mv, t_coord coord)
{
	int	x;
	int	y;
	int	sum;
	int	cnt_shrp;

	set_par_fig(&x, &y, &cnt_shrp, &sum);
	while (flr.piece[y + y_mv])
	{
		if (!flr.map[y + coord.y])
			return (0);
		while (PC)
		{
			if (!MAP || MAP == flr.op || MAP == flr.op + 32)
				return (0);
			sum = (PC == '*' ? MAP + sum : sum);
			if ((MAP == flr.let || MAP == flr.let + 32) && PC == '*')
				cnt_shrp++;
			x++;
		}
		x = 0;
		y++;
	}
	if (cnt_shrp != 1)
		return (0);
	return (sum);
}

/*
Save the minnimal sum and it coordinates
*/

int		ft_find_pos(t_flr flr, int x_mv, int y_mv)
{
	t_coord	coord;
	int		sv_x;
	int		sv_y;
	int		sum;
	int		min;

	set_params_pos(&coord);
	min = 0;
	while (flr.map[coord.y])
	{
		while (flr.map[coord.y][coord.x])
		{
			sum = ft_put_figure(flr, x_mv, y_mv, coord);
			if ((!min || sum < min) && sum)
			{
				min = sum;
				sv_y = coord.y;
				sv_x = coord.x;
			}
			coord.x++;
		}
		coord.x = 0;
		coord.y++;
	}
	return (!make_out(min, sv_y - y_mv, sv_x - x_mv) ? 0 : 1);
}

int	ft_put_det(t_flr flr)
{
	int	y_mv;
	int x_mv;

	y_mv = ft_count_min_y(flr);
	x_mv = ft_count_min_x(flr);
	return (!ft_find_pos(flr, x_mv, y_mv) ? 0 : 1);
}