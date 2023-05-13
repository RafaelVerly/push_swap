/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:20:03 by rverly            #+#    #+#             */
/*   Updated: 2023/01/03 14:24:36 by rverly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/swap.h"

int	ft_check_number(char *num)
{
	int		plus_signal;
	char	*num_dif;

	plus_signal = 0;
	if (num[0] == '+')
		plus_signal = 1;
	num_dif = ft_itoa(ft_atoi(num));
	if (ft_strncmp(num_dif, num + plus_signal, ft_strlen(num_dif)))
	{
		free (num_dif);
		return (0);
	}
	free (num_dif);
	return (1);
}

int	ft_check_dup(t_list *stk, int num)
{
	while (stk)
	{
		if (num == stk->num)
			return (0);
		stk = stk->next;
	}
	return (1);
}
