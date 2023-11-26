/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:21:28 by mdiamant          #+#    #+#             */
/*   Updated: 2023/05/29 15:21:30 by mdiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*cett fonction sert a creer un tableau de structure
qui contient un tableau d'entier et un int*/
t_tab	**make_tab(t_list *a)
{
	int		i;
	int		len;
	t_tab	**struc;

	i = 0;
	len = ft_lstsize(a);
	struc = (t_tab **)malloc(sizeof(t_tab *) * (len + 1));
	if (!struc || !a)
		return (NULL);
	while (i < len)
	{
		struc[i] = (t_tab *)malloc(sizeof(t_tab) * len);
		if (!struc[i])
			return (NULL);
		struc[i]->tabs = (int *)malloc(sizeof(int) * len);
		if (!struc[i]->tabs)
			return (NULL);
		struc[i]->lens = 0;
		i++;
	}
	struc[i] = NULL;
	return (struc);
}

int	*index_tab(t_list *a, t_tab *tabm)
{
	int	*tabi;
	int	i;

	i = 0;
	if (tabm->lens <= 1)
		return (0);
	tabi = (int *)malloc(sizeof(int) * (tabm->lens + 1));
	if (!tabi)
		return (0);
	while (i < tabm->lens)
		tabi[i++] = -1;
	i = 0;
	while (a)
	{
		if (a->index % 2 == 1)
		{
			if (in_tabi(a, tabm, tabi) == 0)
				tabi[i++] = a->index;
		}
		a = a->next;
	}
	tabi[i] = -1;
	return (tabi);
}

int	in_tabi(t_list *a, t_tab *tabm, int *tabi)
{
	int	i;

	i = 0;
	if (!a || !tabi)
		return (0);
	while (i < tabm->lens)
	{
		if (a->index == tabi[i])
			return (1);
		i++;
	}
	return (0);
}

int	in_tab(t_list *a, t_tab *tabm)
{
	int	i;

	i = 0;
	while (i < tabm->lens)
	{
		if (a->content == tabm->tabs[i])
			return (1);
		if (a->content != tabm->tabs[i])
			i++;
	}
	return (0);
}
