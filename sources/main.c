/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:45:58 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/20 16:04:07 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	init_lists(t_push **push);
static int	check_args(int argc, char **argv);
static int	check_list(t_push *push, int argc, char **argv);
static void	transform_and_add(t_push *push, int argc, char **argv);

int	main(int argc, char **argv)
{
	t_push	*push;
	t_stack	*curr;

	push = NULL;
	init_lists(&push);
	check_args(argc, argv);
	check_list(push, argc, argv);
	push_swap(&push);
	curr = push->stack_a;
	while (curr)
	{
		ft_printf("%d\n", curr->value);
		curr = curr->next;
	}
	ft_printf("STACK B:\n");
	curr = push->stack_b;
	while (curr)
	{
		ft_printf("%d\n", curr->value);
		curr = curr->next;
	}
	free_lists(push);
	return (0);
}

static void	init_lists(t_push **push)
{
	*push = malloc(sizeof(t_push));
	if (*push == NULL)
		exit(1);
	(*push)->stack_a = NULL;
	(*push)->stack_b = NULL;
}

static int	check_args(int argc, char **argv)
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
	return (0);
}

static int	check_list(t_push *push, int argc, char **argv)
{
	transform_and_add(push, argc, argv);
	has_double(push);
	if (is_ordered(push->stack_a) == 1)
	{
		free_lists(push);
		exit_error();
	}
	return (0);
}

static void	transform_and_add(t_push *push, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atol(argv[i]) > MAX_INT || ft_atol(argv[i]) < MIN_INT)
		{
			free_lists(push);
			exit_error();
		}
		else
			insert_end(&push->stack_a, ft_atol(argv[i]));
		i++;
	}
}
