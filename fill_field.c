/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anesteru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 20:13:16 by anesteru          #+#    #+#             */
/*   Updated: 2017/11/29 20:13:20 by anesteru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		size_of_min_square(char **tetros)
{
	int	i;
	int	n;

	i = 0;
	n = 1;
	while (tetros[i] != 0)
		i++;
	while (i * 4 > n * n)
		n++;
	return (n);
}

char	*create_field(char **tetros, int j)
{
	char		*field;
	int			i;
	int			n;
	int			s;

	i = 0;
	s = size_of_min_square(tetros) + j;
	n = s * (s + 1);
	field = (char *)malloc(sizeof(char) * n + 1);
	if (!field)
		return (0);
	field[n] = '\0';
	while (i < n)
	{
		if (i % (s + 1) == s)
			field[i] = '\n';
		else
			field[i] = '.';
		i++;
	}
	return (field);
}

int		where_does_it_fit(char *field, char *tetro, int n)
{
	int i;

	i = empty_space(tetro);
	while (field[n + i] != '.' && is_too_long(field, n, tetro) == 1)
		n++;
	return (n);
}

int		does_not_fit(char **field, char **tetros, int *i)
{
	int			a;
	int			n;
	static int	j = 1;

	if (*i == 0)
	{
		free(*field);
		*field = create_field(tetros, j++);
		n = 0;
	}
	else
	{
		*i -= 1;
		a = back_track_tetro(*field, tetros[*i]);
		n = where_does_it_fit(*field, tetros[*i], ++a);
	}
	return (n);
}

char	*fill_field(char **tetros)
{
	int		sqv_side;
	char	*field;
	int		i;
	int		n;

	i = 0;
	n = 0;
	sqv_side = size_of_min_square(tetros);
	field = create_field(tetros, 0);
	while (tetros[i] != 0)
	{
		if (is_too_long(field, n, tetros[i]) == 0)
			n = does_not_fit(&field, tetros, &i);
		else if (is_there_enough_space(field, tetros[i], n) == 0)
			n = where_does_it_fit(field, tetros[i], ++n);
		else
			n = draw_tetro(n, field, tetros[i++]);
	}
	return (field);
}
