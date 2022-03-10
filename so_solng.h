
#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "minilibx/mlx.h"


typedef struct	s_option {
/**окно*/
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		im_wid;
	int 	im_hei;
/**изображение*/
	void	*mlx;
	void	*win;
/**карта*/
	char	*map;
/**элементы для карты*/
	void 	*im_P;
	void 	*im_1;
	void 	*im_0;
	void 	*im_С;
	void 	*im_E;
/**положение грока*/
	int 	p_x;
	int 	p_y;

}				t_option;

int		key_hook(int keycode, t_option *vars);
void	ft_putstr_fd(char *s, int fd);

#endif //SO_LONG_H
