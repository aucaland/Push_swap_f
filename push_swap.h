/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:25:35 by aucaland          #+#    #+#             */
/*   Updated: 2023/01/30 17:24:51 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "LIBFT/libft.h"
# include <errno.h>
# include <stdio.h>

# define ESCAPE	" "

typedef struct s_stack
{
	int	size;
	int	size_tmp_a;
	int	size_tmp_b;
}						t_stack;

void	push_swap(int argc, char **argv);
void	pushswap_algo(t_list_int **list_a, t_list_int **list_b);
int		*decrease_nbr(int *tab, char **str, int len_str);
void	pars_mult_args(char **str, char *tmp, int argc, char **argv);

/*					OPERATION					*/

void	swap_a(t_list_int **list, int is_print);
void	swap_b(t_list_int **list, int is_print);
void	swap_all(t_list_int **list_a, t_list_int **list_b);
void	push_a(t_list_int **list_b, t_list_int **list_a, t_stack *stack);
void	push_b(t_list_int **list_a, t_list_int **list_b, t_stack *stack);
void	rotate_a(t_list_int **list, int is_printed);
void	rotate_b(t_list_int **list, int is_printed);
void	rotate_all(t_list_int **list_a, t_list_int **list_b);
void	r_rotate_a(t_list_int **list, int is_printed);
void	r_rotate_b(t_list_int **list, int is_printed);
void	r_rotate_all(t_list_int **list_a, t_list_int **list_b);

/*					CHECK					*/

void	ft_check_stack(t_list_int **list_a, t_list_int **list_b);//TODO:erase
int		check_sort(t_list_int **list_a, int size);
void	check_max_int(char *str, int *tab, char **str_malloc);
void	check_dup(char **str, int len_src, int argc);
void	check_str(char **str, int len_str);
int		zero(char *str);

/*					TRI					*/

void	sort_three(t_list_int **list, t_stack *stack);
void	big_sort(t_list_int **list_a, t_list_int **list_b, t_stack *stack);
int		find_bigger(t_list_int **list, t_stack *stack);
int		push_score(t_list_int **list_a, t_stack *stack, int index);
void	bring_to_top(t_list_int **list, t_stack *stack, int score);
void	sort_five_to_sort_three(t_list_int **list_a, \
									t_list_int **list_b, t_stack *stack);

/*					ERRORS/EXIT			*/

void	exit_ps(t_list_int **list_a, t_list_int **list_b);
void	ft_error(char **str);
void	protect_malloc(t_list_int **list_a, t_list_int **list_b, \
										void *ptr_check, void *ptr_to_free);
void	protect_malloc_tab(t_list_int **list_a, t_list_int **list_b, \
										void *ptr_check, void **ptr_to_free);
void	protect_malloc_list(t_list_int **list_a, t_list_int **list_b, \
										void *ptr_check, void **ptr_to_free);
void	ft_free_multiple(void *ptr, void *ptr_two, void *ptr_three, void \
																	*ptr_four);
#endif
