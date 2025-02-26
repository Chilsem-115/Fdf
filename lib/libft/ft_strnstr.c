/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 01:27:09 by itamsama          #+#    #+#             */
/*   Updated: 2024/10/26 22:21:00 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lil, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lil_len;

	i = 0;
	if (*lil == '\0')
		return ((char *)big);
	lil_len = ft_strlen(lil);
	if (len < lil_len)
		return (NULL);
	while (i <= len - lil_len)
	{
		j = 0;
		while (j < lil_len && big [i + j] == lil[j])
			j++;
		if (j == lil_len)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
