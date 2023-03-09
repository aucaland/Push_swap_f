/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:33:38 by aucaland          #+#    #+#             */
/*   Updated: 2023/03/06 15:58:27 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_sort(t_list_int **list_a, int size)
{
	t_list_int	*top;
	int			size_top;

	top = *list_a;
	size_top = ft_lstsize_int(*list_a);
	while (*list_a && (*list_a)->next != NULL)
	{
		if ((*list_a)->value < (*list_a)->next->value)
			*list_a = (*list_a)->next;
		else
			break ;
	}
	if (*list_a && (*list_a)->next == NULL && size == size_top)
	{
		*list_a = top;
		exit_ps(list_a, NULL);
	}
	if (*list_a && (*list_a)->next == NULL)
	{
		*list_a = top;
		return (1);
	}
	*list_a = top;
	return (0);
}

void	check_max_int(char *str, int *tab, char **str_malloc)
{
	char			*str_max;
	char			*str_min;
	long long int	tmp;

	str_min = ft_itoa(INT_MIN);
	protect_malloc(NULL, NULL, str_min, NULL);
	str_max = ft_itoa(INT_MAX);
	protect_malloc(NULL, NULL, str_max, str_min);
	tmp = ft_atol_int(str);
	if ((str[0] == '-' && ft_strlen(str) - zero(str) > ft_strlen(str_min)) \
		|| (str[0] != '-' && ft_strlen(str) - zero(str) > ft_strlen(str_max)))
	{
		ft_free_multiple(str, tab, str_min, str_max);
		ft_error(str_malloc);
	}
	if (tmp > INT_MAX || tmp < INT_MIN)
	{
		ft_free_multiple(str, tab, str_min, str_max);
		ft_error(str_malloc);
	}
	free(str_min);
	free(str_max);
}

void	check_dup(char **str, int *tab, int len_str)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < len_str)
	{
		j = -1;
		while (++j < len_str)
		{
			if (j == i)
				continue ;
			else if (tab[i] == tab[j])
				return (ft_error(str));
		}
	}
}

void	check_str(char **str, int len_str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len_str)
	{
		while (str[i][j] && ft_isspace(str[i][j]))
			j++;
		if (str[i][j] == '-' || str[i][j] == '+')
			j++;
		if (!str[i][j])
			ft_error(str);
		while (str[i][j])
		{
			if (!ft_is_digit(str[i][j]))
				ft_error(str);
			j++;
		}
		i++;
		j = 0;
	}
}

int	zero(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '0')
		i++;
	return (i);
}
