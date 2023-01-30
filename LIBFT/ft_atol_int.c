/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:05:03 by aucaland          #+#    #+#             */
/*   Updated: 2022/12/09 17:05:03 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(const char str)
{
	if (str == '\t' || str == '\n' || str == '\v' \
		|| str == '\f' || str == '\r' || str == ' ')
		return (1);
	return (0);
}

long int	ft_atol_int(const char *str)
{
	int long long		n;
	int long long		sign;
	int					i;

	n = 0;
	sign = 1;
	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		n = n * 10 + (str[i++] - '0');
	return ((n * sign));
}
