/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slamhaou <slamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:00:39 by slamhaou          #+#    #+#             */
/*   Updated: 2025/09/20 15:49:12 by slamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

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
		lin = skip_spc(lin);
		if ((lin[0] != '1' && lin[0] != '\n') || how_many_pl(&last_play, lin, &count_p) < 0)
			return (-1);
		if (lin[0] != '\n')
			long_str = ft_strjoin(long_str, lin);
		ft_fre(lin, NULL);
	}
	if (!long_str || last_play == '0')
		return (free(long_str),-1);
	data->map = ft_split(long_str, '\n');
	return(0);
}

int start_check_mp(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;

	return (0);
}