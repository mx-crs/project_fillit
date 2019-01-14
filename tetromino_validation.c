/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetromino_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anesteru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:13:47 by anesteru          #+#    #+#             */
/*   Updated: 2017/11/25 16:13:49 by anesteru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_two(char *copy, int i)
{
	if (copy[i + 2] == '#' || copy[i + 6] == '#' ||
		copy[i + 4] == '#' || copy[i + 10] == '#')
		return (1);
	return (0);
}

int		check_r(char *copy, int i)
{
	if (copy[i + 2] == '#' && copy[i + 6] == '#')
		return (1);
	else if (copy[i + 2] == '#' && copy[i + 6] != '#')
	{
		if (copy[i + 3] == '#' || copy[i + 7] == '#')
			return (1);
	}
	else if (copy[i + 2] != '#' && copy[i + 6] == '#')
	{
		if (copy[i + 7] == '#' || copy[i + 11] == '#')
			return (1);
	}
	return (0);
}

int		check_l(char *copy, int i)
{
	if (copy[i + 6] == '#' && (copy[i + 4] == '#' || copy[i + 7] == '#'
		|| copy[i + 11] == '#' || copy[i + 10] == '#'))
		return (1);
	else if (copy[i + 10] == '#' && (copy[i + 11] == '#' ||
		copy[i + 15] == '#' || copy[i + 9] == '#'))
		return (1);
	else if (copy[i + 4] == '#' && (copy[i + 3] == '#' ||
		copy[i + 9] == '#' || copy[i + 10] == '#'))
		return (1);
	return (0);
}

int		check_tetro(char *copy, int i)
{
	if (copy[i + 1] == '#' && copy[i + 5] == '#' && check_two(copy, i) == 1)
		return (1);
	else if (copy[i + 1] == '#' && copy[i + 5] != '#' && check_r(copy, i) == 1)
		return (1);
	else if (copy[i + 5] == '#' && copy[i + 1] != '#' && check_l(copy, i) == 1)
		return (1);
	return (0);
}

int		tetromino_validation(char *copy, int size)
{
	int i;
	int b;

	i = 0;
	b = 20;
	while (b <= size)
	{
		while (i < b)
		{
			if (copy[i] == '#')
			{
				if (check_tetro(copy, i) == 1)
					break ;
				else
					return (0);
			}
			i++;
		}
		i = b;
		b += 21;
	}
	return (1);
}
