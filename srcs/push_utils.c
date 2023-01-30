/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:59:07 by aucaland          #+#    #+#             */
/*   Updated: 2023/01/30 14:24:29 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_list_int **list, t_stack *stack)
{
	int	index_bigger;

	index_bigger = find_bigger(list, stack);
	if (index_bigger == 1)
		r_rotate_a(list, 1);
	else if (index_bigger == 0)
		rotate_a(list, 1);
	if ((*list)->value > (*list)->next->value)
		swap_a(list, 1);
}

void	sort_five(t_list_int **list_a, t_list_int **list_b, t_stack *stack)
{
	int	score;

	score = push_score(list_a, stack, 0);
	if (stack->size == 4)
	{
		bring_to_top(list_a, stack, score);
		push_b(list_a, list_b, stack);
		stack->size_tmp_a = ft_lstsize_int(*list_a);
		sort_three(list_a, stack);
		push_a(list_b, list_a, stack);
	}
	else
	{
		sort_five_to_sort_three(list_a, list_b, stack);
		stack->size_tmp_a = ft_lstsize_int(*list_a);
		sort_three(list_a, stack);
		if ((*list_b)->value < (*list_b)->next->value)
			swap_b(list_b, 1);
		push_a(list_b, list_a, stack);
		push_a(list_b, list_a, stack);
	}
}

void	big_sort(t_list_int **list_a, t_list_int **list_b, t_stack *stack)
{
	int	max;
	int	max_bits;
	int	i;
	int	j;
	int	num;

	i = -1;
	max = stack->size - 1;
	max_bits = 0;
	while ((max >> max_bits) != 0)
		++max_bits;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < stack->size)
		{
			num = (*list_a)->value;
			if (((num >> i) & 1) == 1)
				rotate_a(list_a, 1);
			else
				push_b(list_a, list_b, stack);
		}
		while ((*list_b) != NULL)
			push_a(list_b, list_a, stack);
	}
}

void	pushswap_algo(t_list_int **list_a, t_list_int **list_b)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	protect_malloc(list_a, list_b, stack, NULL);
	stack->size = ft_lstsize_int(*list_a);
	stack->size_tmp_a = stack->size;
	stack->size_tmp_b = 0;
	check_sort(list_a, stack->size);
	if (stack->size > 1 && stack->size < 4)
		sort_three(list_a, stack);
	if (stack->size > 3 && stack->size < 6)
		sort_five(list_a, list_b, stack);
	if (stack->size > 5)
		big_sort(list_a, list_b, stack);
	free(stack);
	exit_ps(list_a, list_b);
}

int	*decrease_nbr(int *tab, char **str, int len_str)
{
	int	i;
	int	j;
	int	*index;

	i = 0;
	index = ft_calloc(sizeof(int), len_str);
	if (!index)
		ft_error(str);
	while (i < len_str)
	{
		j = 0;
		while (j < len_str)
		{
			if (tab[i] > tab[j])
				index[i]++;
			j++;
		}
		i++;
	}
	free(tab);
	return (index);
}
