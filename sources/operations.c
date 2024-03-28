/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:48:04 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/28 13:08:13 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	moves(t_push **stacks, int target_pos, int pos_b)
{
	t_stack	*curr_a;
	t_stack	*curr_b;

	curr_a = (*stacks)->stack_a;
	curr_b = (*stacks)->stack_b;	
	while (curr_a->pos != target_pos)
		curr_a = curr_a->next;
	while (curr_b->pos != pos_b)
		curr_b = curr_b->next;
	while (curr_a->cost_a != 0 || curr_b->cost_b != 1)
	{
		if (curr_a->cost_a < 0 && curr_b->cost_b < 0)
		{
			rrr(*stacks);
			curr_a->cost_a++;
			curr_b->cost_b++;
		}
		else if (curr_a->cost_a > 0 && curr_b->cost_b > 1)
		{
			rr(*stacks);
			curr_a->cost_a--;
			curr_b->cost_b--;
		}
		else
		{
			move_a(stacks, target_pos);
			move_b(stacks, pos_b);
		}
	}
	if (curr_a->cost_a == 0 && curr_b->cost_b == 1)
		pa(*stacks);
}

void	move_a(t_push **stacks, int pos)
{
	t_stack	*curr;
	
	curr = (*stacks)->stack_a;
	while (curr)
	{
		if (curr->pos == pos)
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
			while (curr->cost_b != 1)
			{
				if (curr->cost_b < 1)
				{
					rrb(*stacks);
					curr->cost_b++;
				}	
				else if (curr->cost_b > 1)
				{
					rb(*stacks);
					curr->cost_b--;
				}
			}
			//pa(*stacks);
			return ;
		}
		curr = curr->next;
	}
}
