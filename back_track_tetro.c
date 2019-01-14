/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_track_tetro.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anesteru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 19:59:49 by anesteru          #+#    #+#             */
/*   Updated: 2017/11/30 19:59:55 by anesteru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_lett(char *tetro)
{
	int i;

	i = 0;
	while (tetro[i] != '\0')
	{
		if (tetro[i] >= 'A')
			return (tetro[i]);
		i++;
	}
	return (0);
}

int		find_place(char *field, char *tetro, int lett)
{
	int i;
	int n;

	i = 0;
	n = empty_space(tetro);
	while (field[i] != lett)
		i++;
	return (i - n);
}

int		back_track_tetro(char *field, char *tetro)
{
	int i;
	int n;
	int lett;

	i = -1;
	lett = get_lett(tetro);
	n = find_place(field, tetro, lett);
	while (field[++i] != '\0')
		if (field[i] == lett)
			field[i] = '.';
	return (n);
}
