/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 11:53:41 by sbeaufil          #+#    #+#             */
/*   Updated: 2015/10/29 19:56:06 by sbeaufil         ###   ########.fr       */
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
