/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 17:05:01 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/05/12 17:14:24 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

/*
Initialize image
*/

void	ft_init_image(t_mlx *data)
{
	int		bpp;
	int		ln_s;
	int		endian;

	data->img.img_ptr = mlx_new_image(data->mlx, 990, 600);
	data->img.img_mas = (int *)mlx_get_data_addr(data->img.img_ptr, &(bpp), &(ln_s),
	&(endian));
}

/*
Check pos on massive
*/

static	int		ft_check_col(int y, int x, t_mlx *vis)
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

/*
Fill img with col
*/

static	void	ft_fill_col(int x, int y, int col, t_mlx *vis)
{
	if (col == 1)
		vis->img.img_mas[y * LEN_P + x] = 0x00006400;
	else if (col == 2)
		vis->img.img_mas[y * LEN_P + x] = 0x0000FF00;
	else if (col == 3)
		vis->img.img_mas[y * LEN_P + x] = 0x00FF0000;
	else if (col == 4)
		vis->img.img_mas[y * LEN_P + x] = 0x00FFFFFF;
}

/*
Fill img by pixel
*/

void		ft_out(t_mlx *vis)
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
			ft_fill_col(x, y, col, vis);
			if (y % (int)vis->hei == 0 || x % (int)vis->len == 0)
				vis->img.img_mas[y * LEN_P + x] = 0x00000000;
			x++;
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window(vis->mlx, vis->wnd, vis->img.img_ptr, 0, 0);
}
