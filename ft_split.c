/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaymak <dkaymak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:56:44 by dkaymak           #+#    #+#             */
/*   Updated: 2025/07/02 18:57:01 by dkaymak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	j;
	size_t	start;
	size_t	word_count;
	size_t	k;

	if (!s)
		return (NULL);

	i = 0;
	word_count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			word_count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			result[j] = (char *)malloc(i - start + 1);
			if (!result[j])
			{
				while (j > 0)
				{
					j--;
					free(result[j]);
				}
				free(result);
				return (NULL);
			}
			k = 0;
			while (start < i)
			{
				result[j][k] = s[start];
				start++;
				k++;
			}
			result[j][k] = '\0';
			j++;
		}
	}
	result[j] = NULL;
	return (result);
}
