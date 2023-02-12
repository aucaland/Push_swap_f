/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:23:39 by aucaland          #+#    #+#             */
/*   Updated: 2023/02/12 10:35:26 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**pars_mult_args(char ***str, int argc, char **argv)
{
	char *tmp_first;
	char **ret;

	tmp_first = NULL;
	**str = ft_strjoin((argv + 1)[0], SPACE);
	protect_malloc_tab(NULL, NULL, *str, (void **)*str);
	join_args_into_one(str, tmp_first, argv, argc);
	ret = ft_split(**str, ' ');
	protect_malloc_tab(NULL, NULL, ret, (void **)*str);
	ft_free_tab(str);
	return (ret);
}

void	join_args_into_one(char ***str, char *tmp_first, char **argv, int argc)
{
	char	*tmp_second;
	int		i;

	i = 0;
	tmp_second = NULL;
	while (++i < argc - 1)
	{
		tmp_first = ft_strjoin((argv + 1)[i], SPACE);
		if (!tmp_first)
			protect_malloc_tab(NULL, NULL, tmp_first, (void **)*str);
		tmp_second = ft_strjoin(*str[0], tmp_first);
		if (!tmp_second)
		{
			ft_free_tab(str);
			protect_malloc(NULL, NULL, tmp_second, tmp_first);
		}
		free(*str[0]);
		*str[0] = ft_strdup(tmp_second);
		if (str[0] == NULL)
		{
			free(tmp_first);
			return (protect_malloc(NULL, NULL, *str[0], tmp_second));
		}
		ft_free_multiple(tmp_first, tmp_second, NULL, NULL);
	}
}

void	clean_values(t_list_int **list_a, t_list_int **list_b, char ***str, \
															int **tab)
{
	*list_a = NULL;
	*list_b = NULL;
	*tab = NULL;
	*str = NULL;
}
