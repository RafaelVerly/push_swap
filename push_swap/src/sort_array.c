/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:31:47 by rverly            #+#    #+#             */
/*   Updated: 2023/01/03 16:12:55 by rverly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/swap.h"

void	ft_push_to_b(t_list **a, t_list **b, int *sorted, int size)
{
	int	lower;
	int	sub;

	lower = size * 0.17;
	sub = 0;
	while (size > 5)
	{
		ft_func_move_30(&*a, &*b, sorted[lower + sub]);
		size = ft_list_len(*a);
		sub += (size * 0.17);
	}
	if (size < 4)
		ft_three_sort(&*a);
	else
		ft_five_sort(&*a, &*b);
}

void	ft_push_to_a(t_list **a, t_list **b, int *sorted, int size)
{
	int	size_b;
	int	sub;
	int	higher;

	sub = 0;
	size_b = ft_list_len(*b);
	higher = size_b * 0.20;
	while (size_b > 5)
	{
		ft_move_20(&*a, &*b, size_b, sorted[size - (higher + sub)]);
		size_b = ft_list_len(*b);
		sub += (size_b * 0.20);
	}
	ft_five_to_a(&*a, &*b);
}

int	ft_is_sorted(t_list *list)
{
	t_list	*temp;

	temp = list;
	while (temp->next)
	{
		if (temp->num > temp->next->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}
