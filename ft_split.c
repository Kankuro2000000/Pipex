/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:06:00 by vtasia            #+#    #+#             */
/*   Updated: 2022/04/07 10:06:02 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_split_words(char const *s, char c)
{
	int	words;

	words = 0;
	while (*s == c && *s)
		s++;
	while (*s)
	{
		words++;
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
	}
	return (words);
}

static int	ft_split_word_len(char const *s, char c)
{
	int	j;

	j = 0;
	while (*(s + j) != c && *(s + j))
		j++;
	return (j + 1);
}

static void	*ft_split_free(char **tmp)
{
	int	i;

	i = -1;
	while (tmp[++i])
		free (tmp[i]);
	free(tmp);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tmp;	
	int		words;
	int		len_word;
	int		i;

	if (s == NULL)
		return (NULL);
	words = ft_split_words(s, c);
	tmp = (char **)malloc((words + 1) * sizeof(char *));
	if (!tmp)
		return (NULL);
	tmp[words] = (NULL);
	i = -1;
	while (++i < words)
	{
		while (*s == c && *s)
			s++;
		len_word = ft_split_word_len(s, c);
		tmp[i] = (char *)malloc(len_word * sizeof(char));
		if (!tmp[i])
			return (ft_split_free(tmp));
		ft_strlcpy(tmp[i], s, len_word);
		s += len_word;
	}
	return (tmp);
}

void	ft_free_split(char	**tmp)
{
	int	i;

	if (!tmp)
		return ;
	i = -1;
	while (tmp[++i])
		free (tmp[i]);
	free(tmp);
}
