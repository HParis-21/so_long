/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_solng.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 23:24:38 by hparis            #+#    #+#             */
/*   Updated: 2021/08/11 23:24:40 by hparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "minilibx/mlx.h"

typedef struct s_option {
	void	*img;
	int		im_wid;
	int		im_hei;
	void	*mlx;
	void	*win;
	char	**map;
	void	*im_P;
	int		count_P;
	void	*im_1;
	void	*im_0;
	void	*im_C;
	int		count_C;
	void	*im_E;
	int		count_E;
	void	*im_N;
	int		p_x;
	int		p_y;
	int		count_step;
	void	*im_PA;
	void	*im_PD;
	void	*im_PS;
	void	*im_PW;
}				t_option;

void	img_init(t_option *vars);
void	writ_map(t_option *vars, int x, int y);
void	check_map(t_option *vars, int x, int y, char c);
void	read_map(char *name, t_option *vars, int len);
void	errors(char *line);
int		end_game(t_option *vars, int i);
void	step(t_option *vars, int x, int y, char c);
void	moving(t_option *vars, int x, int y, char c);
int		key_hook(int keycode, t_option *vars);
void	print_step(t_option *vars);
int		ft_strlen(const char *s);
char	*ft_strnstr(const char *s1, const char *s2, int n);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
#endif //SO_LONG_H
