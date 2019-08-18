/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmariam <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:36:02 by fmariam           #+#    #+#             */
/*   Updated: 2019/04/15 22:34:08 by fmariam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;

	i = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s) - 1;
	while (ft_strlen(s) && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (ft_strlen(s) && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		j--;
	return (ft_strsub(s, i, j - i + 1 >= 0 ? j - i + 1 : 0));
}
