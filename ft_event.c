/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_norme.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 02:58:19 by pkeita            #+#    #+#             */
/*   Updated: 2017/10/09 02:58:21 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_event_key_key(int keycode, t_stock *s)
{
	if (keycode == 116)
		s->zoom += 0.05;
	else if (keycode == 121)
		s->zoom -= (s->zoom > 0.1 ? 0.05 : 0);
	else if (keycode == 115)
		s->zoom += 0.25;
	else if (keycode == 119)
		s->zoom -= (s->zoom > 0.3 ? 0.25 : 0);
	else if (keycode == 65)
		s->point = (s->point == 1 ? 0 : 1);
	else if (keycode == 76)
		s->iso = (s->iso == 1 ? 0 : 1);
	else if (keycode == 123)
		s->decal_x -= 20;
	else if (keycode == 124)
		s->decal_x += 20;
	else if (keycode == 125)
		s->decal_y += 20;
	else if (keycode == 126)
		s->decal_y -= 20;
	else if (keycode == 78)
		s->height -= (s->height == 0.4 ? 0.5 : 0.4);
	else if (keycode == 69)
		s->height += (s->height == -0.4 ? 0.5 : 0.4);
}

int			ft_event_key(int keycode, void *param)
{
	t_stock *s;

	s = param;
	ft_clear_image(s);
	if (keycode == 53)
		exit(0);
	ft_event_key_key(keycode, s);
	ft_solve(s);
	mlx_put_image_to_window(s->mlx, s->win, s->img, s->img_x, s->img_y);
	ft_event_color(keycode, s);
	return (0);
}

int			ft_event_color(int keycode, t_stock *s)
{
	if (keycode == 82)
		ft_change_color(s, 0xFFFFFF);
	else if (keycode == 83)
		ft_change_color(s, 0xFF0000);
	else if (keycode == 84)
		ft_change_color(s, 0x00FF00);
	else if (keycode == 85)
		ft_change_color(s, 0x0000FF);
	else if (keycode == 86)
		ft_change_color(s, 0xFFFF00);
	else if (keycode == 87)
		ft_change_color(s, 0xFF00FF);
	else if (keycode == 88)
		ft_change_color(s, 0x00FFFF);
	else if (keycode == 89)
		ft_change_color(s, 0xF6E497);
	else if (keycode == 91)
		ft_change_color(s, 0x001B0F0);
	else if (keycode == 92)
		ft_change_color(s, 0x3F04323);
	return (0);
}
