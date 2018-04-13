/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_norme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 03:00:50 by pkeita            #+#    #+#             */
/*   Updated: 2017/10/09 03:00:51 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_init(t_stock *stock, char *file_name)
{
	if (!(stock->mlx = mlx_init()))
		return (ft_exit("la connexion a échoué"));
	if (!(stock->win =
		mlx_new_window(stock->mlx, WINDOW_SIZE, WINDOW_SIZE, file_name)))
		return (ft_exit("La connexion a échoué"));
	stock->l_window = WINDOW_SIZE;
	stock->h_window = WINDOW_SIZE;
	stock->img = mlx_new_image(stock->mlx, stock->l_window, stock->h_window);
	stock->data = mlx_get_data_addr(stock->img, &stock->bpp, &stock->size_line,
	&stock->endian);
	stock->decal_x = stock->hauteur * 1;
	stock->decal_y = stock->longueur * 1;
	stock->height = 3;
	stock->img_y = 0;
	stock->img_x = 0;
	stock->zoom = 1;
	stock->color = 0xFFFFFF;
	stock->iso = 1;
	stock->point = 1;
	stock->h = 0;
	stock->l = 0;
	return (0);
}

int			ft_solve(t_stock *stock)
{
	ft_solve_horizontal(stock);
	ft_solve_vertical(stock);
	return (0);
}

int			ft_real_brensenham(t_stock *stock)
{
	int x;
	int y;
	int tx;
	int ty;

	if (stock->point == 0)
		return (ft_draw_point(stock));
	x = stock->x1;
	y = stock->y1;
	tx = stock->x2;
	ty = stock->y2;
	stock->dx = stock->x2 - stock->x1;
	stock->dy = stock->y2 - stock->y1;
	stock->xinc = (stock->dx > 0) ? 1 : -1;
	stock->yinc = (stock->dy > 0) ? 1 : -1;
	stock->dx = abs(stock->dx);
	stock->dy = abs(stock->dy);
	if (stock->dx >= stock->dy)
		ft_draw_horizontal(stock, x, y);
	else
		ft_draw_vertical(stock, x, y);
	return (0);
}

int			ft_draw_horizontal(t_stock *stock, int x, int y)
{
	int index;

	stock->cumul = stock->dx / 2;
	stock->i = 1;
	while (stock->i <= stock->dx)
	{
		x += stock->xinc;
		stock->cumul += stock->dy;
		if (stock->cumul >= stock->dx)
		{
			stock->cumul -= stock->dx;
			y += stock->yinc;
		}
		stock->i++;
		if (x >= 0 && x < stock->l_window && y >= 0 && y < stock->l_window)
		{
			index = x * stock->bpp / 8 + y * stock->size_line;
			stock->data[index] = stock->color & 0xff;
			stock->data[++index] = stock->color >> 8 & 0xff;
			stock->data[++index] = stock->color >> 16;
		}
	}
	return (0);
}

int			ft_draw_vertical(t_stock *stock, int x, int y)
{
	int index;

	stock->cumul = stock->dy / 2;
	stock->i = 1;
	while (stock->i <= stock->dy)
	{
		y += stock->yinc;
		stock->cumul += stock->dx;
		if (stock->cumul >= stock->dy)
		{
			stock->cumul -= stock->dy;
			x += stock->xinc;
		}
		stock->i++;
		if (x >= 0 && x < stock->l_window && y >= 0 && y < stock->l_window)
		{
			index = x * stock->bpp / 8 + y * stock->size_line;
			stock->data[index] = stock->color & 0xff;
			stock->data[++index] = stock->color >> 8 & 0xff;
			stock->data[++index] = stock->color >> 16;
		}
	}
	return (0);
}
