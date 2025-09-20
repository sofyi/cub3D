/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slamhaou <slamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:32:46 by slamhaou          #+#    #+#             */
/*   Updated: 2025/09/18 16:17:12 by slamhaou         ###   ########.fr       */
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

int	check_color(char *str, t_data *data, char c, int i)
{
	int	j;
	int	k;
	char sv;
	
	j = 0;
	data->clr[i][j++] = c;
	str++;
	while(str[0] != '\n' && j < 4)
	{
		if (j == 4)
			break;
		str = skip_spc(str);
		k = 0;
		while (str[k] && str[k] != ',' && str[k] != '\n')
			k++;
		if (str[k])
		{
			sv = str[k];
			str[k] = '\0';
			data->clr[i][j] = atoi(str);
			str[k] = sv;
			while (*str != ',' && *str != '\n')
				str++;
			if (*str == ',')
				str++;
		}
		j++;
	}
	if ((j == 4 && *str != '\n') || (j < 4 && *str == '\n'))
		return (-1);
	return (0);
}
