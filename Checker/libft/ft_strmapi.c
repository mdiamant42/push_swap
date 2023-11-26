/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:11:30 by mdiamant          #+#    #+#             */
/*   Updated: 2023/05/29 14:38:19 by mdiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*sdest;
	size_t	i;

	i = ft_strlen(s);
	sdest = malloc((i + 1) * sizeof(char));
	if (!sdest)
		return (0);
	i = -1;
	while (s[++i])
		sdest[i] = (*f)((unsigned int) i, s[i]);
	sdest[i] = 0;
	return (sdest);
}
