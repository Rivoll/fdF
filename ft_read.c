/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_norme.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 07:48:17 by pkeita            #+#    #+#             */
/*   Updated: 2017/10/09 07:48:19 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**ft_readfill(char *line, int y, t_stock *stock, int check)
{
	int ret;

	while ((ret = get_next_line((const int)stock->fd, &line)))
	{
		if (ret == -1)
			return (NULL);
		if (!line[0])
			break ;
		if (check == 0)
			check = ft_check(line, 0);
		else
		{
			if (check != ft_check(line, 0))
				ft_exit(ERR_BAD_FILE_NAME);
		}
		stock->tab = ft_addtabi(stock->tab, line, check, y++);
	}
	stock->x = check;
	stock->y = y - 1;
	if (check == 0)
		return (NULL);
	stock->hauteur = WINDOW_SIZE / stock->y;
	stock->longueur = WINDOW_SIZE / stock->x;
	return (stock->tab);
}

int		ft_check(char *line, int nb)
{
	int i;

	i = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '\0')
			break ;
		if (line[i] == '-')
			i++;
		if (!ft_isdigit(line[i]))
			ft_exit(ERR_BAD_FILE_NAME);
		while (line[i] >= '0' && line[i] <= '9')
			i++;
		++nb;
		if (line[i] == ',' && !ft_ishexa(line + i + 1))
			ft_exit(ERR_BAD_FILE_NAME);
		while (line[i] && line[i] != ' ')
			i++;
	}
	if (nb < 1 && line[0] != '\0')
		ft_exit(ERR_BAD_FILE_NAME);
	return (nb);
}

int		**ft_addtabi(int **grille, char *line, int nb_elem, int y)
{
	int i;
	int **tgrille;
	int x;

	i = 0;
	x = 0;
	tgrille = ft_creat_tabi2(nb_elem, y);
	y > 1 ? ft_tabi2copy(grille, tgrille, nb_elem, y) : 0;
	while (line[i])
	{
		while (!(line[i] >= '0' && line[i] <= '9') && line[i] != '-' && line[i])
			i++;
		if (line[i] == '\0')
			break ;
		tgrille[y - 1][x++] = ft_atoi(line + i);
		line[i] == '-' ? i++ : 0;
		while (line[i] >= '0' && line[i] <= '9')
			i++;
		while (line[i] && line[i] != ' ')
			i++;
		while (line[i] == ' ')
			i++;
	}
	y > 1 ? ft_deltab2((void***)&grille, y - 1) : 0;
	return (tgrille);
}
