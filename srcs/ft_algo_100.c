/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:32:05 by anbourge          #+#    #+#             */
/*   Updated: 2021/09/28 17:45:54 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_algorithm_main(t_list **bgnl_a, int chunk_size)
{
	t_list	**bgnl_b;
	t_list	*list_b;
	int		chunk[2];
	int		size;

	size = ft_list_size(*bgnl_a);
	chunk[0] = 1;
	chunk[1] = chunk_size;
	bgnl_b = malloc(sizeof(t_list));
	if (!bgnl_b)
		return ;
	while (chunk[0] < size)
	{
		ft_algorithm_chunks(bgnl_a, bgnl_b, chunk);
		chunk[0] = chunk[1] + 1;
		chunk[1] = chunk[1] + chunk_size;
	}
	list_b = *bgnl_b;
	while (list_b)
	{
		ft_push(bgnl_a, bgnl_b, 'a');
		list_b = *bgnl_b;
	}
	ft_clear_list(bgnl_b);
}

int	ft_algorithm_check_chunk(t_list **bgnl, int *chunk)
{
	t_list	*list;

	list = *bgnl;
	while (list)
	{
		if (list->data >= chunk[0] && list->data <= chunk[1])
			return (1);
		list = list->next;
	}
	return (0);
}

void	ft_algorithm_chunks(t_list **bgnl_a, t_list **bgnl_b, int *chunk)
{
	int		*hold;
	int		*i;

	hold = malloc(sizeof(int) * 2);
	if (!hold)
		return ;
	i = malloc(sizeof(int));
	if (!i)
		return ;
	while (ft_algorithm_check_chunk(bgnl_a, chunk))
	{
		ft_algorithm_create_holds(bgnl_a, hold, chunk);
		ft_algorithm_pp(bgnl_a, bgnl_b, hold, i);
	}
	while (i[0] > 0)
	{
		ft_reverse_rotate(bgnl_b, bgnl_a, 'b');
		i[0]--;
	}
	free(hold);
	free(i);
}

void	ft_algorithm_create_holds(t_list **bgnl_a, int *hold, int *chunk)
{
	t_list	*list_a;

	list_a = *bgnl_a;
	hold[0] = 0;
	hold[1] = 0;
	while ((list_a->data < chunk[0] || list_a->data > chunk[1]) && list_a)
	{
		hold[0]++;
		list_a = list_a->next;
	}
	list_a = ft_list_last(list_a);
	while ((list_a->data < chunk[0] || list_a->data > chunk[1]) && list_a)
	{
		hold[1]++;
		list_a = list_a->prev;
	}
	if (hold[0] <= hold[1])
		hold[1] = -1;
	else
		hold[0] = -1;
}

int	ft_execute(t_list **begin_list, t_list **bgnl)
{
	ft_create_stack(begin_list, bgnl, ft_list_size(*begin_list));
	ft_algo_choose(bgnl);
	ft_clear_list(begin_list);
	ft_clear_list(bgnl);
	return (0);
}
