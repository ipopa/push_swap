/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipopa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 14:35:41 by ipopa             #+#    #+#             */
/*   Updated: 2016/05/13 14:35:45 by ipopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		set_min(t_stack *la, t_opt *opt)
{
	t_stack *tmp;

	opt->total = 0;
	opt->pos = 0;
	tmp = la->next;
	opt->min = la->value;
	while (tmp != la)
	{
		if (tmp->value < opt->min)
		{
			opt->min = tmp->value;
			opt->pos = opt->total;
		}
		tmp = tmp->next;
		opt->total++;
	}
}

void		algo_suite(t_stack **la, t_stack **lb, t_opt *opt)
{
	while ((*la)->next != *la)
	{
		set_min(*la, opt);
		while ((*la)->value != opt->min)
		{
			if ((*la)->next->value == opt->min)
				opt->op += sa(*la, *lb, opt);
			else if ((*la)->prec->value == opt->min)
				opt->op += rra(la, lb, opt);
			else
			{
				if (opt->pos < (opt->total) / 2)
					opt->op += ra(la, lb, opt);
				else
					opt->op += rra(la, lb, opt);
			}
		}
		if (sorted_stack(*la))
			break ;
		opt->op += pb(la, lb, opt);
	}
}

void		algo(t_stack **la, t_stack **lb, t_opt *opt)
{
	if (check_case(la, lb, opt))
		return ;
	algo_suite(la, lb, opt);
	while (*lb != NULL)
		opt->op += pa(la, lb, opt);
}
