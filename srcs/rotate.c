/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipopa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 14:39:02 by ipopa             #+#    #+#             */
/*   Updated: 2016/05/13 14:39:03 by ipopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ra(t_stack **a, t_stack **b, t_opt *opt)
{
	if ((*a)->next == *a)
		return (0);
	*a = (*a)->next;
	if (opt->color || opt->state)
		print_spec("ra ", *a, *b, opt);
	else
		write(1, "ra ", 3);
	return (1);
}

int		rb(t_stack **a, t_stack **b, t_opt *opt)
{
	if ((*b)->next == *b)
		return (0);
	*b = (*b)->next;
	if (opt->color || opt->state)
		print_spec("rb ", *a, *b, opt);
	else
		write(1, "rb ", 3);
	return (1);
}

int		rr(t_stack **a, t_stack **b, t_opt *opt)
{
	if ((*a)->next == *a || (*b)->next == *b)
		return (0);
	*a = (*a)->next;
	*b = (*b)->next;
	if (opt->color || opt->state)
		print_spec("rr ", *a, *b, opt);
	else
		write(1, "rr ", 3);
	return (1);
}
