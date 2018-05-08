/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 14:47:27 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/05/05 19:13:41 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dpogrebn.filler.h"

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

int		ft_count_min_x(t_flr flr, int y)
{
	int	x;

	x = 0;
	while (flr.piece[y][x])
	{
		if (flr.piece[y][x] == '*')
			return (x);
		x++;
	}
	return(0);
}

int		ft_count_len(int y2, int y1, int x2, int x1)
{
	int y;
	int x;
	int len;

	y = (y2 - y1 > 0 ? y2 - y1 : y1 - y2);
	x = (x2 - x1 > 0 ? x2 - x1 : x1 - x2);
	len = y + x;
	return (len);
}

void	ft_fill_near(t_flr flr, int x_len, int y_len)
{
	int		x;
	int		y;
	int		len;

	x = 0;
	y = 0;
	len = 0;
	while (flr.map[y])
	{
		while (flr.map[y][x])
		{
			if ((flr.map[y][x] == '.' || ft_count_len(y_len, y, x_len, x) < flr.map[y][x] - 48) 
				&& flr.map[y][x] != 'x' && flr.map[y][x] != 'X' && flr.map[y][x] != 'o'
				&& flr.map[y][x] != 'O')
				flr.map[y][x] = ft_count_len(y_len, y, x_len, x) + 48;
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_fill_num(t_flr flr)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (flr.map[y])
	{
		while (flr.map[y][x])
		{
			if (flr.map[y][x] == flr.op || flr.map[y][x] == flr.op + 32)
				ft_fill_near(flr, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_fill(t_flr flr)
{
	int		x_mv;
	int		y_mv;

	ft_print(flr);
	ft_fill_num(flr);
	ft_print(flr);
	y_mv = ft_count_min_y(flr);
	x_mv = ft_count_min_x(flr, y_mv);
}