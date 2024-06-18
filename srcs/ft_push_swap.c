/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:27:32 by anbourge          #+#    #+#             */
/*   Updated: 2021/09/28 19:47:08 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	*ft_puterror(t_list **begin_list)
{
	ft_clear_list(begin_list);
	ft_putstr_fd("Error\n", 2);
	exit(1);
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

int	main(int argc, char **argv)
{
	t_list	**begin_list;
	t_list	**bgnl;
	t_list	*list;

	begin_list = malloc(sizeof(t_list));
	if (!begin_list)
		return (0);
	if (argc < 2)
	{
		ft_clear_list(begin_list);
		return (0);
	}
	list = ft_create_list(argc, argv, begin_list);
	if (!list)
		ft_puterror(begin_list);
	*begin_list = list;
	if (ft_is_sort(begin_list))
	{
		ft_clear_list(begin_list);
		return (0);
	}
	bgnl = malloc(sizeof(t_list));
	if (!bgnl)
		return (0);
	return (ft_execute(begin_list, bgnl));
}
