/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pattern.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:23:24 by mdiamant          #+#    #+#             */
/*   Updated: 2023/05/29 15:23:25 by mdiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verif_order_input(t_list *a)
{
	int	tmp;

	tmp = a->content;
	a = a->next;
	while (a)
	{
		if (a->content < tmp)
			return (1);
		tmp = a->content;
		a = a->next;
	}
	return (0);
}
