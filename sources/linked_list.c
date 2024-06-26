/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:54:40 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/28 18:58:14 by bda-mota         ###   ########.fr       */
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

void	free_lists(t_push *stacks)
{
	deallocate(&stacks->stack_a);
	deallocate(&stacks->stack_b);
	free(stacks);
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

void	insert_beginning(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

t_stack	*stack_last(t_stack *lst)
{
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
