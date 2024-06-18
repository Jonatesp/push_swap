/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:12:24 by anbourge          #+#    #+#             */
/*   Updated: 2021/09/28 17:09:57 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_swap(t_list *list, t_list *list2, char s)
{
	int		temp;
	t_list	*ltemp;

	if (ft_list_size(list) < 2)
	{
		if (s == 's')
			ft_swap(list2, list2, 'c');
		return (0);
	}
	temp = list->data;
	ltemp = list;
	list = list->next;
	ltemp->data = list->data;
	list->data = temp;
	if (s == 's')
		ft_swap(list2, list2, 'c');
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
	}
	if (p == 'b')
	{
		if (ft_list_size(list) < 1)
			return (0);
		data = list->data;
		ft_list_del_front(begin_list, list);
		ft_list_add_front(begin_list2, ft_list_create_elem(data));
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
	if (ft_list_size(list) < 2)
	{
		if (r == 'r')
			ft_rotate(begin_list2, begin_list2, 'c');
		return (0);
	}
	data = (int)list->data;
	ft_list_del_front(begin_list, list);
	ft_list_add_back(begin_list, ft_list_create_elem(data));
	if (r == 'r')
		ft_rotate(begin_list2, begin_list2, 'c');
	return (0);
}

int	ft_reverse_rotate(t_list **begin_list, t_list **begin_list2, char r)
{
	t_list	*list;
	t_list	*list2;
	int		data;

	list = *begin_list;
	list2 = *begin_list2;
	if (ft_list_size(list) < 2)
	{
		if (r == 'r')
			ft_reverse_rotate(begin_list2, begin_list2, 'c');
		return (0);
	}
	list = ft_list_last(list);
	data = list->data;
	list = *begin_list;
	ft_list_del_back(begin_list, list);
	ft_list_add_front(begin_list, ft_list_create_elem(data));
	if (r == 'r')
		ft_reverse_rotate(begin_list2, begin_list2, 'c');
	return (0);
}
