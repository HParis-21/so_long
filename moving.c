/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 14:47:39 by hparis            #+#    #+#             */
/*   Updated: 2021/08/08 14:47:41 by hparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	errors(char *line)
{
	printf("%s", line);
	exit(0);
}

int	end_game(t_option *vars, int i)
{
	int	y;

	y = 0;
	if (vars->map)
	{
		while (vars->map[y])
		{
			free(vars->map[y]);
			vars->map[y] = NULL;
			y++;
		}
		free(vars->map);
		vars->map = NULL;
	}
	if (i == 1)
		errors("Error - bad map\n");
	if (i == 2)
		errors("YOU WIN!\n");
	if (i == 3)
		errors("GAME OVER!\n");
	exit(0);
}

void	step(t_option *vars, int x, int y, char c)
{
	vars->map[(vars->p_y + y)][(vars->p_x + x)] = 'P';
	if (c == 'A')
		vars->im_P = vars->im_PA;
	if (c == 'D')
		vars->im_P = vars->im_PD;
	if (c == 'W')
		vars->im_P = vars->im_PW;
	if (c == 'S')
		vars->im_P = vars->im_PS;
	vars->map[vars->p_y][vars->p_x] = '0';
	vars->p_x = vars->p_x + x;
	vars->p_y = vars->p_y + y;
	vars->count_step++;
	print_step(vars);
}

void	moving(t_option *vars, int x, int y, char c)
{
	if (vars->map[vars->p_y + y][vars->p_x + x] != '1')
	{
		if (vars->map[vars->p_y + y][vars->p_x + x] == 'C')
		{
			vars->count_C--;
			step(vars, x, y, c);
		}
		else if ((vars->map[vars->p_y + y][vars->p_x + x] == 'E') && \
				(vars->count_C == 0))
		{
			vars->count_step++;
			print_step(vars);
			end_game(vars, 2);
		}
		else if (vars->map[vars->p_y + y][vars->p_x + x] == '0')
			step(vars, x, y, c);
		else if (vars->map[vars->p_y + y][vars->p_x + x] == 'N')
			end_game(vars, 3);
		writ_map(vars, 0, 0);
	}
}

int	key_hook(int keycode, t_option *vars)
{
	(void)vars;
	if (keycode == 53)
		exit(0);
	if (keycode == 0)
		moving(vars, -1, 0, 'A');
	if (keycode == 1)
		moving(vars, 0, 1, 'S');
	if (keycode == 2)
		moving(vars, 1, 0, 'D');
	if (keycode == 13)
		moving(vars, 0, -1, 'W');
	return (0);
}
