/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 19:59:52 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/05/12 17:15:30 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# define	LEN 990
# define	HEI	600

# define LEN_P 990
# define HEI_P 600

# include "../minilibx/mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/ft_printf/ft_printf.h"

typedef	struct	s_im
{
	void		*img_ptr;
	int			*img_mas;
}				t_im;

typedef struct 	s_mlx
{
	void		*mlx;
	void		*wnd;
	t_im		img;
	char		**map;
	float		len;
	float		hei;
	int			map_num;
}				t_mlx;

typedef	struct	s_player
{
	int			p1;
	int			p2;
}				t_player;

void	ft_out(t_mlx *vis);
void	ft_init_image(t_mlx *data);

#endif