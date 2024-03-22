/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:55:40 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/22 12:55:13 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_push **stacks)
{
	if (get_stack_size((*stacks)->stack_a) <= 3)
		sort_three(stacks);
	else
	{
		put_index(stacks);
		media_and_push(stacks);
		sort_three(stacks);
		sort_many(stacks);
	}
}

void	sort_three(t_push **stacks)
{
	(*stacks)->max_value = get_max((*stacks)->stack_a);
	if ((*stacks)->stack_a->value == (*stacks)->max_value)
		ra(*stacks);
	else if ((*stacks)->stack_a->next->value == (*stacks)->max_value)
		rra(*stacks);
	if ((*stacks)->stack_a->value > (*stacks)->stack_a->next->value)
		sa(*stacks);
}

void	sort_many(t_push **stacks)
{
	(void)stacks;
	return ;
}
