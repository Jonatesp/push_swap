/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:07:37 by anbourge          #+#    #+#             */
/*   Updated: 2021/09/28 18:41:20 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_algo_choose(t_list **begin_list)
{	
	int	size;

	size = ft_list_size(*begin_list);
	if (size < 4)
		ft_algo_under_three(begin_list);
	else if (size < 6)
		ft_algo_under_five(begin_list, size);
	else if (size <= 36)
		ft_algorithm_main(begin_list, size / 4);
	else if (size > 36)
		ft_algorithm_main(begin_list, size / 12);
}

void	ft_clear_list(t_list **begin_list)
{
	t_list	*list;
	t_list	*tmp;

	list = *begin_list;
	tmp = list;
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	free(begin_list);
}

void	ft_algo_under_three(t_list **begin_list)
{
	t_list	*list;
	t_list	*temp;
	t_list	*temp2;

	list = *begin_list;
	temp = list->next;
	if (ft_list_size(*begin_list) == 2 && list->data > temp->data)
	{
		ft_swap(*begin_list, *begin_list, 'a');
		exit(0);
	}
	temp2 = temp->next;
	if (list->data > temp->data && temp2->data > list->data)
		ft_swap(*begin_list, *begin_list, 'a');
	else if (list->data > temp->data && temp->data > temp2->data)
	{
		ft_swap(*begin_list, *begin_list, 'a');
		ft_reverse_rotate(begin_list, begin_list, 'a');
	}
	else
		ft_three_utils(begin_list, list, temp, temp2);
}

void	ft_algo_under_five(t_list **bgnl_a, int size)
{
	t_list	*list_a;
	t_list	**bgnl_b;
	int		i;

	bgnl_b = malloc(sizeof(t_list));
	if (!bgnl_b)
		return ;
	list_a = *bgnl_a;
	i = 0;
	while (list_a->data != 1)
	{
		list_a = list_a->next;
		i++;
	}
	if (size == 4)
		ft_algo_size_four(bgnl_a, bgnl_b, i);
	if (size == 5)
		ft_algo_size_five(bgnl_a, bgnl_b, i);
	ft_clear_list(bgnl_b);
}

void	ft_algo_size_four(t_list **bgnl_a, t_list **bgnl_b, int i)
{
	if (i < 3)
	{
		while (i)
		{
			ft_rotate(bgnl_a, bgnl_b, 'a');
			i--;
		}
	}
	else
	{
		while (i <= 3)
		{
			ft_reverse_rotate(bgnl_a, bgnl_b, 'a');
			i++;
		}
	}
	ft_push(bgnl_a, bgnl_b, 'b');
	ft_algo_under_three(bgnl_a);
	ft_push(bgnl_a, bgnl_b, 'a');
}
