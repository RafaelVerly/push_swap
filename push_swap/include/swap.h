/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:34:04 by rverly            #+#    #+#             */
/*   Updated: 2023/01/03 17:27:27 by rverly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>

typedef struct s_list
{
	int				num;
	struct s_list	*next;
}	t_list;

void	ft_swap(t_list **list, char c);
void	ft_rotate(t_list **list, char c);
void	ft_reverse_rotate(t_list **list, char c);
void	ft_push(t_list **a, t_list **b, int id);
void	ft_push_b(t_list **a, t_list **b);
int		ft_check_number(char *num);
int		ft_check_dup(t_list *stk, int num);
void	ft_add(t_list **element, int number);
t_list	*ft_list_last(t_list *list);
int		ft_last_number(t_list *list);
int		ft_higher(t_list *a);
int		*ft_sort_array(t_list **a, int args);
int		*ft_bubble_sort(int *arr, int n);
int		*ft_fill_list(int *organizado, t_list **a);
int		ft_build_stack(char **argv, t_list **a, int qntd);
int		ft_validate(char **argv, int qntd, t_list **a);
size_t	ft_list_len(t_list *list);
t_list	*ft_list_last(t_list *list);
void	ft_clear_list(t_list **list);
void	ft_func_move_30(t_list **stackA, t_list **stackB, int num);
int		ft_is_sorted(t_list *list);
void	ft_five_sort(t_list **a, t_list **b);
void	ft_three_sort(t_list **a);
int		ft_move(t_list **a, t_list **b);
void	ft_move_20(t_list **a, t_list **b, int size_b, int limit);
void	ft_five_sort_b(t_list **a, t_list **b);
void	ft_three_sort_b(t_list **a);
void	ft_push_to_a(t_list **a, t_list **b, int *sorted, int size);
void	ft_push_to_b(t_list **a, t_list **b, int *sorted, int size);
void	ft_five_to_a(t_list **a, t_list **b);
#endif
