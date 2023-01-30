/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:40:37 by aurel             #+#    #+#             */
/*   Updated: 2023/01/30 14:49:42 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	exit_ps(t_list_int **list_a, t_list_int **list_b)
{
	if (list_a && *list_a)
		ft_lstclear_stack(list_a);
	if (list_b && *list_b)
		ft_lstclear_stack(list_b);
	exit(EXIT_SUCCESS);
}

void	ft_error(char **str)
{
	ft_putendl_fd("Error", 2);
	if (str != NULL)
		ft_free_tab(&str);
	exit(EXIT_SUCCESS);
}

void	protect_malloc(t_list_int **list_a, t_list_int **list_b, \
											void *ptr_check, void *ptr_to_free)
{
	if (ptr_check)
		return ;
	if (ptr_to_free)
		free(ptr_to_free);
	ft_putendl_fd("Error", 2);
	exit_ps(list_a, list_b);
}

void	protect_malloc_tab(t_list_int **list_a, t_list_int **list_b, \
											void *ptr_check, void **ptr_to_free)
{
	if (ptr_check)
		return ;
	if (ptr_to_free)
		ft_free_tab((char ***)ptr_to_free);
	ft_putendl_fd("Error", 2);
	exit_ps(list_a, list_b);
}

void	protect_malloc_list(t_list_int **list_a, t_list_int **list_b, \
											void *ptr_check, void **ptr_to_free)
{
	if (ptr_check)
		return ;
	if (ptr_to_free)
		ft_lstclear_stack((t_list_int **)ptr_to_free);
	ft_putendl_fd("Error", 2);
	exit_ps(list_a, list_b);
}
