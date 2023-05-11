/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 09:51:31 by tlorne            #+#    #+#             */
/*   Updated: 2023/05/11 10:10:35 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	put_img(t_data *data, int x, int y)
{
	if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall,
			x * 32, y * 32);
	else if (data->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit,
			x * 32, y * 32);
	else if (data->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->collect,
			x * 32, y * 32);
	else if (data->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->empty,
			x * 32, y * 32);
	else if (data->map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player,
			x * 32, y * 32);
}

void	create_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->h)
	{
		x = 0;
		while (x < data->l)
		{
			put_img(data, x, y);
			x++;
		}
		y++;
	}
}

void	create_image(t_data *data)
{
	data->hp = 32;
	data->lp = 32;
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, "./img/Img_W.xpm",
			&data->hp, &data->lp);
	data->empty = mlx_xpm_file_to_image(data->mlx_ptr, "./img/Img_Emp.xpm",
			&data->hp, &data->lp);
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr, "./img/Img_Exit.xpm",
			&data->hp, &data->lp);
	data->collect = mlx_xpm_file_to_image(data->mlx_ptr, "./img/Img_C.xpm",
			&data->hp, &data->lp);
	data->player = mlx_xpm_file_to_image(data->mlx_ptr, "./img/Char_R.xpm",
			&data->hp, &data->lp);
}
