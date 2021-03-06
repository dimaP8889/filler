/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converse_numb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 19:15:17 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/02/05 19:15:18 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_check_size(t_printf *params, t_size *size, void *number)
{
	if (!ft_strcmp(params->size, "l") || !ft_strcmp(params->convers, "D")
		|| !ft_strcmp(params->convers, "U") || !ft_strcmp(params->convers, "O"))
		ft_check_size_l(params, size, number);
	else if (!ft_strcmp(params->size, "hh"))
		ft_check_size_hh(params, size, number);
	else if (!ft_strcmp(params->size, "h"))
		ft_check_size_h(params, size, number);
	else if (!ft_strcmp(params->size, "ll"))
		ft_check_size_ll(params, size, number);
	else if (!ft_strcmp(params->size, "j"))
		ft_check_size_j(params, size, number);
	else if (!ft_strcmp(params->size, "z"))
		ft_check_size_z(params, size, number);
}

static void	ft_i_d_no_size(t_printf *params, t_size *size, void *number)
{
	size->i = (int)number;
	if (!size->i)
		params->check_zero = 1;
	if (size->i == -2147483648)
	{
		params->check_num = -1;
		params->string = ft_strjoin_free(&params->string, "2147483648");
	}
	else
	{
		if (size->i < 0)
		{
			params->check_num = -1;
			size->i = -size->i;
		}
		free(params->string);
		params->string = ft_itoa_base((size_t)size->i, params->base, 0);
	}
}

void		ft_check_no_size(t_printf *p, t_size *size, void *number)
{
	if (!ft_strcmp(p->convers, "d") || !ft_strcmp(p->convers, "i"))
		ft_i_d_no_size(p, size, number);
	else if (!ft_strcmp(p->convers, "o") || !ft_strcmp(p->convers, "u")
		|| !ft_strcmp(p->convers, "x") || !ft_strcmp(p->convers, "X"))
	{
		size->u_i = (unsigned int)number;
		!size->u_i ? (p->check_zero = 1) : 0;
		free(p->string);
		p->string = ft_itoa_base((size_t)size->u_i, p->base,
		(p->convers[0] == 'X' ? 1 : 0));
	}
	else if (!ft_strcmp(p->convers, "p"))
	{
		size->l = (long)number;
		if (!size->l)
			p->check_zero = 1;
		if (size->l < 0)
		{
			p->check_num = -1;
			size->l = -size->l;
		}
		free(p->string);
		p->string = ft_itoa_base((size_t)size->l, p->base, 0);
		p->flag = ft_addletter(p->flag, '#');
	}
}

void		ft_make_out(t_printf *params)
{
	int			count_perc;
	int			length;
	int			count;

	count_perc = params->precision;
	if (params->width > params->precision
	&& params->precision > (int)ft_strlen(params->string))
		length = params->width - params->precision;
	if (params->width > params->precision
	&& params->precision <= (int)ft_strlen(params->string))
		length = params->width - (int)ft_strlen(params->string);
	if (params->width <= params->precision)
		length = 0;
	count = length;
	if (ft_strcmp(params->width_char, ""))
		while (length-- > 0)
			params->out = ft_addletter(params->out, ' ');
	if (ft_strcmp(params->precision_char, ""))
		while (count_perc > (int)ft_strlen(params->string))
		{
			params->out_num = ft_addletter(params->out_num, '0');
			count_perc--;
		}
	params->out_num = ft_strjoin_free(&params->out_num, params->string);
	ft_make_flag(params);
}
