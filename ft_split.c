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

	// Kelime sayısını bul
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

	// Ana dizi için malloc
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);

	// Kelimeleri doldur
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