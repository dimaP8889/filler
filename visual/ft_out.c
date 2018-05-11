/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 17:05:01 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/05/11 17:05:03 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int		ft_check_col(int y, int x, t_mlx *vis)
{
	if (vis->map[(int)(y / vis->hei)][(int)(x / vis->len)] == 'O')
		return(1);
	if (vis->map[(int)(y / vis->hei)][(int)(x / vis->len)] == 'o')
		return(2);
	if (vis->map[(int)(y / vis->hei)][(int)(x / vis->len)] == 'X')
		return(3);
	if (vis->map[(int)(y / vis->hei)][(int)(x / vis->len)] == 'x')
		return(4);
	return (0);
}

void	ft_out(t_mlx *vis)
{
	int		x;
	int		y;
	int		col;
	int		count;

	x = 0;
	y = 0;
	count = 0;
	col = 0;
	while (y < HEI_P)
	{
		while (x < LEN_P)
		{
			vis->img.img_mas[y * LEN_P + x] = 0x00BA55D3;
			col = ft_check_col(y, x, vis);
			if (col == 1)
				vis->img.img_mas[y * LEN_P + x] = 0x00006400;
			else if (col == 2)
				vis->img.img_mas[y * LEN_P + x] = 0x0000FF00;
			else if (col == 3)
				vis->img.img_mas[y * LEN_P + x] = 0x00FF0000;
			else if (col == 4)
				vis->img.img_mas[y * LEN_P + x] = 0x00FFFFFF;
			if (y % (int)vis->hei == 0 || x % (int)vis->len == 0)
				vis->img.img_mas[y * LEN_P + x] = 0x00000000;
			x++;
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window(vis->mlx, vis->wnd, vis->img.img_ptr, 0, 0);
	ft_bzero(vis->img.img_mas, 1000 * 650 * 4);
}
