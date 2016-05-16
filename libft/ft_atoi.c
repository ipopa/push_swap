/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 19:52:18 by sbeaufil          #+#    #+#             */
/*   Updated: 2014/11/14 17:46:22 by sbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
  int	result;
  int sign;
  int i;
  char *tmpstr;

  result = 0;
  tmpstr = ft_strtrim(str);
  i = 0;
  sign = (tmpstr[i] == '-') ? -1 : 1;
  if (tmpstr[i] == '-' || tmpstr[i] == '+')
    i++;
  if ((ft_strcmp(tmpstr, INT_MAX_STR) > 0 && ft_strlen(tmpstr) == 10) || ft_strlen(tmpstr) > 10)
    sign = 0;
  while ((ft_isdigit(tmpstr[i]) == 1) && tmpstr[i])
    {
      result = (result * 10) + (tmpstr[i] - '0');
      i++;
    }
  if (tmpstr[i])
    sign = 0;
  free(tmpstr);
  return sign * result;
}
