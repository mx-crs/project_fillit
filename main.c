/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anesteru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:13:09 by anesteru          #+#    #+#             */
/*   Updated: 2017/11/25 16:13:15 by anesteru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		size_of_file(char *file_name)
{
	int		fd;
	int		size;
	char	buf[BUF_SIZE];

	size = 0;
	fd = open(file_name, O_RDONLY);
	if (read(fd, buf, (BUF_SIZE - 1)) == -1)
		return (-1);
	while (read(fd, buf, BUF_SIZE))
		size++;
	if (close(fd) == -1)
		return (-1);
	return (size);
}

char	*create(char *file)
{
	int		fd;
	int		size;
	char	buf[BUF_SIZE];
	char	*copy;

	size = size_of_file(file);
	if (size == -1)
		return (0);
	copy = (char *)malloc(sizeof(char) * size + 1);
	if (!copy)
		return (0);
	copy[size] = '\0';
	size = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, buf, BUF_SIZE))
		copy[size++] = buf[0];
	if (close(fd) == -1)
		return (0);
	return (copy);
}

int		validation(char *copy, char *file_name)
{
	int size;

	size = size_of_file(file_name);
	if (size == -1)
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (file_validation(copy, size) == 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (tetromino_validation(copy, size) == 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	else
		return (1);
}

char	*fillit(char *copy, char *file_name)
{
	char	**tet_arr;
	char	*result;
	int		size;

	size = size_of_file(file_name);
	tet_arr = split_tetros(copy, size);
	place_top_left(tet_arr);
	result = fill_field(tet_arr);
	free_tetros(tet_arr, number_of_tetros(size));
	return (result);
}

int		main(int ac, char **av)
{
	char	*copy;
	char	*result;
	int		i;

	if (ac > 2 || ac < 2)
	{
		write(1, "usage: ./fillit file_name\n", 26);
		return (0);
	}
	copy = create(av[1]);
	if (validation(copy, av[1]) == 0)
	{
		free(copy);
		return (0);
	}
	result = fillit(copy, av[1]);
	i = 0;
	while (result[i] != '\0')
		write(1, &result[i++], 1);
	free(result);
	return (0);
}
