/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:27:30 by itamsama          #+#    #+#             */
/*   Updated: 2024/10/26 16:27:26 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*string_beg = str;

	while (*str)
		str++;
	if (c == '\0')
		return ((char *)str);
	while (str != string_beg)
	{
		if (*--str == (char)c)
			return ((char *)str);
	}
	return (NULL);
}
