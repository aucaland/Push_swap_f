/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:43:32 by aucaland          #+#    #+#             */
/*   Updated: 2023/01/30 14:46:58 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_multiple(void *ptr, void *ptr_two, void *ptr_three, void
																	*ptr_four)
{
	if (ptr)
		free(ptr);
	if (ptr_two)
		free(ptr_two);
	if (ptr_three)
		free(ptr_three);
	if (ptr_four)
		free(ptr_four);
}
