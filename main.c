/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 04:03:09 by pkeita            #+#    #+#             */
/*   Updated: 2017/10/09 04:03:26 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_stock		s;
	char		*line;

	line = NULL;
	if (ac != 2)
		ft_exit("Usage : ./fdf file");
	if ((s.fd = open(av[1], O_RDONLY)) == -1)
		return (0);
	if ((!(ft_readfill(line, 1, &s, 0))))
		ft_exit("Bad file");
	close(s.fd);
	if ((ft_init(&s, av[1]) == -1))
		return (-1);
	ft_solve(&s);
	mlx_put_image_to_window(s.mlx, s.win, s.img, s.img_x, s.img_y);
	mlx_hook(s.win, 2, 3, ft_event_key, &s);
	mlx_loop(s.mlx);
	return (0);
}
