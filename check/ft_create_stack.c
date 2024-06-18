/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:58:17 by anbourge          #+#    #+#             */
/*   Updated: 2021/09/28 20:03:31 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_check_arg_utils(char **argv, int i, int j)
{
	long long	temp;

	while (argv[i + 1][j])
	{
		while (argv[i + 1][j] == ' ')
			j++;
		if (argv[i + 1][j])
		{
			temp = ft_atoi(argv[i + 1], j);
			if (temp < -2147483648 || temp > 2147483647)
				return (-1);
			while (((ft_isdigit(argv[i + 1][j])))
			|| (argv[i + 1][j] == '-' && ft_isdigit(argv[i + 1][j + 1])))
				j++;
		}
	}
	return (j);
}

int	ft_create_list_utils(char **argv, int *i, t_list *tmp, t_list *list)
{
	while (i[0] < (i[1] - 1))
	{
		if (!(ft_check_arg(argv, i[0])))
			return (0);
		if (i[0] != 0)
			i[2] = 0;
		while (argv[i[0] + 1][i[2]])
		{
			while (argv[i[0] + 1][i[2]] == ' ')
				i[2]++;
			if (argv[i[0] + 1][i[2]])
			{
				list->next = ft_lst_crtelm((int)ft_atoi(argv[i[0] + 1], i[2]));
				tmp = list;
				list = list->next;
				list->prev = tmp;
				while (((ft_isdigit(argv[i[0] + 1][i[2]])))
				|| (argv[i[0] + 1][i[2]] == '-'
				&& (ft_isdigit(argv[i[0] + 1][i[2] + 1]))))
					i[2]++;
			}
		}
		i[0]++;
	}
	return (1);
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

t_list	*ft_create_stack2(t_list *list, t_list *res, t_list **bgnlst, int *i)
{
	t_list	*tmp;

	while (++i[1] < i[0])
		list = list->next;
	i[2] = list->data;
	i[1] = 1;
	list = *bgnlst;
	while (list)
	{
		if (list->data < i[2])
			i[1]++;
		list = list->next;
	}
	list = *bgnlst;
	if (i[0] == 0)
		res = ft_list_create_elem(i[1]);
	else
	{
		res->next = ft_list_create_elem(i[1]);
		tmp = res;
		res = res->next;
		res->prev = tmp;
	}
	return (res);
}
