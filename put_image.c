/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:46:15 by tlorne            #+#    #+#             */
/*   Updated: 2023/05/11 13:58:37 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image_odd(t_data *data, int x, int y)
{
	if (data->imput == KEY_UP || data->imput == KEY_W)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player_u, x * 32, y * 32);
	else if (data->imput == KEY_DOWN || data->imput == KEY_S)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player_d, x * 32, y * 32);
	else if (data->imput == KEY_RIGHT || data->imput == KEY_D)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player_r, x * 32, y * 32);
	else if (data->imput == KEY_LEFT || data->imput == KEY_A)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player_l, x * 32, y * 32);
}

void	put_image_even(t_data *data, int x, int y)
{
	if (data->imput == KEY_UP || data->imput == KEY_W)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player_u1, x * 32, y * 32);
	else if (data->imput == KEY_DOWN || data->imput == KEY_S)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player_d1, x * 32, y * 32);
	else if (data->imput == KEY_RIGHT || data->imput == KEY_D)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player_r1, x * 32, y * 32);
	else if (data->imput == KEY_LEFT || data->imput == KEY_A)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player_l1, x * 32, y * 32);
}
