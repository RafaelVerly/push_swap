/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:09:53 by rverly            #+#    #+#             */
/*   Updated: 2023/01/03 16:14:04 by rverly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/swap.h"

void	ft_three_sort(t_list **a)
{
	while (!ft_is_sorted(*a))
	{
		if ((*a)->num > (*a)->next->num)
			ft_swap(&*a, 'a');
		else
			ft_reverse_rotate(&*a, 'a');
	}
}

int	ft_higher(t_list *a)
{
	int		higher;
	t_list	*temp;

	temp = a;
	higher = temp->num;
	while (temp)
	{
		if (temp->num > higher)
			higher = temp->num;
		temp = temp->next;
	}
	return (higher);
}

int	ft_lower(t_list *a)
{
	int		lower;
	t_list	*temp;

	temp = a;
	lower = temp->num;
	while (temp)
	{
		if (temp->num < lower)
			lower = temp->num;
		temp = temp->next;
	}
	return (lower);
}

void	ft_five_sort(t_list **a, t_list **b)
{
	int	smallest;

	while (42)
	{
		smallest = ft_lower(*a);
		if ((*a)->num == smallest)
			ft_push(&*a, &*b, 'B');
		else
		{
			if (ft_last_number(*a) == smallest)
				ft_reverse_rotate(&*a, 'a');
			else
				ft_rotate(&*a, 'a');
		}
		if (ft_list_len(*a) == 3)
		{
			ft_three_sort(&*a);
			ft_push(&*a, &*b, 'A');
			if (*b)
				ft_push(&*a, &*b, 'A');
			break ;
		}
	}
}

void	ft_five_to_a(t_list **a, t_list **b)
{
	int	size_b;
	int	high;

	size_b = ft_list_len(*b);
	while (size_b > 0)
	{
		high = ft_higher(*b);
		if ((*b)->num == high)
		{
			ft_move(&*a, &*b);
			ft_push(&*a, &*b, 'A');
			size_b--;
		}
		if (size_b > 1)
			ft_rotate(&*b, 'b');
		else
			while (ft_last_number(*a) < (*a)->num)
				ft_reverse_rotate(&*a, 'a');
	}
}
