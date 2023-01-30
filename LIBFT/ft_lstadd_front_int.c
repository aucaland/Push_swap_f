/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:00:43 by aucaland          #+#    #+#             */
/*   Updated: 2022/12/10 15:02:07 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front_int(t_list_int **lst, t_list_int *new)
{
	if (!*lst)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}
