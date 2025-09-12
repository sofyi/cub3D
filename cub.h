/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slamhaou <slamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:27:07 by slamhaou          #+#    #+#             */
/*   Updated: 2025/09/11 15:19:14 by slamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
#define CUB_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#define COLORS 1
#define PATH	2
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
typedef struct data_file_cub
{
	char	**map;
	char	**clr;
	char	**path_txter;
}	t_data;

////////////////////////// PARS //////////////////
char	*ft_strjoin(char *s1, char *s2);
char	*str_dup(char *s);
char	*get_next_line(int fd);
int		ft_strlen(char *str);
int		str_cmp(char *s1, char *s2);
int		serch(char *str, char c);
void	err_msg(char *str, t_data *data);
void	ft_fre(void *lin, char **str);
char	**ft_split(char *str, char sep);
#endif