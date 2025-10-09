/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slamhaou <slamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:32:46 by slamhaou          #+#    #+#             */
/*   Updated: 2025/10/08 12:23:31 by slamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int S_W_E_N(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	dot_cub(char *str)
{
	int	i;
	
	i = ft_strlen(str);
	i--;
	while (i > 0 && str[i] != '.')
		i--;
	if (i == 0 || str[i - 1] == '/')
		return (0);
	if (str[i] == '.' && str_cmp(&str[i + 1], "cub"))
		return (1);
	return (0);
	
}

int	color_or_paht(char *str)
{
	char	c;

	if (!str[0] || str[0] == '\n')
		return (0);
	if (str[0] == 'F' || str[0] == 'C')
		return (str[0]);
	c = str[2];
	str[2] = '\0';
	if (str_cmp("NO", str) || str_cmp("SO", str) ||
		str_cmp("WE", str) || str_cmp("EA", str))
		return (str[2] = c, str[0]);
	return (-1);
}

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_lin(char *str)
{
	//printf("error[%s]\n",str);
	str = skip_spc(str);
	while (*str && *str >= '0' && *str <= '9')
		str++;
	str = skip_spc(str);
	if (*str != '\0' && *str != '\n')
		return (-1);
	return (0);

}
int	count_coma(char *str)
{
	int	i;
	int counter;
	
	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == ',')
			counter++;
		i++;
	}
	return (counter);
}
int	check_color(char *str, t_data *data, char c, int i)
{
	char **arr;
	int	j;
	int	k;
	
	j = 0;
	if (count_coma(str) > 2)
		return (-1);
	arr = ft_split(str, ',');
	while (arr[j])
		j++;
	if (j > 3)
		return (-1);
	j = 0;
	k = 0;
	data->clr[i][k++] = c;
	while (arr[0][j])
	{
		if (arr[0][j] == c)
		{
			arr[0][j] = ' ';
			break;
		}
		j++;
	}
	j = 0;
	while (arr[j])
	{
		if (check_lin(arr[j]))
			return (-1);
		data->clr[i][k] = atoi(arr[j]);	
		if (data->clr[i][k] > 255 || data->clr[i][k] < 0)
			return (-1);
		j++;
		k++;
	}
	return (0);
}

