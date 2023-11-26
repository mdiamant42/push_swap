/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in_a_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:22:31 by mdiamant          #+#    #+#             */
/*   Updated: 2023/05/29 15:22:32 by mdiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_tabs(int *src, int *dest, int len)
{
	int	i;

	if (!src || !dest)
		return ;
	i = -1;
	while (++i < len)
		dest[i] = src[i];
}
