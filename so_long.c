/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:21:54 by tlorne            #+#    #+#             */
/*   Updated: 2023/05/12 15:51:30 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data.game = 0;
	if (!get_map_n_check(&data, argc, argv))
	{
		ft_quit(&data);
		return (0);
	}
	data.game = 1;
	data.count = 0;
	data.c_collected = 0;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.l * 32,
			(data.h * 32 + FOOTER_H), "Test");
	create_image(&data);
	create_map(&data);
	mlx_hook(data.win_ptr, 2, 1L << 0, key_move, &data);
	mlx_hook(data.win_ptr, 17, 0, ft_quit, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
