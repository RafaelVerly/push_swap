/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:28:39 by rverly            #+#    #+#             */
/*   Updated: 2023/01/03 16:52:01 by rverly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/swap.h"

int	*ft_sort_array(t_list **a, int args)
{
	int	*sorted_array;

	sorted_array = malloc((args) * sizeof (int));
	sorted_array = ft_fill_list(sorted_array, &*a);
	sorted_array = ft_bubble_sort(sorted_array, args);
	return (sorted_array);
}

void	ft_clear_list(t_list **list)
{
	t_list	*temp;

	while (*list)
	{
		temp = *list;
		*list = (*list)->next;
		free(temp);
	}
}

int	ft_validate(char **argv, int qntd, t_list **a)
{
	int	i;
	int	j;

	i = 1;
	while (i < qntd)
	{
		j = 0;
		if (argv[i][0] == '-' || argv[i][0] == '+')
			j = 1;
		if (!argv[i][j])
			return (0);
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (0);
			j++;
		}
			i++;
	}
	if (ft_build_stack(&*argv, a, qntd))
		return (1);
	else
		return (0);
}

int	ft_build_stack(char **argv, t_list **a, int qntd)
{
	int	i;
	int	number;

	i = 1;
	while (i < qntd)
	{
		if (ft_check_number(argv[i]))
			number = ft_atoi(argv[i]);
		else
		{
			ft_clear_list(&*a);
			return (0);
		}
		if (!ft_check_dup(*a, number))
		{
			ft_clear_list(&*a);
			return (0);
		}
		ft_add(a, number);
		i++;
	}
	return (1);
}
