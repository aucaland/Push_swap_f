/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:19:32 by aucaland          #+#    #+#             */
/*   Updated: 2023/01/17 11:13:53 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_list_int **list_b, t_list_int **list_a, t_stack *stack)
{
	t_list_int	*top;

	top = NULL;
	if (*list_b)
	{
		top = (*list_b)->next;
		ft_lstadd_front_int(list_a, *list_b);
		*list_b = top;
		stack->size_tmp_b--;
		stack->size_tmp_a++;
		ft_putendl_fd("pa", 1);
	}
	else
		return ;
}

void	push_b(t_list_int **list_a, t_list_int **list_b, t_stack *stack)
{
	t_list_int	*top;

	top = NULL;
	if (*list_a)
	{
		top = (*list_a)->next;
		(*list_a)->next = NULL;
		ft_lstadd_front_int(list_b, *list_a);
		*list_a = top;
		stack->size_tmp_b++;
		stack->size_tmp_a--;
		ft_putendl_fd("pb", 1);
	}
	else
		return ;
}
