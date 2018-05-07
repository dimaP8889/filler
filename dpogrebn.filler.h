/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dpogrebn.filler.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:58:19 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/04/23 13:58:20 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DPOGREBN_FILLER_H
# define DPOGREBN_FILLER_H

#include "libft/includes/libft.h"
#include "libft/includes/get_next_line.h"
#include "libft/ft_printf/ft_printf.h"

typedef struct 	s_flr
{
	int			player;
	char		let;
	char		op;
	char		**map;
	char		**piece;
}				t_flr;

void	ft_fill(t_flr flr);

#endif