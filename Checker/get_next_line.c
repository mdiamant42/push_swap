/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:11:30 by mdiamant          #+#    #+#             */
/*   Updated: 2023/05/29 14:47:12 by mdiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*line;
	static t_glist	*stack;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	read_stack(fd, &stack);
	if (!stack)
		return (NULL);
	extract_line(stack, &line);
	clean_stack(&stack);
	if (line[0] == '\0')
	{
		free_stack(stack);
		stack = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

void	read_stack(int fd, t_glist **stack)
{
	char	*buffer;
	int		r_read;

	r_read = 1;
	while (!chearch_endline(*stack) && r_read != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return ;
		r_read = read(fd, buffer, BUFFER_SIZE);
		if ((!*stack && r_read == 0) || r_read == -1)
		{
			free(buffer);
			return ;
		}
		buffer[r_read] = '\0';
		go_to_stack(stack, buffer, r_read);
		free(buffer);
	}
}

void	go_to_stack(t_glist **stack, char *buffer, int r_read)
{
	t_glist	*end;
	t_glist	*new_temp;
	int		i;

	new_temp = malloc(sizeof(t_glist));
	if (!new_temp)
		return ;
	new_temp->next = NULL;
	new_temp->content = malloc(sizeof(char) * (r_read + 1));
	if (!new_temp->content)
		return ;
	i = 0;
	while (buffer[i] && i < r_read)
	{
		new_temp->content[i] = buffer[i];
		i++;
	}
	new_temp->content[i] = '\0';
	if (!*stack)
	{
		*stack = new_temp;
		return ;
	}
	end = lst_getlast(*stack);
	end->next = new_temp;
}

void	extract_line(t_glist *stack, char **line)
{
	int	i;
	int	j;

	if (!stack)
		return ;
	generate_line(stack, line);
	if (!*line)
		return ;
	j = 0;
	while (stack)
	{
		i = 0;
		while (stack->content[i])
		{
			if (stack->content[i] == '\n')
			{
				(*line)[j++] = stack->content[i];
				break ;
			}
			(*line)[j++] = stack->content[i++];
		}
		stack = stack->next;
	}
	(*line)[j] = '\0';
}

void	clean_stack(t_glist **stack)
{
	t_glist	*new_temp;
	t_glist	*last;
	int		i;
	int		j;

	new_temp = malloc(sizeof(t_glist));
	if (!stack || !new_temp)
		return ;
	new_temp->next = NULL;
	last = lst_getlast(*stack);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content[i] == '\n')
		i++;
	new_temp->content = malloc(sizeof(char) * (ft_len(last->content + i) + 1));
	if (!new_temp->content)
		return ;
	j = 0;
	while (last->content[i])
		new_temp->content[j++] = last->content[i++];
	new_temp->content[j] = '\0';
	free_stack(*stack);
	*stack = new_temp;
}
