/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 14:39:08 by hparis            #+#    #+#             */
/*   Updated: 2021/08/08 14:39:14 by hparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	prov(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i - 1] == str[i] && str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static int	len_map(char *name)
{
	int		fd;
	int		res;
	int		len;
	char	c;

	len = 0;
	fd = open(name, O_RDONLY);
	if (fd > 0)
	{
		res = read(fd, &c, 1);
		while (res > 0)
		{
			len++;
			res = read(fd, &c, 1);
		}
	}
	if (len == 0 || fd < 0 )
		errors("Error - open/read fail\n");
	close(fd);
	return (len);
}

void	read_map(char *name, t_option *vars, int len)
{
	int		fd;
	char	*temp;

	len = len_map(name);
	temp = malloc (len + 1);
	if (!temp)
		errors("Error - memory error\n");
	fd = open(name, O_RDONLY);
	if ((read(fd, temp, len)) < 0)
	{
		free(temp);
		errors("Error - open/read fail\n");
	}
	close(fd);
	temp[len] = '\0';
	if (prov(temp))
	{
		free(temp);
		errors("Error - bad map\n");
	}
	vars->map = ft_split(temp, '\n');
	if (vars->map == NULL)
		errors("Error - memory error\n");
	free(temp);
}
