/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:57:51 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/11 10:18:32 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_int(char **argv, int i)
{
	int	z;

	while (argv[i])
	{
		z = 0;
		while (argv[i][z])
		{
			if (argv[i][z] == '+' || argv[i][z] == '-')
				z++;
			if (!ft_isdigit(argv[i][z]))
				return (1);
			z++;
		}
		i++;
	}
	return (0);
}

static int	ft_is_int_valid(char **argv, int i)
{
	while (argv[i])
	{
		if ((ft_atoi(argv[i]) > 2147483647) || (ft_atoi(argv[i]) < -2147483648))
			return (1);
		i++;
	}
	return (0);
}

static int	ft_double(char **argv, int start)
{
	int	tmp;
	int	double_count;
	int	i;
	int	z;

	i = start;
	while (argv[i])
	{
		tmp = ft_atoi(argv[i]);
		double_count = 0;
		z = start;
		while (argv[z])
		{
			if (ft_atoi(argv[z]) == tmp)
				double_count++;
			z++;
		}
		if (double_count != 1)
			return (1);
		i++;
	}
	return (0);
}

void	ft_verify(char **argv, int start)
{
	if (ft_is_int(argv, start))
	{
		ft_putendl_fd("Error", 1);
		exit(1);
	}
	if (ft_is_int_valid(argv, start))
	{
		ft_putendl_fd("Error", 1);
		exit(1);
	}
	if (ft_double(argv, start))
	{
		ft_putendl_fd("Error", 1);
		exit(1);
	}
}
