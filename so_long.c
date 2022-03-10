/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 14:15:19 by hparis            #+#    #+#             */
/*   Updated: 2021/08/08 14:15:38 by hparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_var(t_option *vars)
{
	vars->count_C = 0;
	vars->count_E = 0;
	vars->count_P = 0;
	vars->count_step = 0;
	vars->p_x = 0;
	vars->p_y = 0;
}

void	img_init(t_option *vars)
{
	vars->im_P = mlx_xpm_file_to_image(vars->mlx, "./imag/SPR_PS.xpm", \
				&vars->im_wid, &vars->im_hei);
	vars->im_0 = mlx_xpm_file_to_image(vars->mlx, "./imag/SPR_0.xpm", \
				&vars->im_wid, &vars->im_hei);
	vars->im_1 = mlx_xpm_file_to_image(vars->mlx, "./imag/SPR_1.xpm", \
				&vars->im_wid, &vars->im_hei);
	vars->im_C = mlx_xpm_file_to_image(vars->mlx, "./imag/SPR_C.xpm", \
				&vars->im_wid, &vars->im_hei);
	vars->im_E = mlx_xpm_file_to_image(vars->mlx, "./imag/SPR_E.xpm", \
				&vars->im_wid, &vars->im_hei);
	vars->im_N = mlx_xpm_file_to_image(vars->mlx, "./imag/SPR_N.xpm", \
				&vars->im_wid, &vars->im_hei);
	vars->im_PA = mlx_xpm_file_to_image(vars->mlx, "./imag/SPR_PA.xpm", \
				&vars->im_wid, &vars->im_hei);
	vars->im_PD = mlx_xpm_file_to_image(vars->mlx, "./imag/SPR_PD.xpm", \
				&vars->im_wid, &vars->im_hei);
	vars->im_PS = mlx_xpm_file_to_image(vars->mlx, "./imag/SPR_PS.xpm", \
				&vars->im_wid, &vars->im_hei);
	vars->im_PW = mlx_xpm_file_to_image(vars->mlx, "./imag/SPR_PW.xpm", \
				&vars->im_wid, &vars->im_hei);
	if (vars->im_P == NULL || vars->im_0 == NULL || vars->im_1 == NULL || \
		vars->im_C == NULL || vars->im_E == NULL || vars->im_N == NULL)
		errors("Error - not enough file\n");
}

void	writ_map(t_option *vars, int x, int y)
{
	while (vars->map[++y])
	{
		x = -1;
		while (vars->map[y][++x])
		{
			if (vars->map[y][x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->im_1, \
				x * 64, y * 64);
			if (vars->map[y][x] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->im_0, \
				x * 64, y * 64);
			if (vars->map[y][x] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->im_P, \
				x * 64, y * 64);
			if (vars->map[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->im_C, \
				x * 64, y * 64);
			if (vars->map[y][x] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->im_E, \
				x * 64, y * 64);
			if (vars->map[y][x] == 'N')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->im_N, \
				x * 64, y * 64);
		}
	}
}

int	main(int argc, char **argv)
{
	t_option	vars;

	if (argc != 2)
		errors("wrong argument | ./so_long map_big.ber\n");
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		errors("wrong argument | -.ber\n");
	init_var(&vars);
	read_map(argv[1], &vars, 0);
	check_map(&vars, 0, -1, 0);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.im_wid * 64, \
		vars.im_hei * 64, "so_long");
	img_init(&vars);
	writ_map(&vars, 0, -1);
	mlx_hook(vars.win, 17, 0, end_game, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
