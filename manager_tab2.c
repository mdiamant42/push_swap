/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_tab2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:21:34 by mdiamant          #+#    #+#             */
/*   Updated: 2023/05/29 15:21:36 by mdiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_jtab(t_list **a, t_jtb ***jtab, int *tabi, int tabm_len)
{
	int	i;

	i = 0;
	mall_jtab(*a, jtab, tabi_len(tabi), tabm_len);
	while (tabi[i] != -1)
	{
		(*jtab)[i]->index = tabi[i];
		(*jtab)[i]->s_len = make_jtab2(*a, (*jtab)[i], tabi[i]);
		(*jtab)[i]->a = *a;
		i++;
	}
	while ((*jtab)[i])
	{
		if (!(*jtab)[i]->tabs)
			return ;
		if (!(*jtab)[i]->inclu)
			return ;
		if (!(*jtab)[i]->exclu)
			return ;
		if (!(*jtab)[i]->p_line)
			return ;
		if (!(*jtab)[i]->pl_temp)
			return ;
		i++;
	}
}

void	mall_jtab(t_list *a, t_jtb ***jtab_real, int t_len, int tabm_len)
{
	int		i;
	t_jtb	**jtab;

	i = 0;
	jtab = (t_jtb **)malloc(sizeof(t_jtb *) * (t_len + 1));
	if (!jtab)
	{
		ft_printf("Error t_jtb\n");
		exit(0);
	}
	*jtab_real = jtab;
	while (i < t_len)
	{
		jtab[i] = (t_jtb *)malloc(sizeof(t_jtb) * (t_len + 1));
		if (!jtab[i])
			return ;
		jtab[i]->tabs = (int *)malloc(sizeof(int) * ft_lstsize(a) - tabm_len);
		if (!jtab[i]->tabs)
			return ;
		mall_jtab3(&jtab[i], t_len + tabm_len);
		jtab[i]->index = 0;
		jtab[i]->s_len = 0;
		i++;
	}
	jtab[i] = NULL;
}

int	make_jtab2(t_list *a, t_jtb *jtab, int index)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->index == index)
		{
			jtab->tabs[i] = a->content;
			i++;
		}
		a = a->next;
	}
	return (i);
}

int	tabi_len(int *tabi)
{
	int	i;

	i = 0;
	while (tabi[i] != -1)
		i++;
	return (i);
}

void	mall_jtab3(t_jtb **jtab, int len)
{
	(*jtab)->inclu = (int *)malloc(sizeof(int) * (len + 1));
	(*jtab)->exclu = (int *)malloc(sizeof(int) * (len + 1));
	(*jtab)->p_line = (int *)malloc(sizeof(int) * (len + 1));
	(*jtab)->pl_temp = (int *)malloc(sizeof(int) * (len + 1));
	(*jtab)->excl_2 = (int *)malloc(sizeof(int) * (len + 1));
	if (!(*jtab)->pl_temp || !(*jtab)->p_line || !(*jtab)->exclu
		|| !(*jtab)->inclu || !(*jtab)->excl_2)
		return ;
	while (len >= 0)
	{
		(*jtab)->inclu[len] = -1;
		(*jtab)->exclu[len] = -1;
		(*jtab)->p_line[len] = -1;
		(*jtab)->pl_temp[len] = -1;
		(*jtab)->excl_2[len] = -1;
		len--;
	}
}
