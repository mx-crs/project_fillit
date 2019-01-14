/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tetro.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anesteru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:02:00 by anesteru          #+#    #+#             */
/*   Updated: 2017/12/01 15:02:03 by anesteru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_sqv_len(char *field)
{
	int i;

	i = 0;
	while (field[i] != '\n')
		i++;
	i++;
	return (i);
}

int		draw_tetro(int n, char *field, char *tetro)
{
	int i;
	int s;
	int sqv_len;

	i = 0;
	sqv_len = get_sqv_len(field);
	while (i < 16)
	{
		if (tetro[i] >= 'A')
			field[n] = tetro[i];
		else if (tetro[i] == '\n')
			n += sqv_len - 5;
		i++;
		n++;
	}
	s = where_does_it_fit(field, tetro, 0);
	return (s);
}
