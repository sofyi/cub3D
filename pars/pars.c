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
int	is_color(char *str)
{
	int	i;

	i = 0;
	if (str[i] == 'F' || str[i] == 'C')
	{
		i++;
		str = skip_spc(str);
		if (str[i] >= '0' && str[i] <= '9')
		{}
	}
	return (-1)
}
char	*skip_spc(char *str)
{
	int	i;

	i = 0;
	
	while (str[i] <= 32)
		i++;
	return (&str[i]);
}

void	get_path_color(int fd, t_data *data)
{
	char	*lin;
	char	*path;
	int		i;
	
	while (1)
	{
		lin = get_next_line(fd);
		if (serch(lin, "1"))
			break ;
		skip_spc(lin);
		if (is_color(lin))
		else if (is_path)
		
	}
}
int	start_pars (char *str, t_data *data)
{
	int		fd;
	
	if (dot_cub(str) == 0)
		return(write(2, "ERORR FILE\n", 12), 1);
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (write(2, "Erorr: no file \n", 18), 1);
	get_path_color(fd, data);
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
