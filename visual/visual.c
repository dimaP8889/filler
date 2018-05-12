/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 19:58:18 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/05/12 17:14:43 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

/*
Fill map
*/

static	char	**ft_fill_map(int fd, int hei_c, char **map)
{
	char		*str;
	int			coun;

	coun = 0;
	get_next_line(fd, &str);
	if (ft_strstr(str, ".") || ft_strstr(str, "*"))
		return (NULL);
	while (hei_c > 0)
	{
		get_next_line(fd, &str);
		while (*str == ' ' || ft_isdigit(*str))
			str++;
		map[coun] = ft_strcpy(map[coun], str);
		coun++;
		hei_c--;
	}
	map[coun] = NULL;
	return(map);
}

/*
Allocate mem for char massive
*/

static	char	**ft_get_size(char *str, int fd, t_mlx *vis)
{
	int 	len;
	int		hei;
	char	**map;
	int		hei_c;
	int		coun;

	coun = 0;
	while (!ft_isdigit(*str))
		str++;
	hei = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	str++;
	len = ft_atoi(str);
	map = (char **)malloc(sizeof(char *) * (hei + 1));
	hei_c = hei;
	vis->len = LEN_P / len;
	vis->hei = HEI_P / hei;
	while (hei-- > 0)
	{
		map[coun] = (char *)malloc(sizeof(char) * (len + 1));
		coun++;
	}
	map = ft_fill_map(fd, hei_c, map);
	return(map);
}

/*
Exit key
*/

static	int		key(int num, void *vis)
{
	(void)vis;
	if (num == 53)
		exit(1);
	return (0);
}

/*
Find map
*/

static	int		ft_visual(void *v)
{
	char	*str;
	t_mlx	*vis;
	int		fd;

	vis = (t_mlx *)v;
	fd = 0;
	while (!ft_strstr(str, "Plateau"))
	{
		get_next_line(fd, &str);
		if (ft_strstr(str, "O fin"))
		{
			mlx_destroy_window(vis->mlx, vis->wnd);
			vis->mlx = mlx_init();
			vis->wnd = mlx_new_window(vis->mlx, 990, 600, "mlx 42");
			mlx_string_put (  vis->mlx, vis->wnd, 420, 260, 0xFF0000, str );
			get_next_line(fd, &str);
			mlx_string_put (  vis->mlx, vis->wnd, 420, 300, 0xFF0000, str );
			mlx_key_hook(vis->wnd, key, &vis);
			mlx_loop(vis->mlx);
		}
	}
	vis->map = ft_get_size(str, fd, vis);
	ft_out(vis);
	return (0);
}

int				main(void)
{
	t_mlx	vis;

	vis.mlx = mlx_init();
	vis.wnd = mlx_new_window(vis.mlx, 990, 600, "mlx 42");
	ft_init_image(&vis);
	mlx_loop_hook(vis.mlx, ft_visual, &vis);
	mlx_key_hook(vis.wnd, key, &vis);
	mlx_loop(vis.mlx);
	return (0);
}