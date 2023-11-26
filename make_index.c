/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:21:07 by mdiamant          #+#    #+#             */
/*   Updated: 2023/05/29 15:21:09 by mdiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_index_b(t_tab *t, t_list **b)
{
	t_list	*temp;
	int		i;

	if (!*b || !t || !t->tabs || !b)
		return ;
	temp = *b;
	if (t->lens == 1)
	{
		make_index_b2(t, b);
		return ;
	}
	while (temp)
	{
		i = 0;
		while (++i <= t->lens)
		{
			if (temp->content < t->tabs[i - 1] && temp->content > t->tabs[i])
				temp->index = (t->lens - i) * 2 - 1;
			if (temp->content < t->tabs[i - 1] && temp->content > t->tabs[i])
				break ;
		}
		if (temp->content > t->tabs[0])
			temp->index = t->lens * 2 - 1;
		temp = temp->next;
	}
}

void	make_index_b2(t_tab *t, t_list **b)
{
	t_list	*temp;

	if (
		!b || !*b || !t || !t->tabs)
		return ;
	temp = *b;
	while (temp)
	{
		temp->index = 1;
		temp = temp->next;
	}
}

void	make_index_a(t_tab *tabm, t_list **a)
{
	t_list	*temp;
	int		i;
	int		j;

	if (!a || !*a)
		return ;
	temp = *a;
	i = 0;
	while (temp)
	{
		j = 0;
		while (j < tabm->lens)
		{
			if (temp->content == tabm->tabs[j])
			{
				temp->index = (tabm->lens - j - 1) * 2;
				break ;
			}
			j++;
		}
		temp = temp->next;
		i++;
	}
}
