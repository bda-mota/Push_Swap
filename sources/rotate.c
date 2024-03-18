/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:50:40 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/18 17:04:17 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		first = (*stack_a);
		last = stack_last(*stack_a);
		*stack_a = first->next;
		first->next = NULL;
		last->next = first;
	}
}