/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:11:30 by mdiamant          #+#    #+#             */
/*   Updated: 2023/05/29 14:47:15 by mdiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h> // a virer avant de push
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_glist
{
	char			*content;
	struct s_glist	*next;
}				t_glist;

char	*get_next_line(int fd);

int		chearch_endline(t_glist *stack);

void	read_stack(int fd, t_glist **stack);

void	go_to_stack(t_glist **stack, char *buffer, int r_read);

t_glist	*lst_getlast(t_glist *stack);

int		ft_len(const char *s);

void	extract_line(t_glist *stack, char **line);

void	generate_line(t_glist *stack, char **line);

void	free_stack(t_glist *stack);

void	clean_stack(t_glist **stack);

#endif
