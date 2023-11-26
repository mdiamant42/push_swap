/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:23:35 by mdiamant          #+#    #+#             */
/*   Updated: 2023/05/29 15:23:37 by mdiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_tabi_empty(t_list **a, t_list **b)
{
	if ((*a)->next != 0)
	{
		a_replace(a, b, 0);
		if ((*a)->next != 0)
		{
			ft_p(&a, &b, 1);
			a_replace(a, b, 2);
			ft_p(&a, &b, 2);
		}
		ft_list_instruction(0);
	}
}

void	clear_all(t_list *a, t_tab **tabm, t_tab **pos_line, int *tabi)
{
	clear_tabs(tabm, pos_line, 1);
	ft_lstclear(&a);
	free(tabi);
}

void	creat_list(t_list **a, char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		ft_lstadd_back(a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	if (!*a)
	{
		ft_printf("Error in creat_list\n");
		exit(0);
	}
}

int	ft_min_in_a(t_list *a)
{
	int	min;

	min = a->content;
	while (a)
	{
		if (a->content < min)
			min = a->content;
		a = a->next;
	}
	return (min);
}
