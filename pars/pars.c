/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slamhaou <slamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 08:23:40 by slamhaou          #+#    #+#             */
/*   Updated: 2025/09/03 09:19:16 by slamhaou         ###   ########.fr       */
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

int check_and_put(char c, char *str, t_data *data)
{
	static int i;
	int	j;

	j = 0;
	if (!data->clr || !(c == 'C' || c == 'F') )
		return (0);
	while (data->clr[i])
	{
		if (data->clr[j][0] == c)
			return (-1);
		j++;
	}
	data->clr[i] = str;
	i++;
	if (i == 2)
		data->clr[i] = NULL;
	return (0);
	
}
int	get_path_color(int fd, t_data *data)
{
	char	*lin;
	int		chk;
	int		i;

	i = 0;
	data->clr = malloc(sizeof(char *) * 3);
	data->clr[0] = NULL;
	data->clr[1] = NULL;
	data->path_txter = NULL;
	while (i < 6)
	{
		lin = get_next_line(fd);
		if (!lin)
			break ;
		
		lin = skip_spc(lin);
		if (lin[0] != '\n')
		{
			chk = color_or_paht(lin);
			if (chk == -1)
				exit (5);
			if (check_and_put(chk, lin, data) == -1)
				return (-1);
			i++;
		}
	}
	printf("this first coclor [%s] un second [%s]\n", data->clr[0], data->clr[1]);
	return (0);
}
int	start_pars (char *str, t_data *data)
{
	int		fd;
	
	if (dot_cub(str) == 0)
		return(write(2, "ERORR FILE\n", 12), 1);
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (write(2, "Erorr: no file \n", 17), 1);
	if (get_path_color(fd, data) == -1)
		return (-1);
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
