/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slamhaou <slamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 08:23:40 by slamhaou          #+#    #+#             */
/*   Updated: 2025/09/15 11:32:10 by slamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

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

char	*skip_spc(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '	')
		i++;
	return (&str[i]);
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


int check_put_color(char c, char *str, t_data *data)
{
	static int i;
	static int p;
	int	j;
	int	k;
	
	// printf("data [%c]\n",);
	j = 0;
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		while (data->path_txter[j])
			if (data->path_txter[j++][0] == c)
				return (-1);
		if (p < 4)
			data->path_txter[p++] = str_dup(str);
	}
	else if (c == 'C' || c == 'F')
	{
		data->clr[i][0] = c;
		str++;
		j = 1;
		while(j < 4)
		{
			str = skip_spc(str);
			k = 0;
			while (str[k] && str[k] != ',' && str[k] != '\n')
				k++;
			if (str[k])
			{
				str[k] = '\0';
				data->clr[i][j] = atoi(str);
				str[k] = ',';
				while (*str != ',' && *str)
					str++;
				if (*str == ',')
					str++;
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	init_data(t_data *data)
{
	int	i;

	i = 0;
	data->clr = malloc(sizeof(int *) * 3);
	while (i < 2)
		data->clr[i++] = malloc(sizeof(int) * 4);
	data->clr[i] = NULL;
	i = 0;
	data->path_txter = malloc(sizeof(char *) * 5);
	if (!data->clr || !data->path_txter)
		exit (1);
	i = 0;
	while (i < 5)
		data->path_txter[i++] = NULL;
}
int	get_path_color(int fd, t_data *data)
{
	char	*lin;
	int		chk;
	int		i;

	i = 0;
	lin = NULL;
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
				exit (5);
			if (check_put_color(chk, lin, data) == -1)
				return (-1);
			i++;
		}
		ft_fre(lin, NULL);
	}
	return (0);
}

int	get_map(t_data *data, int fd)
{
	char	*lin;
	char	*long_str;
	
	long_str = NULL;
	while (1)
	{
		lin = get_next_line(fd);
		if (!lin)
			break;
		lin = skip_spc(lin);
		if (lin[0] != '1' && lin[0] != '\n')
			return (-1);
		if (lin[0] != '\n')
			long_str = ft_strjoin(long_str, lin);		
		// free(lin);
	}
	if (!long_str)
		return (-1);
	data->map = ft_split(long_str, '\n');
	return(0);
}
int	start_pars (char *str, t_data *data)
{
	int		fd;
	
	if (dot_cub(str) == 0)
		return(write(2, "ERORR FILE\n", 12), 1);
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (write(2, "Erorr: no file \n", 17), 1);
	init_data(data);
	if (get_path_color(fd, data) == -1)
		return (-1);
	if (get_map(data, fd) == -1)
	 	return (err_msg("Erorr: map erorr", data), -1);
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
	int i = 0;
	int k = 0;
	while (data.clr[i])
	{
		k = 0;
		while (k < 4)
			printf ("data[%d] ",data.clr[i][k++]);
		printf ("\n");
		i++;
	}
}
