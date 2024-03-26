/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:48:04 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/26 13:24:33 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
			pa(*stacks);
			return ;
		}
		curr = curr->next;
	}
}
