/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:55:40 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/28 16:40:05 by bda-mota         ###   ########.fr       */
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
	while ((*stacks)->stack_b != NULL)
	{
		find_position(stacks);
		find_target_pos(stacks);
		calculate_costs(stacks);
		total_cost(stacks);
		find_op(stacks);
	}
}

void	find_op(t_push **stacks)
{
	t_stack	*curr;
	int		cheapier;

	cheapier = 	find_cheaper((*stacks)->stack_b);
	curr = (*stacks)->stack_b;
	while (curr)
	{
		if (curr->cost == cheapier)
		{
			moves(stacks, curr->target_pos, curr->pos);
			return ;
		}	
		curr = curr->next;
	}
}