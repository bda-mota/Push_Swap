/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:45:58 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/14 18:32:51 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_args(int argc, char **argv);
static int	check_list(t_stack **stack, int argc, char **argv);
static void	transform_and_add(t_stack **stack, int argc, char **argv);

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = NULL;
	if (check_args(argc, argv) == 1)
		exit_error();
	check_list(&stack, argc, argv);
	return (0);
}

static int	check_args(int argc, char **argv)
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
			return (1);
		j = 0;
		while (argv[i][j])
		{
			if (ft_issign(argv[i][0]) && j == 0)
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_list(t_stack **stack, int argc, char **argv)
{
	transform_and_add(stack, argc, argv);
	has_double(stack);
	//is_ordered(stack);
	deallocate(stack);
	return (0);
}

static void	transform_and_add(t_stack **stack, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_printf("%d\n", ft_atoi(argv[i]));
		if (ft_atol(argv[i]) > MAX_INT || ft_atol(argv[i]) < MIN_INT)
		{
			deallocate(stack);
			exit_error();
		}
		else
			insert_end(stack, ft_atol(argv[i]));
		i++;
	}
}
