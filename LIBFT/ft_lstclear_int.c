/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 09:07:05 by aucaland          #+#    #+#             */
/*   Updated: 2022/12/10 09:20:51 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear_int(t_list_int **lst, void (*del)(int))
{
	t_list_int	*temp;

	if (!(lst) || !(del))
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		ft_lstdelone_int(*lst, (*del));
		*lst = temp;
	}
}
