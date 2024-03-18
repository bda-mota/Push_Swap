/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:22:27 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/18 16:38:34 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;
	
	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		first = (*stack_a);
		second = (*stack_a)->next;
		first->next = second->next;
		second->next = first;
		(*stack_a) = second;
	}
}