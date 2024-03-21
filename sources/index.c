/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:43:01 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/21 15:41:05 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	put_index(t_push **stacks)
{
	t_stack	*curr;
	t_stack	*runner;
	int		index;

	curr = (*stacks)->stack_a;
	while (curr)
	{
		index = 1;
		runner = (*stacks)->stack_a;
		while (runner)
		{
			if (runner->value < curr->value)
				index++;
			runner = runner->next;
		}
		curr->index = index;
		curr = curr->next;
	}
}