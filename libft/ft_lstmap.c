/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmariam <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 20:04:03 by fmariam           #+#    #+#             */
/*   Updated: 2019/04/15 21:24:00 by fmariam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*beg;
	t_list	*current;

	beg = f(lst);
	current = beg;
	if (!f || !lst)
		return (NULL);
	while ((lst = lst->next))
	{
		if (!current)
			return (NULL);
		current->next = f(lst);
		current = current->next;
	}
	return (beg);
}
