/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:11:30 by vtasia            #+#    #+#             */
/*   Updated: 2022/04/07 10:11:35 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!(*needle))
		return ((char *)haystack);
	i = 0;
	while (!(!haystack && len == 0) && *haystack)
	{
		j = 0;
		while (*(needle + j) && i + j < len)
		{
			if (*(needle + j) == *(haystack + j))
				j++;
			else
			{
				j = 0;
				break ;
			}
		}
		if (*(needle + j) == '\0')
			return ((char *)haystack);
		i++;
		haystack++;
	}
	return (NULL);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (*(dst + i) && i < dstsize)
		i++;
	while (*src && i + 1 < dstsize)
	{
		*(dst + i) = *src;
		i++;
		src++;
	}
	if (i < dstsize)
		*(dst + i) = '\0';
	return (i + ft_strlen(src));
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < dstsize - 1 && *(src + i))
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	tmp = (char *)malloc(len * sizeof(char));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, s1, len);
	ft_strlcat(tmp, s2, len);
	return (tmp);
}
