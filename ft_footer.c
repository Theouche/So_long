/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_footer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:54:10 by tlorne            #+#    #+#             */
/*   Updated: 2023/05/12 14:40:01 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_footer(t_data *data)
{
	char	*step_str;

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->step,
		0, data->h * 32);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->step_wall,
		32, data->h * 32);
	step_str = ft_itoa(data->count);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 40, data->h * 32 + 20,
		0x00FFFFFF, step_str);
	free(step_str);
}
