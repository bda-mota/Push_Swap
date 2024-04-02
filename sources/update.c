/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:18:13 by bda-mota          #+#    #+#             */
/*   Updated: 2024/04/02 16:08:46 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	update_rrr(t_push **stacks, int a, int b)
{
	t_stack	*curr;
	
	curr = (*stacks)->stack_a;
	while (curr && curr->index != a)
		curr = curr->next;
	curr->cost_a++;
	curr = (*stacks)->stack_b;
	while (curr && curr->index != b)
		curr = curr->next;
	curr->cost_b++;
	rrr(*stacks);
}

void	update_rr(t_push **stacks, int a, int b)
{
	t_stack	*curr;
	
	curr = (*stacks)->stack_a;
	while (curr && curr->index != a)
		curr = curr->next;
	curr->cost_a--;
	curr = (*stacks)->stack_b;
	while (curr && curr->index != b)
		curr = curr->next;
	curr->cost_b--;
	rr(*stacks);
}