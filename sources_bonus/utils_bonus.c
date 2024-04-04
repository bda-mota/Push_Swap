/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:03:12 by bda-mota          #+#    #+#             */
/*   Updated: 2024/04/04 16:42:19 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	exit_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ft_print_error(t_push *stacks)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	free_lists(stacks);
	exit(EXIT_FAILURE);
}

void	perform_input(char *op, t_push **stacks)
{
	if (ft_strcmp(op, "sa\n") == 0)
		sa(*stacks);
	else if (ft_strcmp(op, "sb\n") == 0)
		sb(*stacks);
	else if (ft_strcmp(op, "ss\n") == 0)
		ss(*stacks);
	else if (ft_strcmp(op, "pa\n") == 0)
		pa(*stacks);
	else if (ft_strcmp(op, "pb\n") == 0)
		pb(*stacks);
	else if (ft_strcmp(op, "ra\n") == 0)
		ra(*stacks);
	else if (ft_strcmp(op, "rb\n") == 0)
		rb(*stacks);
	else if (ft_strcmp(op, "rr\n") == 0)
		rr(*stacks);
	else if (ft_strcmp(op, "rra\n") == 0)
		rra(*stacks);
	else if (ft_strcmp(op, "rrb\n") == 0)
		rrb(*stacks);
	else if (ft_strcmp(op, "rrr\n") == 0)
		rrr(*stacks);
	else
	{
		free(op);
		ft_print_error(*stacks);
	}
}
