/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_crtelm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 19:28:12 by anbourge          #+#    #+#             */
/*   Updated: 2021/09/28 19:28:27 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_crtelm(int data)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!(elem))
		return (NULL);
	elem->next = NULL;
	elem->prev = NULL;
	elem->data = data;
	return (elem);
}
