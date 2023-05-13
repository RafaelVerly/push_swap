/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:47:20 by rverly            #+#    #+#             */
/*   Updated: 2023/01/03 15:31:15 by rverly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/swap.h"

void	ft_move_and_push(t_list **a, t_list **b)
{
	ft_move(&*a, &*b);
	ft_push(&*a, &*b, 'A');
}

void	ft_move_20(t_list **a, t_list **b, int size_b, int limit)
{
	int	i;
	int	stop;

	i = 0;
	stop = size_b * 0.20;
	while (i < stop)
	{
		if ((*b)->num < ft_last_number(*b))
			ft_rotate(&*b, 'b');
		else
		{
			if ((*b)->num >= limit)
			{
				ft_move_and_push(&*a, &*b);
				i++;
			}
			else
				ft_rotate(&*b, 'b');
		}
	}
}

void	ft_func_move_30(t_list **a, t_list **b, int num)
{
	int	size;
	int	i;

	i = 0;
	size = ft_list_len(*a) * 0.17;
	while (i < size)
	{
		if ((*a)->num <= num)
		{
			ft_push(&*a, &*b, 'B');
			i++;
		}
		else
			ft_rotate(&*a, 'a');
	}
}

int	ft_move(t_list **a, t_list **b)
{
	int	high;

	high = ft_higher(*a);
	while (42)
	{
		if ((*b)->num > (*a)->num)
			ft_rotate(&*a, 'a');
		if ((*b)->num < (*a)->num)
		{
			if (ft_last_number(*a) != high && (*b)->num < ft_last_number(*a))
				ft_reverse_rotate(&*a, 'a');
			else
				return (1);
		}	
	}
}
