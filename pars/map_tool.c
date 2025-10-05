/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slamhaou <slamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:00:39 by slamhaou          #+#    #+#             */
/*   Updated: 2025/10/03 15:25:52 by slamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	str_no_sps(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] <= 32) && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	wall_check(char *str, char c)
{
	int	i;

	i = 0;
	if (c == 'c')
	{
		if (*str != ' ' && *str != '1')
			return (1);
		return (0);
	}
	if (c == 's')
	{
		while (str[i])
		{
			if (str[i] != ' ' && str[i] != '1')
				return (1);            
			i++;
		}
		return (0);	
	}
	return (0);
}

int	empt_lin(char *lin)
{
	char *s;
	
	s = skip_spc(lin);
	if (lin[0] == '\n' || s[0] == '\n')
		return (-1);
	return (0);
}
int	get_map(t_data *data, int fd)
{
	char	*lin;
	char	*long_str;
	char	last_play;
	int		count_p;

	count_p = 0;
	last_play = '0';
	long_str = NULL;
	while (1)
	{
		lin = get_next_line(fd);
		if (!lin)
			break;
		 if (str_no_sps(lin))
			continue;
		break;
	}
	while (1)
	{
		if (!lin)
			break;
		if (how_many_pl(&last_play, lin, &count_p) < 0 || empt_lin(lin))
			return (-1);
		long_str = ft_strjoin(long_str, lin);
		free(lin);
		lin = get_next_line(fd);
	}
	if (!long_str || last_play == '0')
		return (free(long_str),-1);
	data->map = ft_split(long_str, '\n');
	return(0);
}

int	check_zero_player(char *map, int x, char *y_up, char *y_down)
{
	if (map[x - 1] == ' ' || map[x + 1] == ' ' )
		return(1);
	if ((y_down && y_down[x] == ' ') || (y_up && y_up[x] == ' '))
			return(1);
	return(0);
}

int check_map(char **map)
{
	int i;
	int j;

	i = 1;
	if (wall_check(map[0], 's'))
		return (-1);
	while (map[i])
	{
		if(wall_check(&map[i][0], 'c') || wall_check(&map[i][ft_strlen(map[i]) - 1], 'c'))
			return (printf("sss\n"),-1);
		i++;
	}
	i = 1;
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j] == '0' || S_W_E_N(map[i][j]))
				 if (check_zero_player(map[i], j, map[i-1], map[i+1]))
				 	  return (-1);
			j++;
		}
		i++;
	}
	if (wall_check(map[i - 1], 's'))
		return (-1);
	return (0);
}
