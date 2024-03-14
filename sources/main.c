/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:45:58 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/14 15:05:31 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_args(int argc, char **argv);

int	main(int argc, char **argv)
{
	if (check_args(argc, argv) == 1)
	{
		exit_error();
		exit(1);
	}
	else
		ft_printf("todos são números");
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
