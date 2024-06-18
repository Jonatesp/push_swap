/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 19:18:31 by anbourge          #+#    #+#             */
/*   Updated: 2021/09/28 17:43:36 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_swap(t_list *list, t_list *list2, char s)
{
	int		temp;
	t_list	*ltemp;

	if (s == 'a')
		ft_putstr_fd("sa\n", 1);
	if (s == 'b')
		ft_putstr_fd("sb\n", 1);
	temp = list->data;
	ltemp = list;
	list = list->next;
	ltemp->data = list->data;
	list->data = temp;
	if (s == 's')
	{
		ft_swap(list2, list2, 'c');
		ft_putstr_fd("ss\n", 1);
	}
	return (0);
}

int	ft_push(t_list **begin_list, t_list **begin_list2, char p)
{
	t_list	*list;
	t_list	*list2;
	int		data;

	list = *begin_list;
	list2 = *begin_list2;
	if (p == 'a')
	{
		if (ft_list_size(list2) < 1)
			return (0);
		data = list2->data;
		ft_list_del_front(begin_list2, list2);
		ft_list_add_front(begin_list, ft_list_create_elem(data));
		ft_putstr_fd("pa\n", 1);
	}
	if (p == 'b')
	{
		if (ft_list_size(list) < 1)
			return (0);
		data = list->data;
		ft_list_del_front(begin_list, list);
		ft_list_add_front(begin_list2, ft_list_create_elem(data));
		ft_putstr_fd("pb\n", 1);
	}
	return (0);
}

int	ft_push_tmp(t_list **begin_list, t_list **begin_list2)
{
	t_list	*list;
	t_list	*list2;
	int		data;
	int		chunk;

	list = *begin_list;
	list2 = *begin_list2;
	if (ft_list_size(list) < 1)
		return (0);
	data = list->data;
	chunk = list->chunk;
	ft_list_del_front(begin_list, list);
	ft_list_add_back(begin_list2, ft_list_create_elem(data));
	return (0);
}

int	ft_rotate(t_list **begin_list, t_list **begin_list2, char r)
{
	t_list	*list;
	t_list	*list2;
	int		data;

	list = *begin_list;
	list2 = *begin_list2;
	if (r == 'a')
		ft_putstr_fd("ra\n", 1);
	if (r == 'b')
		ft_putstr_fd("rb\n", 1);
	data = (int)list->data;
	ft_list_del_front(begin_list, list);
	ft_list_add_back(begin_list, ft_list_create_elem(data));
	if (r == 'r')
	{
		ft_rotate(begin_list2, begin_list2, 'c');
		ft_putstr_fd("rr\n", 1);
	}
	return (0);
}

int	ft_reverse_rotate(t_list **begin_list, t_list **begin_list2, char r)
{
	t_list	*list;
	t_list	*list2;
	int		data;

	list = *begin_list;
	list2 = *begin_list2;
	if (r == 'a')
		ft_putstr_fd("rra\n", 1);
	if (r == 'b')
		ft_putstr_fd("rrb\n", 1);
	list = ft_list_last(list);
	data = list->data;
	list = *begin_list;
	ft_list_del_back(begin_list, list);
	ft_list_add_front(begin_list, ft_list_create_elem(data));
	if (r == 'r')
	{
		ft_reverse_rotate(begin_list2, begin_list2, 'c');
		ft_putstr_fd("rrr\n", 1);
	}
	return (0);
}
