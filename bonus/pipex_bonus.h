/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:22:23 by vtasia            #+#    #+#             */
/*   Updated: 2022/04/07 10:23:23 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	char	**argv;
	char	*limiter;
	int		l;
	int		file1;
	int		file2;
	int		n_cmd;
	char	***cmd;
	int		*fd;
	int		*pid;
	int		*status;
}t_pipex;

void	ps_error(char *str);
t_pipex	*pipex_parsing(char **argv, int argc, char **envr);
void	parrent_process(t_pipex *pip);

size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *dest, const char *src);
char	**ft_split(char const *s, char c);
void	ft_free_split(char	**tmp);
int		gnl(int fd, char **line);

#endif
