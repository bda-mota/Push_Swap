/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:45:58 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/25 20:38:35 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	check_args(int argc, char **argv);
static void	check_list(t_push *stacks, int argc, char **argv);
static void	transform_and_add(t_push *stacks, int argc, char **argv);

int	main(int argc, char **argv)
{
	t_push	*stacks;
	t_stack	*curr;

	init_list(&stacks);
	check_args(argc, argv);
	check_list(stacks, argc, argv);
	push_swap(&stacks);
	curr = stacks->stack_a;
	ft_printf("--------------\n");
	ft_printf("STACK A:\n");
	ft_printf("--------------\n");
	while (curr)
	{
		ft_printf("index:%d\n", curr->index);
		ft_printf("cost a:%d\n", curr->cost_a);
		ft_printf("--------------\n");
		curr = curr->next;
	}
	ft_printf("STACK B:\n");
	ft_printf("--------------\n");
	curr = stacks->stack_b;
	while (curr)
	{
		ft_printf("index:%d\n", curr->index);
		ft_printf("cost b:%d\n", curr->cost_b);
		ft_printf("--------------\n");
		curr = curr->next;
	}
	free_lists(stacks);
	return (0);
}

static void	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc < 2)
		exit_error();
	while (argv[i] && i < argc)
	{
		if (ft_strcmp(argv[i], "") == 0)
			exit_error();
		j = 0;
		while (argv[i][j])
		{
			if (ft_issign(argv[i][0]) && j == 0)
				j++;
			if (!ft_isdigit(argv[i][j]))
				exit_error();
			j++;
		}
		i++;
	}
}

static void	check_list(t_push *stacks, int argc, char **argv)
{
	transform_and_add(stacks, argc, argv);
	has_double(stacks);
	if (is_ordered(stacks->stack_a) == 1)
	{
		free_lists(stacks);
		exit_error();
	}
}

static void	transform_and_add(t_push *stacks, int argc, char **argv)
{
	int	i;

	i = 1;
	init_stack(&stacks->stack_a);
	remove_first(&stacks->stack_a);
	while (i < argc)
	{
		if (ft_atol(argv[i]) > MAX_INT || ft_atol(argv[i]) < MIN_INT)
		{
			free_lists(stacks);
			exit_error();
		}
		else
			insert_end(&stacks->stack_a, ft_atol(argv[i]));
		i++;
	}
}
