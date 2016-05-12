/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 12:14:19 by sbeaufil          #+#    #+#             */
/*   Updated: 2015/10/29 19:43:05 by sbeaufil         ###   ########.fr       */
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
