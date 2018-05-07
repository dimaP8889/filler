/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dpogrebn.filler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:58:05 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/04/23 13:58:06 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dpogrebn.filler.h"

void	ft_print(t_flr flr)
{
	int coun;

	coun = 0;
	while (flr.map[coun])
	{
		ft_printf("%s\n", flr.map[coun]);
		coun++;
	}
	coun = 0;
	while (flr.piece[coun])
	{
		ft_printf("%s\n", flr.piece[coun]);
		coun++;
	}
}

int		ft_check_player(int fd)
{
	char *str;
	while (get_next_line(fd, &str))
	{
		if (ft_strstr(str, "carli.filler"))
		{
			get_next_line(fd, &str);
			if (ft_strstr(str, "p1"))
				return (1);
			else if (ft_strstr(str, "p2"))
				return (2);
		}
	}
	return(0);
}

char	**ft_fill_map(int fd, int hei_c, char **map)
{
	char		*str;
	int			coun;
	static int	c;

	coun = 0;
	if (!c)
	{
		get_next_line(fd, &str);
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

void 	ft_read(t_flr flr, int fd)
{
	static int 	check;
	char		*str;

	if (!check)
	{
		flr.player = ft_check_player(fd);
		if (flr.player == 1)
		{
			flr.let = 'O';
			flr.op = 'X';
		}
		else if (flr.player == 2)
		{
			flr.let = 'X';
			flr.op = 'O';
		}
		check = 1;
	}
	/*else*/
	{
		get_next_line(fd, &str);
		flr.map = ft_get_size(str, fd);
		get_next_line(fd, &str);
		flr.piece = ft_get_size(str, fd);
		ft_print(flr);
		ft_fill(flr);
	}
}

int		main(void)
{
	t_flr	flr;

	int fd;
	flr.player = 0;
	fd = open("read", O_RDONLY);
	// while (1)
	// {
	ft_read(flr, fd);
	// }
}