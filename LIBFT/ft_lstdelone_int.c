/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 09:08:28 by aucaland          #+#    #+#             */
/*   Updated: 2022/12/10 09:16:57 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone_int(t_list_int *lst, void (*del)(int))
{
	if (lst != NULL)
	{
		if (del != NULL)
		{
			(*del)(lst->value);
			ft_free(lst);
		}
	}
}
