/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipopa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 14:39:19 by ipopa             #+#    #+#             */
/*   Updated: 2016/05/13 14:39:20 by ipopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		sa(t_stack *a, t_stack *b, t_opt *opt)
{
	int		tmp;

	if (a->next == a)
		return (0);
	tmp = a->value;
	a->value = a->next->value;
	a->next->value = tmp;
	if (opt->color || opt->state)
		print_spec("sa ", a, b, opt);
	else
		write(1, "sa ", 3);
	return (1);
}

int		sb(t_stack *a, t_stack *b, t_opt *opt)
{
	int		tmp;

	if (b->next == b)
		return (0);
	tmp = b->value;
	b->value = b->next->value;
	b->next->value = tmp;
	if (opt->color || opt->state)
		print_spec("sb ", a, b, opt);
	else
		write(1, "sb ", 3);
	return (1);
}

int		ss(t_stack *a, t_stack *b, t_opt *opt)
{
	int		tmp;
	int		tmp2;

	if (a->next == a || b->next == b)
		return (0);
	tmp = a->value;
	a->value = a->next->value;
	a->next->value = tmp;
	tmp2 = b->value;
	b->value = b->next->value;
	b->next->value = tmp2;
	if (opt->color || opt->state)
		print_spec("ss ", a, b, opt);
	else
		write(1, "ss ", 3);
	return (1);
}
