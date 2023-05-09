/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:21:54 by tlorne            #+#    #+#             */
/*   Updated: 2023/05/09 13:54:58 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*int	number_key(int key)
{
	ft_putnbr_fd(key, 1);
	write(1, "\n", 1);
	return (0);
}*/

int	main(int argc, char **argv)
{
	t_data	data;

	if (!get_map_n_check(&data, argc, argv))
		return (0);
	data.count = 0;
	data.c_collected = 0;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.l * 32, data.h * 32, "Test");
	create_image(&data);
	create_map(&data);
	mlx_key_hook(data.win_ptr, key_move, &data);
	mlx_hook(data.win_ptr, 17, 0, ft_quit, &data);
	//mlx_hook(t_win_list *win, int x_event, int x_mask, int (*funct)(),void *param)
	write(1, "ok7\n", 4);
	mlx_loop(data.mlx_ptr);
	write(1, "ok8\n", 4);
	return (0);
}
