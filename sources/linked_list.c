/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:54:40 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/14 18:18:33 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	insert_end(t_stack **stack, int value)
{
	t_stack	*curr;
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->value = value;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	curr = *stack;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = new_node;
}

void	deallocate(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*curr;

	curr = *stack;
	while (curr)
	{
		aux = curr;
		curr = curr->next;
		free(aux);
	}
	*stack = NULL;
}

void	has_double(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*runner;

	curr = *stack;
	while (curr)
	{
		runner = curr->next;
		while (runner)
		{
			if (curr->value == runner->value)
				exit_error();
			runner = runner->next;
		}
		curr = curr->next;
	}
}

void	is_ordered(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*runner;

	curr = *stack;
	while (curr)
	{
		runner = curr->next;
		while (runner)
		{
			if (curr->value < runner->value)
				exit_error();
			runner = runner->next;
		}
		curr = curr->next;
	}
}
