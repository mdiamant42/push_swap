/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:11:30 by mdiamant          #+#    #+#             */
/*   Updated: 2023/05/29 14:47:24 by mdiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_list **a)
{
	t_list	*temp;
	t_list	*last;

	if (!*a || !(*a)->next)
		return ;
	temp = *a;
	last = ft_lstlast(*a);
	*a = (*a)->next;
	last->next = temp;
	temp->next = NULL;
}

void	pa(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!b || !(*b))
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
}

void	sa(t_list **a)
{
	t_list	*temp1;

	if (!a || !(*a)->next)
		return ;
	temp1 = (*a)->next;
	(*a)->next = temp1->next;
	temp1->next = *a;
	*a = temp1;
}

void	rra(t_list **a)
{
	t_list	*temp;
	t_list	*last;

	if (!a || !(*a)->next)
		return ;
	temp = *a;
	last = ft_lstlast(*a);
	while (temp->next != last)
		temp = temp->next;
	last->next = *a;
	temp->next = NULL;
	*a = last;
}

void	verif_end(t_list *a)
{
	int	tmp;

	tmp = a->content;
	a = a->next;
	while (a)
	{
		if (tmp > a->content)
		{
			ft_printf("KO\n");
			return ;
		}
		tmp = a->content;
		a = a->next;
	}
	ft_printf("OK\n");
}
