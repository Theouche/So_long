/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:18:12 by tlorne            #+#    #+#             */
/*   Updated: 2023/05/10 15:22:34 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// quitter le jeu
// detruire les images
// free les map
// afficher le nombre de coups.

#include "so_long.h"

void	ft_destroy(t_data *data)
{
	//mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->wall);
	mlx_destroy_image(data->mlx_ptr, data->empty);
	mlx_destroy_image(data->mlx_ptr, data->player);
	mlx_destroy_image(data->mlx_ptr, data->exit);
	mlx_destroy_image(data->mlx_ptr, data->collect);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
}

int	ft_quit(t_data *data)
{
	int	i;

	if (data->game != 0)
	{
		ft_destroy(data);
		//write(1, "ok\n", 3);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		//write(1, "ok2\n", 4);
	}
	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	//write(1, "ok3\n", 4);
	//free(data->map[i]);
	//write(1, "ok4\n", 4);
	free(data->map);
	//write(1, "ok5\n", 4);
	free(data->map_str);
	//write(1, "ok6\n", 4);
	exit(0);
}

void	ft_win(t_data *data)
{
	//ft_destroy(data);
	ft_printf("Congrats, you win in %d steps\n", data->count);
	ft_quit(data);
}
