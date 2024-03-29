/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:55:40 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/28 21:11:06 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_stack_a(t_push **stacks);
static int	find_first(t_stack *stack_a);

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
	sort_stack_a(stacks);
}

static void	sort_stack_a(t_push **stacks)
{
	t_stack	*curr;
	int		min;
	int		media;

	while (is_ordered((*stacks)->stack_a) == 0)
	{
		curr = (*stacks)->stack_a;
		find_position(stacks);
		min = find_first((*stacks)->stack_a);
		media = get_stack_size((*stacks)->stack_a) / 2;
		while (curr)
		{
			if (curr->index == min)
			{
				if (curr->pos > media)
					rra(*stacks);
				else
					ra(*stacks);
				break ;
			}
			curr = curr->next;
		}
	}
}

static int	find_first(t_stack *stack_a)
{
	t_stack	*curr;
	int		min;

	curr = stack_a;
	min = curr->index;
	while (curr)
	{
		if (curr->index < min)
			min = curr->index;
		curr = curr->next;
	}
	return (min);
}