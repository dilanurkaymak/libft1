/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaymak <dkaymak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:56:13 by dkaymak           #+#    #+#             */
/*   Updated: 2025/07/02 18:56:19 by dkaymak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		len;

	nb = n;
	len = 1;
	if (n < 0)
	{
		nb = -nb;
		len++;
	}
	while (n / 10 != 0)
	{
		n = n / 10;
		len++;
	}
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (str[0] == '0' && n < 0)
		str[0] = '-';
	return (str);
}
