/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:02:29 by aucaland          #+#    #+#             */
/*   Updated: 2022/12/09 16:15:05 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_int	*ft_lstnew_int(int value)
{
	t_list_int	*np;

	np = malloc(sizeof(t_list_int));
	if (np)
	{
		np->value = value;
		np->next = NULL;
	}
	else
	{
		free(np);
		np = NULL;
	}
	return (np);
}
