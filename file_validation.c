/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anesteru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:13:31 by anesteru          #+#    #+#             */
/*   Updated: 2017/11/25 16:13:33 by anesteru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		num_of_hash(char *copy, int size)
{
	int i;
	int n;
	int b;

	i = 0;
	b = 20;
	if ((size < 20 || size > 545 || (size > 20 && (size - 20) % 21 != 0)))
		return (0);
	while (copy[i] != '\0')
	{
		n = 0;
		if (copy[i] != '.' && copy[i] != '#' && copy[i] != '\n')
			return (0);
		while (i < b)
		{
			if (copy[i] == '#')
				n++;
			i++;
		}
		if (n != 4)
			return (0);
		b += 21;
	}
	return (1);
}

int		file_validation(char *copy, int size)
{
	int i;
	int n;
	int p;

	i = -1;
	p = 0;
	n = 0;
	if (num_of_hash(copy, size) == 0)
		return (0);
	while (copy[++i] != '\0')
	{
		if ((i + 1) % 5 != n && copy[i] != '.' && copy[i] != '#')
			return (0);
		if ((i + 1) % 5 == n && copy[i] != '\n')
			return (0);
		if (copy[i] == '\n' && copy[i - 1] != '\n')
		{
			p++;
			if (p % 4 == 0)
				n++;
			if (n == 5)
				n = 0;
		}
	}
	return (1);
}
