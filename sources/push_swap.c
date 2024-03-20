/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:55:40 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/20 17:24:14 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_push **push)
{
	sort_three(push);
	return ;
}

void	get_size(t_push *push)
{
	push->size_a = get_stack_size(push->stack_a);
	push->size_b = get_stack_size(push->stack_b);
}

void	sort_three(t_push **push)
{
	(*push)->max_value = get_max((*push)->stack_a);
	(*push)->min_value = get_min((*push)->stack_a);
	if ((*push)->stack_a->value == (*push)->max_value)
		ra(*push);
	if ((*push)->stack_a->value > (*push)->stack_a->next->value)
		sa(*push);
	if ((*push)->stack_a->next->next->value == (*push)->min_value)
		rra(*push);
}
