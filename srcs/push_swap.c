/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:25:30 by aucaland          #+#    #+#             */
/*   Updated: 2023/01/30 23:38:13 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	int	*pars_argv(char **str, int *tab, int len_str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < len_str)
	{
		tmp = ft_strdup(str[i]);
		if (!tmp)
			ft_error(str);
		check_max_int(tmp, tab, str);
		tab[i] = ft_atoi(tmp);
		i++;
		free(tmp);
	}
	tab = decrease_nbr(tab, str, len_str);
	return (tab);
}

static void	get_list(t_list_int **list, int *tab, int len_str, char **str)
{
	int			i;
	t_list_int	*top;
	t_list_int	*new;

	top = *list;
	i = 0;
	while (i < len_str)
	{
		new = ft_lstnew_int(tab[i]);
		protect_malloc_list(NULL, NULL, new, (void **)list);
		ft_lstadd_back_int(&top, new);
		while (*list && (*list)->value != tab[i])
			*list = (*list)->next;
		if (*list && (*list)->value != tab[i])
		{
			*list = top;
			ft_lstclear_stack(list);
			free(tab);
			ft_error(str);
		}
		*list = top;
		i++;
	}
}

char	**init_str(int argc, char **argv, char **str)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if (!(argv + 1)[i] || (argv + 1)[i][0] == '\0')
			ft_error(str);
		i++;
	}
	if (argc == 2 && argv[1][0] != '\0')
	{
		str = ft_split(argv[1], ' ');
		protect_malloc(NULL, NULL, str, NULL);
	}
	else if (argc > 2)
	{
		str = ft_calloc(sizeof(char *), 2);
		protect_malloc(NULL, NULL, str, NULL);
		pars_mult_args(&str, argc, argv);
	}
	return (str);
}

void	push_swap(int argc, char **argv)
{
	t_list_int	*list_a;
	t_list_int	*list_b;
	char		**str;
	int			*tab;
	int			len_str;

	clean_values(&list_a, &list_b, &str, &tab);
	len_str = 0;
	if (argc < 2)
		ft_error(str);
	str = init_str(argc, argv, str);
	while (str[len_str])
		len_str++;
	tab = malloc(sizeof(int) * len_str);
	protect_malloc_tab(NULL, NULL, tab, (void **)str);
	check_str(str, len_str);
	check_dup(str, len_str, argc);
	tab = pars_argv(str, tab, len_str);
	get_list(&list_a, tab, len_str, str);
	free(tab);
	if (argc == 2)
		ft_free_tab(&str);
	pushswap_algo(&list_a, &list_b);
}

int	main(int argc, char **argv)
{
	push_swap(argc, argv);
	return (EXIT_SUCCESS);
}
