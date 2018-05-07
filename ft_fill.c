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

void ft_fill_x(t_flr flr)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (flr.map[y])
	{
		while (flr.map[y][x])
		{
			x++;
			if (flr.map[y][x] == 'X')
				break;
		}
		if (flr.map[y][x] == 'X')
				break;
		x = 0;
		y++;
	}
	ft_printf("%i\n", x);
	ft_printf("%i\n", y);
}

void	ft_fill(t_flr flr)
{
	if (flr.let == 'X')
		ft_fill_x(flr);
	// else if (flr.let == 'O')
	// 	ft_fill_o(flr);
	ft_printf("lol");
}