/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 15:54:31 by sbeaufil          #+#    #+#             */
/*   Updated: 2015/10/29 19:45:48 by sbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		add_list(t_stack **stack, int val)
{
	t_stack	*new;

	if (*stack == NULL)
		*stack = init_stack(val);
	else
	{
		if ((new = (t_stack *)malloc(sizeof(t_stack))) == NULL)
			return ;
		new->value = val;
		new->prec = (*stack)->prec;
		(*stack)->prec->next = new;
		new->next = *stack;
		(*stack)->prec = new;
	}
}

int			sorted_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next != stack)
	{
		if ((tmp->value) > (tmp->next->value))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int			push_swap(int ac, char **av, t_opt *opt)
{
	t_stack		*a;
	t_stack		*b;
	int			i;

	a = NULL;
	b = NULL;
	i = -1;
	while (av[++i] != NULL)
		add_list(&a, ft_atoi(av[i]));
	if (sorted_stack(a))
		return (1);
	algo(&a, &b, opt);
	write(1, "\n", 1);
	if (opt->print)
		print_op(opt);
	return (0);
}

int			main(int ac, char **av)
{
	t_opt		*opt;
	int			i;

	opt = (t_opt *)malloc(sizeof(t_opt));
	init_opt(opt);
	i = set_opt(av, opt);
	if ((ac - i) < 2)
		ft_error();
	else if (check_arg(ac - i, &(av[i])))
		ft_error();
	else if (check_doublon(&(av[i])))
		ft_error();
	else
		push_swap(ac, &(av[i]), opt);
	return (0);
}
