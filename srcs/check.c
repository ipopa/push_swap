/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipopa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 14:37:56 by ipopa             #+#    #+#             */
/*   Updated: 2016/05/13 14:37:58 by ipopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_doublon(char **av)
{
	int i;
	int y;

	i = 0;
	while (av[i + 1] != NULL)
	{
		y = i + 1;
		while (av[y])
		{
			if (ft_strequ(av[i], av[y]))
				return (1);
			y++;
		}
		i++;
	}
	return (0);
}

int		check_arg(int ac, char **av)
{
  int		i;

  i = 0;
  while (i < ac)
    {
      if (ft_atoi(av[i]) == 0 && !(ft_strequ(av[i], "0")))
	return 1;
      i++;
    }
  return 0;
}
