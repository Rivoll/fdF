/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_norme.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 02:50:07 by pkeita            #+#    #+#             */
/*   Updated: 2017/10/09 02:54:04 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_draw_point(t_stock *s)
{
	int			index;

	if (s->x1 >= 0 && s->x1 < s->l_window && s->y1 >= 0 && s->y1 < s->l_window)
	{
		index = s->x1 * s->bpp / 8 + s->y1 * s->size_line;
		s->data[index] = s->color & 0xff;
		s->data[++index] = s->color >> 8 & 0xff;
		s->data[++index] = s->color >> 16;
	}
	if (s->x2 >= 0 && s->x2 < s->l_window && s->y2 >= 0 && s->y2 < s->l_window)
	{
		index = s->x2 * s->bpp / 8 + s->y2 * s->size_line;
		s->data[index] = s->color & 0xff;
		s->data[++index] = s->color >> 8 & 0xff;
		s->data[++index] = s->color >> 16;
	}
	return (0);
}

int				ft_solve_vertical(t_stock *s)
{
	int			x;
	int			y;

	y = 0;
	while (y < s->y)
	{
		x = 0;
		while (x < s->x - 1)
		{
			s->x1 = (x * s->longueur - (s->hauteur * y * s->iso)) *
			s->zoom + s->decal_x;
			s->y1 = (y * s->hauteur + (s->longueur * x * s->iso) -
			(s->tab[y][x]) * s->height) * s->zoom + s->decal_y;
			s->x2 = ((x + 1) * s->longueur - (s->hauteur * y * s->iso))
			* s->zoom + s->decal_x;
			s->y2 = (y * s->hauteur + (s->longueur * (x + 1) * s->iso) -
			(s->tab[y][x + 1]) * s->height) * s->zoom + s->decal_y;
			s->yact = y;
			s->xact = x;
			ft_real_brensenham(s);
			x++;
		}
		y++;
	}
	return (0);
}

int				ft_solve_horizontal(t_stock *s)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (x < s->x)
	{
		y = 0;
		while (y < s->y - 1)
		{
			s->x1 = (x * s->longueur - (s->hauteur * y * s->iso)) *
			s->zoom + s->decal_x;
			s->y1 = (y * s->hauteur + (s->longueur * x * s->iso) -
			(s->tab[y][x]) * s->height) * s->zoom + s->decal_y;
			s->x2 = (x * s->longueur - (s->hauteur * (y + 1) * s->iso)) *
			s->zoom + s->decal_x;
			s->y2 = ((y + 1) * s->hauteur + (s->longueur * x * s->iso) -
			(s->tab[y + 1][x]) * s->height) * s->zoom + s->decal_y;
			s->yact = y++;
			s->xact = x;
			ft_real_brensenham(s);
		}
		++x;
	}
	return (0);
}

void			ft_clear_image(t_stock *s)
{
	int			x;
	int			y;
	int			index;

	x = 0;
	y = 0;
	while (y < s->h_window)
	{
		x = 0;
		while (x < s->l_window)
		{
			index = x * s->bpp / 8 + y * s->size_line;
			s->data[index] = 0;
			s->data[++index] = 0;
			s->data[++index] = 0;
			x++;
		}
		y++;
	}
}

void			ft_change_color(t_stock *s, int color)
{
	ft_clear_image(s);
	s->color = color;
	ft_solve(s);
	mlx_put_image_to_window(s->mlx, s->win, s->img, s->img_x, s->img_y);
}
