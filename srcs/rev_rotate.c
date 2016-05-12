/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 11:59:03 by sbeaufil          #+#    #+#             */
/*   Updated: 2015/10/29 20:10:41 by sbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		rra(t_stack **a, t_stack **b, t_opt *opt)
{
	if ((*a)->prec == *a)
		return (0);
	*a = (*a)->prec;
	if (opt->color || opt->state)
		print_spec("rra ", *a, *b, opt);
	else
		write(1, "rra ", 4);
	return (1);
}

int		rrb(t_stack **a, t_stack **b, t_opt *opt)
{
	if ((*b)->prec == *b)
		return (0);
	*b = (*b)->prec;
	if (opt->color || opt->state)
		print_spec("rrb ", *a, *b, opt);
	else
		write(1, "rrb ", 4);
	return (1);
}

int		rrr(t_stack **a, t_stack **b, t_opt *opt)
{
	if ((*a)->prec == *a || (*b)->prec == *b)
		return (0);
	*a = (*a)->prec;
	*b = (*b)->prec;
	if (opt->color || opt->state)
		print_spec("rrr ", *a, *b, opt);
	else
		write(1, "rrr ", 4);
	return (1);
}
