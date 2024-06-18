/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_create_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbourge <anbourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:45:40 by anbourge          #+#    #+#             */
/*   Updated: 2021/09/28 16:27:26 by anbourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_create_elem(int data)
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
