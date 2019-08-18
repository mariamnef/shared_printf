/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmariam <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:23:42 by fmariam           #+#    #+#             */
/*   Updated: 2019/04/15 22:28:17 by fmariam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count_word(char const *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (!str[i])
			break ;
		count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

static	int		ft_nb_char(char const *s, int i, char c)
{
	int		count;

	count = 0;
	while (s[i] != c && s[i])
	{
		count++;
		i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	int		j;
	int		i;
	char	**x;

	i = 0;
	j = 0;
	if (!(x = (char**)malloc(sizeof(char*) * (ft_count_word(s, c) + 1))))
		return (NULL);
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (!s[i])
			break ;
		x[j] = ft_strsub(s, i, ft_nb_char(s, i, c));
		j++;
		while (s[i] != c && s[i])
			i++;
	}
	x[j] = NULL;
	return (x);
}
