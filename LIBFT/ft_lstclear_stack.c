/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 09:29:05 by aucaland          #+#    #+#             */
/*   Updated: 2022/12/10 09:29:05 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear_stack(t_list_int **lst)
{
	t_list_int	*temp;

	if (!(lst))
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		ft_free(*lst);
		*lst = temp;
	}
}
