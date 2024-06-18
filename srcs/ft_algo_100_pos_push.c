/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_100_pos_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:43:46 by anbourge          #+#    #+#             */
/*   Updated: 2021/09/28 18:28:59 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_algorithm_pp(t_list **bgnl_a, t_list **bgnl_b, int *hold, int *i)
{
	int		size;
	int		j;

	size = ft_list_size(*bgnl_b);
	j = ft_pp_upper_size(bgnl_a, bgnl_b, hold, i);
	if (j == 0)
	{
		while (hold[0]-- > 0)
			ft_rotate(bgnl_a, bgnl_b, 'a');
		while (hold[1]-- >= 0)
			ft_reverse_rotate(bgnl_a, bgnl_b, 'a');
		ft_push(bgnl_a, bgnl_b, 'b');
	}
}

int	ft_pp_def_data(t_list **bgnl_a, t_list **bgnl_b, int *hold)
{
	t_list	*list_a;
	t_list	*list_b;
	int		i;

	list_a = *bgnl_a;
	list_b = *bgnl_b;
	i = 0;
	if (hold[1] >= 0)
	{
		list_a = ft_list_last(*bgnl_a);
		while (i < hold[1])
		{
			list_a = list_a->prev;
			i++;
		}
	}
	else
	{
		while (i < hold[0])
		{
			list_a = list_a->next;
			i++;
		}
	}
	return (list_a->data);
}

void	ft_pp_upper_size2(t_list **bgnl_a, t_list **bgnl_b, int *hold, int *i)
{
	while (hold[0]-- > 0)
		ft_rotate(bgnl_a, bgnl_b, 'a');
	while (hold[1]-- >= 0)
		ft_reverse_rotate(bgnl_a, bgnl_b, 'a');
	while (i[0] > 0)
	{
		ft_reverse_rotate(bgnl_b, bgnl_b, 'b');
		i[0]--;
	}
	ft_push(bgnl_a, bgnl_b, 'b');
}

int	ft_pp_upper_size(t_list **bgnl_a, t_list **bgnl_b, int *hold, int *i)
{
	int		data;
	int		k;

	data = ft_pp_def_data(bgnl_a, bgnl_b, hold);
	k = ft_pp_define_b(bgnl_b, data, i);
	if (k == ft_list_size(*bgnl_b) && ft_list_size(*bgnl_b) > 0)
	{
		ft_pp_upper_size2(bgnl_a, bgnl_b, hold, i);
		while (k-- > 0)
			ft_reverse_rotate(bgnl_b, bgnl_b, 'b');
		return (1);
	}
	while (k > 0 && hold[0]-- > 0)
	{
		k--;
		ft_rotate(bgnl_a, bgnl_b, 'r');
		i[0]++;
	}
	while (k > 0)
	{
		ft_rotate(bgnl_b, bgnl_a, 'b');
		k--;
		i[0]++;
	}
	return (0);
}

int	ft_pp_define_b(t_list **bgnl_b, int data, int *i)
{
	t_list	*list_b;
	int		k;

	list_b = *bgnl_b;
	k = 0;
	while (list_b && list_b->data > data)
	{
		k++;
		list_b = list_b->next;
	}
	if (k == 0)
	{
		list_b = ft_list_last(*bgnl_b);
		while (i[0] > 0 && list_b->data < data)
		{
			ft_reverse_rotate(bgnl_b, bgnl_b, 'b');
			i[0]--;
			list_b = ft_list_last(*bgnl_b);
		}
	}
	return (k);
}
