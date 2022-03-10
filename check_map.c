/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 14:44:45 by hparis            #+#    #+#             */
/*   Updated: 2021/08/08 14:44:48 by hparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_posit( t_option *vars)
{
	if (vars->count_C < 1)
		end_game(vars, 1);
	if (vars->count_E < 1)
		end_game(vars, 1);
	if (vars->count_P != 1 )
		end_game(vars, 1);
	if (vars->im_wid > 250 || vars->im_hei > 250)
		end_game(vars, 1);
}

static void	check_map_wall(t_option *vars)
{
	int	y;
	int	x;

	y = 0;
	while (y < vars->im_hei)
	{
		if (ft_strlen(vars->map[0]) != ft_strlen(vars->map[y]))
			end_game(vars, 1);
		x = 0;
		while (x < vars->im_wid)
		{
			if ((vars->map[0][x] != '1') || \
				(vars->map[vars->im_hei - 1][x] != '1'))
				end_game(vars, 1);
			if ((vars->map[y][0] != '1') || \
				(vars->map[y][vars->im_wid - 1] != '1'))
				end_game(vars, 1);
			x++;
		}
		y++;
	}
	check_posit(vars);
}

void	check_map(t_option *vars, int x, int y, char c)
{
	while (vars->map[++y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			c = vars->map[y][x++];
			if (c != '0' && c != '1' && c != 'C' && c != 'E' && \
				c != 'P' && c != 'N')
				end_game(vars, 1);
			if (c == 'C')
				vars->count_C++;
			if (c == 'E')
				vars->count_E++;
			if (c == 'P')
			{
				vars->p_x = x - 1;
				vars->p_y = y;
				vars->count_P++;
			}
		}
	}
	vars->im_wid = x;
	vars->im_hei = y;
	check_map_wall(vars);
}
