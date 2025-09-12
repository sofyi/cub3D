/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slamhaou <slamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:05:53 by slamhaou          #+#    #+#             */
/*   Updated: 2025/09/11 15:18:26 by slamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*arr;
	int		i;
	int		j;
	
	if (!s1 && s2)
		return (str_dup(s2));
	if (!s2 && s1)
		return (s1);
	arr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		arr[j++] = s1[i++];
	i = 0;
	while (s2[i])
		arr[j++] = s2[i++];
	arr[j] = '\0';
	free(s1);
	return (arr);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	str_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (!s1[i] && !s2[i])
		return (1);
	return (0);
}

int	serch(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*str_dup(char *s)
{
	int	i;
	char	*arr;
	
	i = 0;
	arr = malloc(ft_strlen(s) + 1);
	if (!arr)
		return (NULL);
	while (s[i])
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
	
}

void	err_msg(char *str, t_data *data)
{
	int	i;

	i = 0;
	write(2, str, ft_strlen(str));
	if (!data)
		return ;
	while (i < 2)
		if (data->clr)
			free(data->clr[i++]);
	i = 0;
	while (i < 4)
		if (data->path_txter)
			free(data->path_txter[i++]);
	free(data->clr);
	free(data->path_txter);
	
}

void	ft_fre(void *lin, char **str)
{
	int i;
	
	i = 0;
	if (lin)
		free(lin);
	if (str)
	{
		while (str[i])
			free(str[i++]);
	}
}