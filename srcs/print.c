/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 12:06:46 by sbeaufil          #+#    #+#             */
/*   Updated: 2015/10/29 20:04:19 by sbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		print_list(t_stack *stack)
{
	t_stack		*tmp;

	tmp = stack;
	if (stack == NULL)
		return ;
	while (tmp->next != stack)
	{
		ft_putnbr(tmp->value);
		write(1, " ", 1);
		tmp = tmp->next;
	}
	ft_putnbr(tmp->value);
}

void		print_op(t_opt *opt)
{
	write(1, "\nNombre d'operation = ", 23);
	ft_putnbr(opt->op);
	write(1, "\n", 1);
}

void		print_color(char *str)
{
	if (ft_strequ(str, "sa "))
		write(1, "\033[31;01msa \033[00m", 17);
	else if (ft_strequ(str, "sb "))
		write(1, "\033[31;01msb \033[00m", 17);
	else if (ft_strequ(str, "ss "))
		write(1, "\033[31;01mss \033[00m", 17);
	else if (ft_strequ(str, "ra "))
		write(1, "\033[32;01mra \033[00m", 17);
	else if (ft_strequ(str, "rb "))
		write(1, "\033[32;01mrb \033[00m", 17);
	else if (ft_strequ(str, "rr "))
		write(1, "\033[32;01mrs \033[00m", 17);
	else if (ft_strequ(str, "rra "))
		write(1, "\033[33;01mrra \033[00m", 18);
	else if (ft_strequ(str, "rrb "))
		write(1, "\033[33;01mrrb \033[00m", 18);
	else if (ft_strequ(str, "rrr "))
		write(1, "\033[33;01mrrr \033[00m", 18);
	else if (ft_strequ(str, "pa "))
		write(1, "\033[34;01mpa \033[00m", 17);
	else if (ft_strequ(str, "pb "))
		write(1, "\033[37;01mpb \033[00m", 17);
	else
		write(1, "error\n", ft_strlen(str));
}

void		print_spec(char *s, t_stack *a, t_stack *b, t_opt *opt)
{
	if (opt->color)
		print_color(s);
	else
		write(1, s, ft_strlen(s));
	if (opt->state)
	{
		write(1, "\npile a apres operation : ", 26);
		print_list(a);
		write(1, "\npile b apres operation : ", 26);
		print_list(b);
		write(1, "\n\n", 2);
	}
}
