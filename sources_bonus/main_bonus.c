/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:11:29 by bda-mota          #+#    #+#             */
/*   Updated: 2024/04/04 16:19:02 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static void	check_args(int argc, char **argv);
static void	check_list(t_push *stacks, int argc, char **argv);
static void	transform_and_add(t_push *stacks, int argc, char **argv);

int	main(int argc, char **argv)
{
	t_push	*stacks;
	char	*op;

	check_args(argc, argv);
	init_list(&stacks);
	check_list(stacks, argc, argv);
	op = get_next_line(0);
	while (op)
	{
		perform_input(op, &stacks);
		free(op);
		op = get_next_line(0);
	}
	free(op);
	if (is_ordered(stacks->stack_a) && stacks->stack_b == NULL)
		ft_putstr_fd("OK\n", STDERR_FILENO);
	else
		ft_putstr_fd("KO\n", STDERR_FILENO);
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
		exit(1);
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
