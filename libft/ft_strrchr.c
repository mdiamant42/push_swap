/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:26:03 by mdiamant          #+#    #+#             */
/*   Updated: 2023/05/29 15:26:03 by mdiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*pts;

	i = -1;
	pts = 0;
	if (!c)
		return (((char *)s) + ft_strlen(s));
	while (((char *)s)[++i])
	{
		if (((char *)s)[i] == (char) c)
		{
			pts = ((char *)s) + i;
		}
	}
	return (pts);
}
	/*si c = NULL alors renvoyer un pointeur sur '\0'*/
