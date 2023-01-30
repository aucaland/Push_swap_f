/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:23:39 by aucaland          #+#    #+#             */
/*   Updated: 2023/01/30 17:46:24 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pars_mult_args(char **str, char *tmp, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if (!(argv + 1)[i] || (argv + 1)[i][0] == '\0')
			ft_error(str);
		i++;
	}
	i = 1;
	str[0] = ft_strdup((argv + 1)[0]);
	dprintf(2, "%s\n", str[0]);
	protect_malloc(NULL, NULL, *str, NULL);
	while (i < argc - 1)
	{
		tmp = ft_strjoin(str[0], ESCAPE);
		str[0] = ft_strjoin(tmp, (argv + 1)[i]);

		protect_malloc(NULL, NULL, str[0], tmp);
		//free(tmp);
		i++;
	}
	dprintf(2, "%s\n", str[0]);
	tmp = *str;
	str = ft_split(tmp, ' ');
	ft_free(tmp);
	protect_malloc(NULL, NULL, str, tmp);
}
