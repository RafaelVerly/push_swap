/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:40:41 by rverly            #+#    #+#             */
/*   Updated: 2023/01/03 14:45:58 by rverly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/swap.h"

size_t	ft_list_len(t_list *list)
{
	size_t	size;

	size = 0;
	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}

int	ft_last_number(t_list *list)
{
	t_list	*temp;

	temp = list;
	while (temp->next)
		temp = temp->next;
	return (temp->num);
}

void	ft_add(t_list **element, int number)
{
	t_list	*no;
	t_list	*temp;

	no = malloc(sizeof(t_list));
	no->next = NULL;
	no->num = number;
	if (!(*element))
		*element = no;
	else
	{
		temp = *element;
		while (temp->next)
		temp = temp->next;
		temp->next = no;
	}
}

int	*ft_fill_list(int *sort, t_list **a)
{
	t_list	*temp;
	int		i;

	temp = *a;
	i = 0;
	while (temp)
	{
		sort[i] = temp->num;
		temp = temp->next;
		i++;
	}
	return (sort);
}

t_list	*ft_list_last(t_list *list)
{
	t_list	*last;

	if (!list)
		return (NULL);
	last = list;
	while (last->next)
		last = last->next;
	return (last);
}
