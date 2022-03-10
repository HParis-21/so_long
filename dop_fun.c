/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 14:53:04 by hparis            #+#    #+#             */
/*   Updated: 2021/08/08 14:53:06 by hparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_step(t_option *vars)
{
	printf("STEPS: %d\n", vars->count_step);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->im_1, \
				0 * 64, 0 * 64);
	mlx_string_put(vars->mlx, vars->win, 25, 10, 0, \
	ft_itoa(vars->count_step));
}

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
	}
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = ft_len(n);
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (i)
	{
		if (n < 0)
			str[i] = -(n % 10) + '0';
		else
			str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	if (n > 0)
		str[i] = n + '0';
	return (str);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strnstr(const char *s1, const char *s2, int n)
{
	int	i;
	int	j;

	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			while ((i + j < n) && (s1[i + j] == s2[j]))
			{
				j++;
				if (!s2[j])
					return ((char *)s1 + i);
			}
		}
		i++;
	}
	return (NULL);
}
