/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:54:24 by aurel             #+#    #+#             */
/*   Updated: 2023/01/30 14:53:04 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_bigger(t_list_int **list, t_stack *stack)
{
	int			i;
	int			bigger;
	int			index;
	t_list_int	*top;

	i = 0;
	index = 0;
	top = *list;
	bigger = (*list)->value;
	while (i < stack->size_tmp_a - 1)
	{
		if ((*list)->next->value > bigger)
		{
			bigger = (*list)->next->value;
			index = i + 1;
		}
		*list = (*list)->next;
		i++;
	}
	*list = top;
	return (index);
}

int	push_score(t_list_int **list_a, t_stack *stack, int index)
{
	t_list_int	*top;
	int			place;
	int			score;

	top = *list_a;
	place = 1;
	while ((*list_a)->value != index)
	{
		*list_a = (*list_a)->next;
		place++;
	}
	if (place > stack->size_tmp_a / 2)
		score = (stack->size_tmp_a + 1) - place + 10;
	else
		score = place - 1;
	*list_a = top;
	return (score);
}

void	bring_to_top(t_list_int **list, t_stack *stack, int score)
{
	int	i;

	if (score >= (stack->size_tmp_a / 2 - 1) + 10)
		i = 10;
	else
		i = 0;
	if (stack->size_tmp_a % 2 == 0)
	{
		i += 2;
		score += 2;
	}
	while (i < score)
	{
		if (i >= (stack->size_tmp_a / 2 - 2) + 10)
			r_rotate_a(list, 1);
		else
			rotate_a(list, 1);
		i++;
	}
}

void	sort_five_to_sort_three(t_list_int **list_a, t_list_int **list_b, \
								t_stack *stack)
{
	int	score;
	int	score_two;

	score = push_score(list_a, stack, 0);
	score_two = push_score(list_a, stack, 1);
	{
		if (score >= stack->size_tmp_a - (stack->size / 2) + 10)
			score -= 10;
		if (score_two >= stack->size_tmp_a - (stack->size / 2) + 10)
			score_two -= 10;
		if (score > score_two)
		{
			bring_to_top(list_a, stack, push_score(list_a, stack, 1));
			push_b(list_a, list_b, stack);
			bring_to_top(list_a, stack, push_score(list_a, stack, 0));
			push_b(list_a, list_b, stack);
		}
		else
		{
			bring_to_top(list_a, stack, push_score(list_a, stack, 0));
			push_b(list_a, list_b, stack);
			bring_to_top(list_a, stack, push_score(list_a, stack, 1));
			push_b(list_a, list_b, stack);
		}
	}
}
