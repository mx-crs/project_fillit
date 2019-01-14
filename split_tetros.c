/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tetros.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anesteru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 16:12:52 by anesteru          #+#    #+#             */
/*   Updated: 2017/11/26 16:13:14 by anesteru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	hash_to_letter(char *tetro, char *copy)
{
	static int	n = 0;
	static int	j = 0;
	static int	a = 'A';
	int			i;

	i = 0;
	while (copy[n] == '\n')
		n++;
	tetro[20] = '\0';
	while (i < 20)
	{
		if (copy[n] == '#')
		{
			j++;
			tetro[i] = a;
			if (j != 0 && j % 4 == 0)
				a++;
		}
		else
			tetro[i] = copy[n];
		i++;
		n++;
	}
}

void	free_tetros(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
}

char	**split_tetros(char *copy, int size)
{
	char	**arr_of_tetros;
	int		i;
	int		num;

	i = 0;
	num = number_of_tetros(size);
	arr_of_tetros = (char **)malloc(sizeof(copy) * num + 1);
	if (!arr_of_tetros)
		return (0);
	while (i < num)
	{
		arr_of_tetros[i] = (char *)malloc(sizeof(char) * 21);
		if (!arr_of_tetros[i])
		{
			free(copy);
			free_tetros(arr_of_tetros, i - 1);
			return (0);
		}
		hash_to_letter(arr_of_tetros[i], copy);
		i++;
	}
	arr_of_tetros[num] = 0;
	free(copy);
	return (arr_of_tetros);
}
