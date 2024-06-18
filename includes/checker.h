/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:15:31 by anbourge          #+#    #+#             */
/*   Updated: 2021/09/28 20:02:09 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>

# include "../libft/libft.h"

int		main(int argc, char **argv);
int		ft_check_arg(char **argv, int i);
int		ft_check_arg_utils(char **argv, int i, int j);
t_list	*ft_create_list(int argc, char **argv, t_list **begin_list);
int		ft_create_list_utils(char **argv, int *i, t_list *tmp, t_list *list);
int		ft_is_sort(t_list **begin_list);
void	*ft_puterror(t_list **begin_list);
int		ft_check_double(t_list **begin_list);
void	ft_clear_list(t_list **begin_list);

int		ft_swap(t_list *list, t_list *list2, char s);
int		ft_push(t_list **begin_list, t_list **begin_list2, char p);
int		ft_push_tmp(t_list **begin_list, t_list **begin_list2);
int		ft_rotate(t_list **begin_list, t_list **begin_list2, char r);
int		ft_reverse_rotate(t_list **begin_list, t_list **begin_list2, char r);

int		ft_stack_position(t_list **begin_list, int b);
t_list	*ft_create_stack2(t_list *list, t_list *res, t_list **bgnlst, int *i);
void	ft_create_stack(t_list **begin_list, t_list **bgnl, int size);

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
int		has_nl(char *str);

void	ft_checker(t_list **bgnl_a);
void	ft_op_choose(t_list **bgnl_a, t_list **bgnl_b, char *line, int i);
void	ft_rotate_choose(t_list **bgnl_a, t_list **bgnl_b, char *line, int i);

#endif