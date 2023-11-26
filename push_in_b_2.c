/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_b_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:22:46 by mdiamant          #+#    #+#             */
/*   Updated: 2023/05/29 15:22:49 by mdiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_mtab(t_mtb **mtab)
{
	if ((*mtab)->current1)
		free((*mtab)->current1);
	if ((*mtab)->current2)
		free((*mtab)->current2);
	free(*mtab);
}

int	maj_m_tab(t_jtb **jtab, t_mtb **mtab)
{
	int	*pos_pline;

	if (!*mtab)
		return (-1);
	if ((*mtab)->current1_len == 0)
	{
		free((*mtab)->current1);
		pos_pline = make_p_line(jtab);
		if (!pos_pline)
		{
			free((*mtab)->current1);
			(*mtab)->current1_len = -1;
		}
		(*mtab)->current1 = copie_current(jtab, pos_pline);
		(*mtab)->current1_len = p_line_len(jtab, (*mtab)->current1);
		rest_s_len(jtab, pos_pline);
	}
	else if ((*mtab)->current2_len == 0)
		return (1);
	return (0);
}

void	maj_m_tab_2(t_jtb **jtab, t_mtb **mtab)
{
	int	*pos_pline;

	if (!*mtab)
		return ;
	free((*mtab)->current2);
	pos_pline = make_p_line(jtab);
	if (!pos_pline)
	{
		free((*mtab)->current2);
		(*mtab)->current2_len = -1;
	}
	(*mtab)->current2 = copie_current(jtab, pos_pline);
	(*mtab)->current2_len = p_line_len(jtab, (*mtab)->current2);
	rest_s_len(jtab, pos_pline);
}

t_mtb	*make_mtab(t_jtb **jtab, t_list *a)
{
	t_mtb	*mtab;
	int		*pline;

	mtab = (t_mtb *)malloc(sizeof(t_mtb));
	if (!mtab)
		return (NULL);
	fill_exclu(a, jtab, NULL);
	pline = make_p_line(jtab);
	mtab->current1 = copie_current(jtab, pline);
	mtab->current1_len = p_line_len(jtab, mtab->current1);
	rest_s_len(jtab, pline);
	fill_exclu(a, jtab, mtab->current1);
	pline = make_p_line(jtab);
	mtab->current2 = copie_current(jtab, pline);
	mtab->current2_len = p_line_len(jtab, mtab->current2);
	rest_s_len(jtab, pline);
	if (!mtab->current1 || !mtab->current2)
		return (NULL);
	return (mtab);
}
