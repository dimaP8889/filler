/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 19:59:52 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/05/10 20:13:33 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

#include "../minilibx/mlx.h"

typedef struct 	s_mlx
{
	void		*mlx;
	void		*wnd;
	void		*img;
	char		**map;
}

#endif