/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:02:23 by itamsama          #+#    #+#             */
/*   Updated: 2024/11/12 09:01:20 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	digit_count(int n)
{
	unsigned int	count;

	count = 0;
	if (n <= 0)
	{
		count++;
		n = -n;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	convert_num(int *n)
{
	char	digit_char;

	digit_char = (*n % 10) + '0';
	*n /= 10;
	return (digit_char);
}

char	*ft_itoa(int n)
{
	char			*ret;
	int				i;
	unsigned int	num_digits;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	num_digits = digit_count(n);
	i = num_digits - 1;
	ret = (char *)malloc((num_digits + 1) * sizeof(char));
	ret[num_digits] = '\0';
	if (n < 0)
	{
		ret[0] = '-';
		n = -n;
	}
	else if (n == 0)
	{
		ret[0] = '0';
		ret[1] = '\0';
		return (ret);
	}
	while (n > 0)
		ret[i--] = convert_num(&n);
	return (ret);
}
