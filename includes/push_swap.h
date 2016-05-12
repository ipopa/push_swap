/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 15:50:01 by sbeaufil          #+#    #+#             */
/*   Updated: 2015/10/29 19:27:26 by sbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_stack	t_stack;
typedef struct s_opt	t_opt;
typedef struct s_min	t_min;

struct					s_opt
{
	int		op;
	int		color;
	int		print;
	int		state;
	int		pos;
	int		min;
	int		total;
};

struct					s_stack
{
	int				value;
	t_stack			*next;
	t_stack			*prec;
};

void					ft_error(void);
int						pa(t_stack **a, t_stack **b, t_opt *opt);
int						pb(t_stack **a, t_stack **b, t_opt *opt);
int						sa(t_stack *a, t_stack *b, t_opt *opt);
int						sb(t_stack *a, t_stack *b, t_opt *opt);
int						ss(t_stack *a, t_stack *b, t_opt *opt);
int						ra(t_stack **a, t_stack **b, t_opt *opt);
int						rb(t_stack **a, t_stack **b, t_opt *opt);
int						rs(t_stack **a, t_stack **b, t_opt *opt);
int						rra(t_stack **a, t_stack **b, t_opt *opt);
int						rrb(t_stack **a, t_stack **b, t_opt *opt);
int						rrs(t_stack **a, t_stack **b, t_opt *opt);
void					algo(t_stack **a, t_stack **b, t_opt *opt);
int						sorted_stack(t_stack *stack);
t_stack					*init_stack(int val);
void					print_op(t_opt *opt);
void					print_spec(char *s, t_stack *a, t_stack *b, t_opt *opt);
int						set_opt(char **av, t_opt *opt);
int						check_doublon(char **av);
int						check_arg(int ac, char **av);
void					init_opt(t_opt *opt);
void					print_list(t_stack *stack);
int						check_case(t_stack **la, t_stack **lb, t_opt *opt);

#endif
