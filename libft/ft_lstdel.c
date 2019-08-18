/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmariam <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 18:44:15 by fmariam           #+#    #+#             */
/*   Updated: 2019/04/15 22:31:57 by fmariam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *new;
	t_list *current;

	new = *alst;
	while (new)
	{
		current = new;
		del(new->content, new->content_size);
		new = current->next;
		free(current);
	}
	*alst = NULL;
}
