/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_backi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:08:30 by aucaland          #+#    #+#             */
/*   Updated: 2022/12/09 16:08:23 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back_int(t_list_int **lst, t_list_int *new)
{
	t_list_int	*temp;

	temp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	while (temp)
	{
		if (temp->next == NULL)
		{
			temp->next = new;
			new->next = NULL;
			break ;
		}
		temp = temp->next;
	}
}
