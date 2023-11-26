/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:11:30 by mdiamant          #+#    #+#             */
/*   Updated: 2023/05/29 14:35:00 by mdiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*on viens compter le nombre de chiffre dans le nombre*/
static int	cpt_c(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n >= 10 && ++i)
		n /= 10;
	return (i + 1);
}

char	*ft_itoa(int n)
{
	char	*nbstr;
	int		i;
	long	nb;

	nb = n;
	i = cpt_c(nb);
	nbstr = malloc((i + 1) * sizeof(char));
	if (!nbstr)
		return (NULL);
	nbstr[i--] = '\0';
	if (nb < 0)
		nb = -nb;
	while (i >= 0)
	{
		nbstr[i--] = (nb % 10) + 48;
		nb /= 10;
	}
	if (n < 0)
		nbstr[0] = '-';
	return (nbstr);
}
