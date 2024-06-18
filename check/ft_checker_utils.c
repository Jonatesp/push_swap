/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:23:27 by anbourge          #+#    #+#             */
/*   Updated: 2021/09/28 19:47:18 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	ft_check_arg(char **argv, int i)
{
	int			j;

	j = -1;
	while (argv[i + 1][++j])
	{
		while (argv[i + 1][j] == ' ')
			j++;
		if (!(argv[i + 1][j]))
			break ;
		if (!(ft_isdigit(argv[i + 1][j]))
			&& (!(argv[i + 1][j] == '-' && (ft_isdigit(argv[i + 1][j + 1])))))
			return (0);
	}
	j = 0;
	j = ft_check_arg_utils(argv, i, j);
	if (j == -1)
		return (0);
	return (1);
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

int	ft_is_sort(t_list **begin_list)
{
	int		i;
	t_list	*list;
	t_list	*temp;

	i = 0;
	list = *begin_list;
	temp = list->next;
	while (i < ft_list_size(*begin_list) - 1)
	{
		if (!(list->data < temp->data))
			return (0);
		list = list->next;
		temp = list->next;
		i++;
	}
	return (1);
}

t_list	*ft_create_list(int argc, char **argv, t_list **begin_list)
{
	t_list	*list;
	t_list	*tmp;
	int		i[3];
	int		j;

	i[0] = 0;
	i[1] = argc;
	j = 0;
	list = ft_list_create_elem((int)ft_atoi(argv[i[0] + 1], 0));
	*begin_list = list;
	while (argv[i[0] + 1][j] == ' ')
		j++;
	while (((ft_isdigit(argv[i[0] + 1][j])))
		|| (argv[i[0] + 1][j] == '-' && (ft_isdigit(argv[i[0] + 1][j + 1]))))
		j++;
	i[2] = j;
	tmp = list;
	if (ft_create_list_utils(argv, i, tmp, list) == 0)
		ft_puterror(begin_list);
	if (!(ft_check_double(begin_list)))
		ft_puterror(begin_list);
	return (*begin_list);
}
