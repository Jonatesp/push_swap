/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:12:17 by anbourge          #+#    #+#             */
/*   Updated: 2021/09/28 16:37:14 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	bgnl = malloc(sizeof(t_list));
	if (!bgnl)
		return (0);
	ft_create_stack(begin_list, bgnl, ft_list_size(*begin_list));
	ft_checker(bgnl);
	ft_clear_list(begin_list);
	ft_clear_list(bgnl);
	return (0);
}

void	*ft_puterror(t_list **begin_list)
{
	ft_clear_list(begin_list);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_checker(t_list **bgnl_a)
{
	t_list	**bgnl_b;
	char	*line;

	bgnl_b = malloc(sizeof(t_list));
	if (!bgnl_b)
		return ;
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == 's' || line[0] == 'p')
			ft_op_choose(bgnl_a, bgnl_b, line, 0);
		else if (line[0] == 'r')
			ft_rotate_choose(bgnl_a, bgnl_b, line, 0);
		else
		{
			ft_putstr_fd("Error\n", 2);
			ft_clear_list(bgnl_a);
			ft_clear_list(bgnl_b);
			exit(1);
		}
	}
	if (ft_is_sort(bgnl_a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

void	ft_op_choose(t_list **bgnl_a, t_list **bgnl_b, char *line, int i)
{
	if (line[i] == 's')
	{
		i++;
		if (line[i] == 'a')
			ft_swap(*bgnl_a, *bgnl_a, 'a');
		else if (line[i] == 'b')
			ft_swap(*bgnl_b, *bgnl_b, 'b');
		else if (line[i] == 's')
			ft_swap(*bgnl_a, *bgnl_b, 's');
	}
	else if (line[i] == 'p')
	{
		i++;
		if (line[i] == 'a')
			ft_push(bgnl_a, bgnl_b, 'a');
		if (line[i] == 'b')
			ft_push(bgnl_a, bgnl_b, 'b');
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
		ft_clear_list(bgnl_a);
		ft_clear_list(bgnl_b);
		exit(1);
	}
}

void	ft_rotate_choose(t_list **bgnl_a, t_list **bgnl_b, char *line, int i)
{
	i++;
	if (line[i] == 'r')
	{
		i++;
		if (line[i] == 'r')
			ft_reverse_rotate(bgnl_a, bgnl_b, 'r');
		else if (line[i] == 'a')
			ft_reverse_rotate(bgnl_a, bgnl_a, 'a');
		else if (line[i] == 'b')
			ft_reverse_rotate(bgnl_b, bgnl_b, 'b');
		else
			ft_rotate(bgnl_a, bgnl_b, 'r');
	}
	else if (line[i] == 'a')
		ft_rotate(bgnl_a, bgnl_a, 'a');
	else if (line[i] == 'b')
		ft_rotate(bgnl_b, bgnl_b, 'b');
	else
	{
		ft_putstr_fd("Error\n", 2);
		ft_clear_list(bgnl_a);
		ft_clear_list(bgnl_b);
		exit(1);
	}
}
