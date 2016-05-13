/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipopa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 14:38:19 by ipopa             #+#    #+#             */
/*   Updated: 2016/05/13 14:38:20 by ipopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack		*init_stack(int val)
{
	t_stack		*stack;

	if ((stack = (t_stack *)malloc(sizeof(t_stack))) == NULL)
	{
		write(2, "Error : Malloc Failed\n", 22);
		return (NULL);
	}
	stack->value = val;
	stack->next = stack;
	stack->prec = stack;
	return (stack);
}

void		init_opt(t_opt *opt)
{
	opt->state = 0;
	opt->print = 0;
	opt->color = 0;
	opt->op = 0;
}

int			check_opt(char *av, t_opt *opt)
{
	if (ft_strequ(av, "-v"))
		opt->state = 1;
	else if (ft_strequ(av, "-c"))
		opt->color = 1;
	else if (ft_strequ(av, "-p"))
		opt->print = 1;
	else
		return (0);
	return (1);
}

int			set_opt(char **av, t_opt *opt)
{
	int		i;

	i = 1;
	while (check_opt(av[i], opt))
		i++;
	return (i);
}
