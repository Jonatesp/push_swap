/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 02:28:06 by anbourge          #+#    #+#             */
/*   Updated: 2021/09/28 20:00:17 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_algo_size_five(t_list **bgnl_a, t_list **bgnl_b, int i)
{
	int		j;
	t_list	*list_a;

	if (i < 3)
	{
		while (i--)
			ft_rotate(bgnl_a, bgnl_b, 'a');
	}
	else
	{
		while (i++ <= 4)
			ft_reverse_rotate(bgnl_a, bgnl_b, 'a');
	}
	ft_push(bgnl_a, bgnl_b, 'b');
	list_a = *bgnl_a;
	j = 0;
	while (list_a->data != 5)
	{
		list_a = list_a->next;
		j++;
	}
	ft_algo_size_five2(bgnl_a, bgnl_b, j);
}

void	ft_algo_size_five2(t_list **bgnl_a, t_list **bgnl_b, int j)
{
	if (j < 3)
	{
		while (j--)
			ft_rotate(bgnl_a, bgnl_b, 'a');
	}
	else
	{
		while (j++ <= 3)
			ft_reverse_rotate(bgnl_a, bgnl_b, 'a');
	}
	ft_push(bgnl_a, bgnl_b, 'b');
	ft_algo_under_three(bgnl_a);
	ft_push(bgnl_a, bgnl_b, 'a');
	ft_rotate(bgnl_a, bgnl_b, 'a');
	ft_push(bgnl_a, bgnl_b, 'a');
}

int	ft_stack_position(t_list **begin_list, int b)
{
	t_list	*list;
	int		i;

	i = 1;
	list = *begin_list;
	while (b > list->data)
	{
		i++;
		list = list->next;
		if (!list)
			break ;
	}
	return (i);
}

void	ft_create_stack(t_list **begin_list, t_list **bgnl, int size)
{
	t_list	*list;
	t_list	*res;
	int		i[3];

	i[0] = 0;
	list = *begin_list;
	res = NULL;
	while (i[0] < size)
	{
		i[1] = -1;
		res = ft_create_stack2(list, res, begin_list, i);
		if (i[0] == 0)
			*bgnl = res;
		i[0]++;
	}
}

int	ft_check_double(t_list **begin_list)
{
	t_list	*list;
	int		tmp;
	int		i;
	int		j;

	i = 0;
	while (i < ft_list_size(*begin_list))
	{
		list = *begin_list;
		j = 0;
		while (j++ != i)
			list = list->next;
		tmp = list->data;
		list = *begin_list;
		j = 0;
		while (list)
		{
			if (tmp == list->data && j != i)
				return (0);
			j++;
			list = list->next;
		}
		i++;
	}
	return (1);
}
