/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_int.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:34:41 by aucaland          #+#    #+#             */
/*   Updated: 2022/12/10 11:34:41 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize_int(t_list_int *lst)
{
	t_list_int	*curr;
	size_t		n;

	curr = lst;
	n = 0;
	while (curr != NULL)
	{
		n++;
		curr = curr->next;
	}
	return (n);
}
