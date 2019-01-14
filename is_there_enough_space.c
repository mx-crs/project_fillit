/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_there_enough_space.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anesteru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 21:37:10 by anesteru          #+#    #+#             */
/*   Updated: 2017/12/04 21:37:14 by anesteru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_sqv_side(char *field)
{
	int i;

	i = 0;
	while (field[i] != '\n')
		i++;
	return (i);
}

int		is_too_long(char *field, int p, char *tetro)
{
	int n;
	int sqv_side;

	n = 16;
	sqv_side = get_sqv_side(field);
	while (--n)
		if (tetro[n] >= 'A')
			break ;
	if ((n / 5) + (p / (sqv_side + 1)) <= sqv_side - 1)
		return (1);
	return (0);
}

int		is_there_enough_space(char *field, char *tetro, int p)
{
	int i;
	int sqv_side;

	i = 0;
	sqv_side = get_sqv_side(field) + 1;
	while (i < 16)
	{
		if (tetro[i] == '\n')
			p += sqv_side - 5;
		if (tetro[i] >= 'A' && field[p] != '.')
			return (0);
		i++;
		p++;
	}
	return (1);
}
