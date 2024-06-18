/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:46:48 by anbourge          #+#    #+#             */
/*   Updated: 2021/09/28 19:57:18 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# include "../libft/libft.h"

int		main(int argc, char **argv);
int		ft_execute(t_list **begin_list, t_list **bgnl);
int		ft_check_arg(char **argv, int i);
t_list	*ft_create_list(int argc, char **argv, t_list **begin_list);
int		ft_is_sort(t_list **begin_list);
void	*ft_puterror(t_list **begin_list);

int		ft_create_list_utils(char **argv, int *i, t_list *tmp, t_list *list);
int		ft_check_arg_utils(char **argv, int i, int j);

int		ft_check_double(t_list **begin_list);

int		ft_swap(t_list *list, t_list *list2, char s);
int		ft_push(t_list **begin_list, t_list **begin_list2, char p);
int		ft_push_tmp(t_list **begin_list, t_list **begin_list2);
int		ft_rotate(t_list **begin_list, t_list **begin_list2, char r);
int		ft_reverse_rotate(t_list **begin_list, t_list **begin_list2, char r);

int		ft_stack_position(t_list **begin_list, int b);
void	ft_create_stack(t_list **begin_list, t_list **bgnl, int size);
t_list	*ft_create_stack2(t_list *list, t_list *res, t_list **bgnlst, int *i);

void	ft_algo_under_five(t_list **begin_list, int size);
void	ft_algo_size_four(t_list **bgnl_a, t_list **bgnl_b, int i);
void	ft_algo_size_five(t_list **bgnl_a, t_list **bgnl_b, int i);
void	ft_algo_size_five2(t_list **bgnl_a, t_list **bgnl_b, int j);
void	ft_algo_under_three(t_list **begin_list);
void	ft_three_utils(t_list **bgnl, t_list *list, t_list *tmp, t_list *tmp2);
void	ft_algo_choose(t_list **begin_list);

void	ft_clear_list(t_list **begin_list);

void	ft_algorithm_main(t_list **bgnl_a, int chunk_size);
void	ft_algorithm_chunks(t_list **bgnl_a, t_list **bgnl_b, int *chunk);
void	ft_algorithm_create_holds(t_list **bgnl_a, int *hold, int *chunk);

void	ft_algorithm_pp(t_list **bgnl_a, t_list **bgnl_b, int *hold, int *i);
int		ft_pp_def_data(t_list **bgnl_a, t_list **bgnl_b, int *hold);
int		ft_pp_upper_size(t_list **bgnl_a, t_list **bgnl_b, int *hold, int *i);
int		ft_pp_define_b(t_list **bgnl_b, int data, int *i);

#endif