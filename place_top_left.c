/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_top_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anesteru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:46:32 by anesteru          #+#    #+#             */
/*   Updated: 2017/11/28 17:46:35 by anesteru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		find_top_space(char *tetro)
{
	int i;
	int n;

	i = 0;
	n = 3;
	while (tetro[i] != '\0')
	{
		if (tetro[i] >= 'A')
			if (i / 5 < n)
				n = i / 5;
		i++;
	}
	return (n);
}

int		find_left_space(char *tetro)
{
	int i;
	int n;

	i = 0;
	n = 3;
	while (tetro[i] != '\0')
	{
		if (tetro[i] >= 'A')
			if (i % 5 < n)
				n = i % 5;
		i++;
	}
	return (n);
}

void	revrite_tetro(char *tetro)
{
	int t;
	int l;
	int i;
	int c;

	i = 0;
	t = find_top_space(tetro) * 5;
	l = find_left_space(tetro);
	while (tetro[i] != '\0')
	{
		if (tetro[i] >= 'A')
		{
			c = tetro[i];
			tetro[i] = '.';
			tetro[i - t - l] = c;
		}
		i++;
	}
}

void	place_top_left(char **tetros)
{
	int i;

	i = 0;
	while (tetros[i])
	{
		revrite_tetro(tetros[i]);
		i++;
	}
}
