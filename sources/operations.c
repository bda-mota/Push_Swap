/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:48:04 by bda-mota          #+#    #+#             */
/*   Updated: 2024/04/03 14:56:34 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_index_cheaper(t_stack *stack_b, int value)
{
	t_stack	*curr;
	int		index;

	curr = stack_b;
	index = curr->index;
	while (curr)
	{
		if (curr->cost == value && index < curr->index)
			index = curr->index;
		curr = curr->next;
	}
	return (index);
}

void	find_op(t_push **stacks)
{
	t_stack	*curr;
	int		cheapier;

	cheapier = find_cheaper((*stacks)->stack_b);
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

void	moves(t_push **stacks, int target_pos, int pos_b)
{
	t_stack	*curr_a;
	t_stack	*curr_b;

	curr_a = (*stacks)->stack_a;
	curr_b = (*stacks)->stack_b;
	while (curr_a->index != target_pos)
		curr_a = curr_a->next;
	while (curr_b->pos != pos_b)
		curr_b = curr_b->next;
	while (curr_b != NULL)
	{
		if (curr_a->cost_a < 0 && curr_b->cost_b < 0)
			update_rrr(stacks, curr_a->index, curr_b->index);
		else if (curr_a->cost_a > 0 && curr_b->cost_b > 0)
			update_rr(stacks, curr_a->index, curr_b->index);
		move_a(stacks, target_pos);
		move_b(stacks, pos_b);
		if (curr_a->cost_a == 0 && curr_b->cost_b == 0)
			break ;
	}
	pa(*stacks);
}

void	move_a(t_push **stacks, int pos)
{
	t_stack	*curr;

	curr = (*stacks)->stack_a;
	while (curr)
	{
		if (curr->index == pos)
		{
			while (curr->cost_a != 0)
			{
				if (curr->cost_a < 0)
				{
					rra(*stacks);
					curr->cost_a++;
				}
				else if (curr->cost_a > 0)
				{
					ra(*stacks);
					curr->cost_a--;
				}
			}
			return ;
		}
		curr = curr->next;
	}
}

void	move_b(t_push **stacks, int pos)
{
	t_stack	*curr;

	curr = (*stacks)->stack_b;
	while (curr)
	{
		if (curr->pos == pos)
		{
			while (curr->cost_b != 0)
			{
				if (curr->cost_b < 0)
				{
					rrb(*stacks);
					curr->cost_b++;
				}
				else if (curr->cost_b > 0)
				{
					rb(*stacks);
					curr->cost_b--;
				}
			}
			return ;
		}
		curr = curr->next;
	}
}
