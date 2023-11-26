/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:22:39 by mdiamant          #+#    #+#             */
/*   Updated: 2023/05/29 15:22:41 by mdiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_replace(t_list **a, t_list **b, int index)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *a;
	while (tmp->index != index)
	{
		tmp = tmp->next;
		i++;
	}
	if (i < ft_lstsize(*a) / 2)
		while ((*a)->index != index)
			ft_rr(&a, &b, 1);
	else if (i >= ft_lstsize(*a) / 2)
		while ((*a)->index != index)
			ft_rrr(&a, &b, 1);
}

void	b_replace(t_list **a, t_list **b, int index)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = 0;
	tmp = *b;
	while (tmp->index != index)
	{
		tmp = tmp->next;
		i++;
	}
	if (i < ft_lstsize(*b) / 2)
		while ((*b)->index != index)
			ft_rr(&a, &b, 2);
	else if (i >= ft_lstsize(*b) / 2)
	{
		j = ft_lstsize(*b) - i;
		while (j-- > 0)
			ft_rrr(&a, &b, 2);
	}
}

void	sort_p1(t_jtb **t2, t_list *a)
{
	int	i;
	int	j;
	int	*tabs_tmp;
	int	len;

	i = 0;
	len = ft_lstsize(a);
	tabs_tmp = (int *)malloc(sizeof(int) * len);
	if (!tabs_tmp)
		return ;
	while (t2[i])
	{
		j = 0;
		tabs_tmp[0] = min_nb(t2, i);
		while (++j < t2[i]->s_len)
			tabs_tmp[j] = next_min(t2, i, tabs_tmp[j - 1]);
		copy_tabs(tabs_tmp, t2[i]->tabs, t2[i]->s_len);
		i++;
	}
	free(tabs_tmp);
}

int	next_min(t_jtb **t2, int i, int nb)
{
	int	j;
	int	tmp1;

	j = -1;
	tmp1 = nb;
	while (++j < t2[i]->s_len)
	{
		if (t2[i]->tabs[j] > nb)
		{
			tmp1 = t2[i]->tabs[j];
			break ;
		}
	}
	while (j < t2[i]->s_len)
	{
		if (t2[i]->tabs[j] < tmp1 && t2[i]->tabs[j] > nb)
			tmp1 = t2[i]->tabs[j];
		j++;
	}
	return (tmp1);
}

int	min_nb(t_jtb **t2, int i)
{
	int	tmp1;
	int	j;

	tmp1 = t2[i]->tabs[0];
	j = 0;
	while (j < t2[i]->s_len)
	{
		if (t2[i]->tabs[j] < tmp1)
			tmp1 = t2[i]->tabs[j];
		j++;
	}
	return (tmp1);
}
