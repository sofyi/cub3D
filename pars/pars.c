/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slamhaou <slamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 08:23:40 by slamhaou          #+#    #+#             */
/*   Updated: 2025/10/05 15:34:23 by slamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*skip_spc(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '	')
		i++;
	return (&str[i]);
}

int check_put(char c, char *str, t_data *data)
{
	static int i;
	static int p;
	int		j;
	

	j = 0;
	if (S_W_E_N(c))
	{
		while (data->path_txter[j])
			if (data->path_txter[j++][0] == c)
				return (-1);
		if (p < 4)
		{
			if (check_path(str))
			data->path_txter[p++] = str_dup(str);
		}
	}
	else if (c == 'C' || c == 'F')
	{
		if(check_color(str, data, c, i) < 0)
			return (-1);
		i++;
	}
	return (0);
}

int	init_data(t_data *data)
{
	int	i;

	i = 0;
	data->clr = malloc(sizeof(int *) * 3);
	if (!data->clr)
		return (-1);
	while (i < 2)
	{
		data->clr[i] = malloc(sizeof(int) * 4);
		if (!data->clr[i])
			return (-1);
		i++;
	}
	data->clr[i] = NULL;
	data->path_txter = malloc(sizeof(char *) * 5);
	if (!data->path_txter)
		return (-1);
	if (!data->clr || !data->path_txter)
		return (-1);
	i = 0;
	while (i < 5)
		data->path_txter[i++] = NULL;
	return (0);
}

int	get_path_color(int fd, t_data *data)
{
	char	*lin;
	int		chk;
	int		i;

	i = 0;
	while (i < 6)
	{
		lin = get_next_line(fd);
		if (!lin)
			break ;
		lin = skip_spc(lin);
		if (lin[0] != '\n' && lin[0])
		{
			chk = color_or_paht(lin);
			if (chk == -1)
				return (-1);
			if (check_put(chk, lin, data) == -1)
				return (-1);
			i++;
		}
		
	}
	return (0);
}

int	 how_many_pl(char *p, char *str, int *count)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		str = skip_spc(str);
		if (S_W_E_N(str[i]))
		{
			*p = str[i];
			(*count)++;
		}
		if (str[i] != '0' && str[i] != '1' && S_W_E_N(str[i]) == 0 && !(str[i] <= 32))
			return (-1);
		i++;
	}
	if (*count > 1)
		return (-1);
	return (0);
}
char **get_tst_map(char **map)
{
	int	i;
	int j;
	int max;
	
	i = 0;
	max = 0;
	j = 0;
	while (map[i])
	{
		j = ft_strlen(map[i]);
		if (j > max)
			max = j;
		i++;
	}		
	char **arr = malloc(sizeof(char *) * (i+1));
	arr[i] = NULL;
	i = 0;
	while (map[i])
	{
		j = 0;
		arr[i] = malloc(max + 1);
		while (map[i][j])
		{
			arr[i][j] = map[i][j];
			j++;
		}
		while (j < max)
			arr[i][j++] = ' ';
		arr[i][j] = '\0';
		i++;
	}
	return (arr);
}

int	start_pars (char *str, t_data *data)
{
	int		fd;
	char	**tst_map;
	
	if (dot_cub(str) == 0)
		return(write(2, "ERORR FILE\n", 12), 1);
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (write(2, "Erorr: no file \n", 17), 1);
	init_data(data);
	if (get_path_color(fd, data) == -1)
		return (printf("coco"),-1);
	int j = 0;
	while (j < 4)
		 printf ("[%d]", data->clr[0][j++]);
	 exit (0);
	if (get_map(data, fd) < 0 )
	 	return (err_msg("Erorr: map erorr", data), -1);
	tst_map = get_tst_map(data->map);
	if (check_map(tst_map) < 0)
	 	return (err_msg("EErorr: map erorr", data), -1);
	return (0);
}

int main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		if(start_pars(av[1], &data))
			return (1);	
	}
	else
		write(2, "ERORR: program must take two arg\n", 34);
}
