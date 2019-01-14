/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anesteru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:23:29 by anesteru          #+#    #+#             */
/*   Updated: 2017/12/05 17:23:32 by anesteru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUF_SIZE 1

int		file_validation(char *copy, int size);
int		tetromino_validation(char *copy, int size);
char	**split_tetros(char *copy, int size);
int		number_of_tetros(int size);
void	place_top_left(char **tetros);
char	*fill_field(char **tetros);
int		back_track_tetro(char *field, char *tetro);
int		draw_tetro(int n, char *field, char *tetro);
int		is_too_long(char *field, int p, char *tetro);
int		is_there_enough_space(char *field, char *tetro, int p);
int		empty_space(char *tetro);
int		where_does_it_fit(char *field, char *tetro, int n);
void	free_tetros(char **arr, int i);

#endif
