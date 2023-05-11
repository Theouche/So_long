/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:53:24 by tlorne            #+#    #+#             */
/*   Updated: 2023/05/11 10:42:52 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_swap(t_data *data, int x, int y)
{
	if (data->coord_x == data->coord_ex && data->coord_y == data->coord_ey)
	{
		data->map[data->coord_x + x][data->coord_y + y] = 'P';
		data->map[data->coord_x][data->coord_y] = 'E';
		data->coord_x += x;
		data->coord_y += y;
	}
	else
	{
		data->map[data->coord_x + x][data->coord_y + y] = 'P';
		data->map[data->coord_x][data->coord_y] = '0';
		data->coord_x += x;
		data->coord_y += y;
	}
}

void	ft_move(t_data *data, int x, int y)
{
	data->count++;
	if (data->map[data->coord_x + x][data->coord_y + y] == '1')
		return ;
	else if (data->map[data->coord_x + x][data->coord_y + y] == 'C')
	{
		data->c_collected++;
		data->map[data->coord_x + x][data->coord_y + y] = '0';
	}
	else if (data->map[data->coord_x + x][data->coord_y + y] == 'E')
	{
		if (data->c_collected == data->env.count_c)
			ft_win(data);
	}
	ft_printf("steps : %d\n", data->count);
	ft_swap(data, x, y);
	create_map(data);
}

int	key_move(int key, t_data *data)
{
	if (key == KEY_UP || key == KEY_W)
		ft_move(data, -1, 0);
	if (key == KEY_DOWN || key == KEY_S)
		ft_move(data, 1, 0);
	if (key == KEY_RIGHT || key == KEY_D)
		ft_move(data, 0, 1);
	if (key == KEY_LEFT || key == KEY_A)
		ft_move(data, 0, -1);
	if (key == KEY_ESC)
		ft_quit(data);
	return (0);
}
