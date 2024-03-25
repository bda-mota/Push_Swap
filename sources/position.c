/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:22:53 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/25 10:27:54 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_position(t_push **stacks)
{
	t_stack	*curr;
	int		position;

	position = 0;
	curr = (*stacks)->stack_a;
	while (curr)
	{
		curr->pos = position++;
		curr = curr->next;
	}
	position = 0;
	curr = (*stacks)->stack_b;
	while (curr)
	{
		curr->pos = position++;
		curr = curr->next;
	}

}