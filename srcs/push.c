/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 12:08:58 by sbeaufil          #+#    #+#             */
/*   Updated: 2015/10/29 20:29:39 by sbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		pa(t_stack **a, t_stack **b, t_opt *opt)
{
	t_stack *new_a;
	t_stack *new_b;

	if ((*b) == NULL)
		return (0);
	new_a = *b;
	if ((*b)->next == *b)
		*b = NULL;
	else
	{
		new_b = (*b)->next;
		(*b)->next->prec = (*b)->prec;
		(*b)->prec->next = (*b)->next;
		*b = new_b;
	}
	new_a->prec = (*a)->prec;
	new_a->prec->next = new_a;
	(*a)->prec = new_a;
	new_a->next = *a;
	*a = new_a;
	if (opt->color || opt->state)
		print_spec("pa ", *a, *b, opt);
	else
		write(1, "pa ", 3);
	return (1);
}

void	pb_suite(t_stack **b, t_stack *new_b)
{
	new_b->prec = (*b)->prec;
	new_b->prec->next = new_b;
	(*b)->prec = new_b;
	new_b->next = *b;
	*b = new_b;
}

int		pb(t_stack **a, t_stack **b, t_opt *opt)
{
	t_stack *new_a;
	t_stack *new_b;

	if ((*a)->next == *a)
		return (0);
	new_a = (*a)->next;
	new_b = *a;
	(*a)->next->prec = (*a)->prec;
	(*a)->prec->next = (*a)->next;
	*a = new_a;
	if (*b == NULL)
	{
		new_b->prec = new_b;
		new_b->next = new_b;
		*b = new_b;
	}
	else
		pb_suite(b, new_b);
	if (opt->color || opt->state)
		print_spec("pb ", *a, *b, opt);
	else
		write(1, "pb ", 3);
	return (1);
}
