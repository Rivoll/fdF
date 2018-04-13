/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <pkeita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 02:37:04 by pkeita            #+#    #+#             */
/*   Updated: 2017/10/16 21:06:19 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include "libft/include/libft.h"

/*
** Error handling
*/

# define ERR_BAD_FILE_NAME "Bad file"
# define WINDOW_SIZE 1200
# define DECALX 400
# define DECALY 0
# define TEST 1
# define HEIGHT 1

/*
**	stuct global
*/

typedef struct	s_stock
{
	int			x;
	int			y;
	double		height;
	int			dx;
	int			dy;
	int			xinc;
	int			yinc;
	int			i;
	int			cumul;
	int			higher;
	int			lower;
	int			yact;
	int			xact;
	int			x1;
	int			x2;
	double		h;
	double		l;
	int			y1;
	int			y2;
	int			**tab;
	int			size_line;
	int			bpp;
	int			iso;
	int			endian;
	int			decal_x;
	int			decal_y;
	int			h_window;
	int			fd;
	int			point;
	int			color;
	int			l_window;
	int			hauteur;
	int			longueur;
	double		zoom;
	void		*mlx;
	void		*win;
	void		*img;
	int			img_x;
	int			img_y;
	char		*data;

}				t_stock;

void			ft_change_color(t_stock *s, int color);

void			ft_event_key_key(int keycode, t_stock *s);

int				**ft_addtabi(int **grille, char *line, int nb_elem, int y);

void			pixel_put(int x, int y, int color, t_stock *stock);

int				**ft_readfill(char *line, int y, t_stock *stock, int check);

int				ft_solve_horizontal(t_stock *s);

int				ft_draw_point(t_stock *s);

int				ft_solve_vertical(t_stock *s);

int				ft_draw_vertical(t_stock *stock, int x, int y);

int				ft_draw_horizontal(t_stock *stock, int x, int y);

int				ft_real_brensenham(t_stock *stock);

int				ft_check(char *line, int nb);

int				ft_draw_img(t_stock *stock, int x, int y);

void			ft_clear_image(t_stock *s);

int				ft_solve(t_stock *stock);

int				ft_init(t_stock *stock, char *file_name);

int				ft_event_key(int keycode, void *param);

int				ft_event_expose(void *param);

int				ft_event_loop(void *param);

int				ft_event_color(int keycode, t_stock *s);

#endif
