/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 09:51:31 by tlorne            #+#    #+#             */
/*   Updated: 2023/05/11 20:01:02 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	choose_image_player(t_data *data, int x, int y)
{
	if (data->game == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_r, x * 32, y * 32);
	else
	{
		if (data->game % 2 == 0)
			put_image_odd(data, x, y);
		else
			put_image_even(data, x, y);
	}
	data->game++;
}

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
		choose_image_player(data, x, y);
	else if (data->map[y][x] == 'M')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->mob,
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
	ft_footer(data);
}

void	create_image_player(t_data *data)
{
	data->player_r = mlx_xpm_file_to_image(data->mlx_ptr, "./img/Char_R.xpm",
			&data->hp, &data->lp);
	data->player_l = mlx_xpm_file_to_image(data->mlx_ptr, "./img/Char_L.xpm",
			&data->hp, &data->lp);
	data->player_u = mlx_xpm_file_to_image(data->mlx_ptr, "./img/Char_U.xpm",
			&data->hp, &data->lp);
	data->player_d = mlx_xpm_file_to_image(data->mlx_ptr, "./img/Char_D.xpm",
			&data->hp, &data->lp);
	data->player_r1 = mlx_xpm_file_to_image(data->mlx_ptr, "./img/Char_R1.xpm",
			&data->hp, &data->lp);
	data->player_l1 = mlx_xpm_file_to_image(data->mlx_ptr, "./img/Char_L1.xpm",
			&data->hp, &data->lp);
	data->player_u1 = mlx_xpm_file_to_image(data->mlx_ptr, "./img/Char_U1.xpm",
			&data->hp, &data->lp);
	data->player_d1 = mlx_xpm_file_to_image(data->mlx_ptr, "./img/Char_D1.xpm",
			&data->hp, &data->lp);
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
	data->mob = mlx_xpm_file_to_image(data->mlx_ptr, "./img/M.xpm",
			&data->hp, &data->lp);
	create_image_player(data);
	data->step = mlx_xpm_file_to_image(data->mlx_ptr, "./img/steps.xpm",
			&data->hp, &data->lp);
	data->step_wall = mlx_xpm_file_to_image(data->mlx_ptr, "./img/step_wall.xpm",
			&data->hp, &data->lp);
}
