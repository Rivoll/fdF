/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabicopy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 08:29:35 by pkeita            #+#    #+#             */
/*   Updated: 2017/10/09 08:29:37 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int		ft_tabicopy(int *tab1, int *tab2, int x)
{
	int i;

	i = 0;
	while (i < x)
	{
		tab2[i] = tab1[i];
		i++;
	}
	return (0);
}
