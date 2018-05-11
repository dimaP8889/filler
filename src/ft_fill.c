/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 14:47:27 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/05/10 17:51:06 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAP	flr.map[y][x]

#include "dpogrebn.filler.h"

/* 
Count numbers for shortest way
*/

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

/* 
Fill map with numbers
*/

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
		while (MAP)
		{
			if ((MAP == '.' || ft_count_len(y_len, y, x_len, x) < MAP - 48)
				&& MAP != 'x' && MAP != 'X' && MAP != 'o'
				&& MAP != 'O')
			{
				MAP = ft_count_len(y_len, y, x_len, x) + 48;
				if (MAP == 'x' || MAP == 'X' || MAP == 'o'
				|| MAP == 'O')
					MAP++;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

/* 
Fill map with numbers
*/

void	ft_fill_num(t_flr flr)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (flr.map[y])
	{
		while (MAP)
		{
			if (MAP == flr.op || MAP == flr.op + 32)
				ft_fill_near(flr, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

int		ft_fill(t_flr flr)
{
	ft_fill_num(flr);
	return (!ft_put_det(flr) ? 0 : 1);
}