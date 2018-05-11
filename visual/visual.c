/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 19:58:18 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/05/10 20:16:23 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

char	**ft_fill_map(int fd, int hei_c, char **map)
{
	char		*str;
	int			coun;
	static int	c;

	coun = 0;
	if (!c)
	{
		get_next_line(fd, &str);
		if (ft_strstr(str, ".") || ft_strstr(str, "*"))
			exit (1);
		c = 1;
	}
	else 
		c = 0;
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

char	**ft_get_size(char *str, int fd)
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
	while (hei > 0)
	{
		map[coun] = (char *)malloc(sizeof(char) * (len + 1));
		coun++;
		hei--;
	}
	map = ft_fill_map(fd, hei_c, map);
	return(map);
}

int		ft_visual(void *v)
{
	t_mlx	*vis;

	vis = (t_mlx *)v;
	vis.map = ft_get_size(str, fd);
}

int		main(void)
{
	t_mlx	vis;

	vis.mlx = mlx_init();
	vis.wnd = mlx_new_window(vis.mlx, 200, 300, "mlx 42");
	mlx_loop_hook(vis.mlx, ft_visual, &vis);
	mlx_loop(data.mlx);
	return (0);
}