/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slamhaou <slamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:27:07 by slamhaou          #+#    #+#             */
/*   Updated: 2025/10/03 14:07:45 by slamhaou         ###   ########.fr       */
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
	int		**clr;
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
/////////////////////////////-----check----------//////////////
int	check_color(char *str, t_data *data, char c, int i);
int	color_or_paht(char *str);
int	dot_cub(char *str);
int S_W_E_N(char c);
char	*skip_spc(char *str);
int	empt_lin(char *lin);
/////////////////////////-----------maps------------///////////
int	get_map(t_data *data, int fd);
int check_map(char **map);
int	how_many_pl(char *p, char *str, int *count);
#endif