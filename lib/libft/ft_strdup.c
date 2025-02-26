/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:53:53 by itamsama          #+#    #+#             */
/*   Updated: 2024/10/26 16:25:02 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dst;
	size_t	i;

	i = ft_strlen(src) + 1;
	dst = (char *)malloc(i);
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, src, i);
	return (dst);
}
