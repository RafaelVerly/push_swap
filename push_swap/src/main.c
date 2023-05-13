/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:02:58 by rverly            #+#    #+#             */
/*   Updated: 2023/01/03 16:48:47 by rverly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		*sorted_array;
	int		stack_size;
	int		size_org;

	a = NULL;
	b = NULL;
	stack_size = argc - 1;
	size_org = argc - 6;
	if (argc < 2)
		return (1);
	if (!(ft_validate(argv, argc, &a)))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	sorted_array = ft_sort_array(&a, stack_size);
	ft_push_to_b(&a, &b, sorted_array, stack_size);
	if (stack_size > 5)
		ft_push_to_a(&a, &b, sorted_array, size_org);
	free(sorted_array);
	ft_clear_list(&a);
}
