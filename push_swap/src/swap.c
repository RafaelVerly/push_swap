/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:34:25 by rverly            #+#    #+#             */
/*   Updated: 2023/01/03 16:02:02 by rverly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/swap.h"

void	ft_swap(t_list **list, char c)
{
	t_list	*temp;

	temp = *list;
	*list = (*list)->next;
	temp->next = (*list)->next;
	(*list)->next = temp;
	if (c == 'a')
		ft_putstr_fd("sa\n", 1);
	if (c == 'b')
		ft_putstr_fd("sb\n", 1);
}

void	ft_rotate(t_list **list, char c)
{
	t_list	*temp;
	t_list	*last;

	temp = *list;
	last = ft_list_last(*list);
	(*list) = (*list)->next;
	last->next = temp;
	temp->next = NULL;
	if (c == 'a')
		ft_putstr_fd("ra\n", 1);
	if (c == 'b')
		ft_putstr_fd("rb\n", 1);
}

void	ft_reverse_rotate(t_list **list, char c)
{
	t_list	*temp;
	t_list	*last;

	last = ft_list_last(*list);
	temp = *list;
	while ((*list)->next->next)
		*list = (*list)->next;
	last->next = temp;
	(*list)->next = NULL;
	*list = last;
	if (c == 'a')
		ft_putstr_fd("rra\n", 1);
	if (c == 'b')
		ft_putstr_fd("rrb\n", 1);
}

void	ft_push(t_list **a, t_list **b, int id)
{
	t_list	*temp_a;
	t_list	*temp_b;

	if (id == 'A')
	{
		if (!*b)
			return ;
		temp_b = *b;
		if (*a)
		{
			temp_a = *a;
			*b = (*b)->next;
			temp_b->next = temp_a;
			*a = temp_b;
		}
		ft_putstr_fd("pa\n", 1);
	}
	if (id == 'B')
		ft_push_b(&*a, &*b);
}

void	ft_push_b(t_list **a, t_list **b)
{
	t_list	*temp_a;
	t_list	*temp_b;

	if (!*a)
		return ;
	temp_a = *a;
	temp_b = *b;
	*a = (*a)->next;
	temp_a->next = temp_b;
	*b = temp_a;
	ft_putstr_fd("pb\n", 1);
}
