/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_function_vol2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:18:46 by vtasia            #+#    #+#             */
/*   Updated: 2022/04/07 10:19:10 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	char	tmp_c;

	tmp_c = (char)c;
	while (*s)
	{
		if (*s == tmp_c)
			return ((char *)s);
		s++;
	}
	if (*s == tmp_c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(s1) + 1;
	tmp = (char *)malloc(len * sizeof(char));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, s1, len);
	return (tmp);
}

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	if (dest == (NULL) || src == (NULL))
		return (0);
	i = 0;
	while (*(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}
