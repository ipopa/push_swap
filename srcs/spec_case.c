/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipopa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 14:39:10 by ipopa             #+#    #+#             */
/*   Updated: 2016/05/13 14:39:11 by ipopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_sw(t_stack **a, t_opt *opt)
{
	t_stack		*cpy;
	int			tmp;
	int			sw;

	sw = 0;
	cpy = *a;
	tmp = cpy->value;
	cpy->value = cpy->next->value;
	cpy->next->value = tmp;
	if (sorted_stack(cpy))
		sw = 1;
	tmp = cpy->value;
	cpy->value = cpy->next->value;
	cpy->next->value = tmp;
	return (sw);
}

int		check_rw(t_stack **a, t_opt *opt)
{
	t_stack		*cpy;
	int			tmp;
	int			rw;

	rw = 0;
	cpy = *a;
	cpy = cpy->prec->prec;
	tmp = cpy->value;
	cpy->value = cpy->next->value;
	cpy->next->value = tmp;
	cpy = cpy->next->next;
	if (sorted_stack(cpy))
		rw = 1;
	cpy = cpy->prec->prec;
	tmp = cpy->value;
	cpy->value = cpy->next->value;
	cpy->next->value = tmp;
	cpy = cpy->next->next;
	return (rw);
}

int		check_r(t_stack **a, t_opt *opt)
{
	t_stack		*cpy;
	int			tmp;
	int			r;

	r = 0;
	cpy = *a;
	cpy = cpy->prec->prec;
	tmp = cpy->value;
	cpy->value = cpy->next->value;
	cpy->next->value = tmp;
	if (sorted_stack(cpy))
		r = 1;
	tmp = cpy->value;
	cpy->value = cpy->next->value;
	cpy->next->value = tmp;
	cpy = cpy->next->next;
	return (r);
}

int		check_case(t_stack **a, t_stack **b, t_opt *opt)
{
	if (check_sw(a, opt))
	{
		opt->op += sa(*a, *b, opt);
		return (1);
	}
	if (check_r(a, opt))
	{
		opt->op += rra(a, b, opt);
		opt->op += rra(a, b, opt);
		opt->op += sa(*a, *b, opt);
		return (1);
	}
	if (check_rw(a, opt))
	{
		opt->op += rra(a, b, opt);
		opt->op += rra(a, b, opt);
		opt->op += sa(*a, *b, opt);
		opt->op += ra(a, b, opt);
		opt->op += ra(a, b, opt);
		return (1);
	}
	return (0);
}
