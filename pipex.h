/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:14:44 by vtasia            #+#    #+#             */
/*   Updated: 2022/04/07 10:15:09 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	char	**argv;
	int		fd[2];
	int		file1;
	int		file2;
	char	**cmd1;
	char	**cmd2;
}t_pipex;

void	ps_error(char *str);
void	pipex_parsing(t_pipex *pip, char **envr);

size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	**ft_split(char const *s, char c);
void	ft_free_split(char	**tmp);
#endif
