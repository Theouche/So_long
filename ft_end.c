/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:18:12 by tlorne            #+#    #+#             */
/*   Updated: 2023/05/11 19:56:26 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// quitter le jeu
// detruire les images
// free les map
// afficher le nombre de coups.

#include "so_long.h"

void	ft_destroy(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->wall);
	mlx_destroy_image(data->mlx_ptr, data->empty);
	mlx_destroy_image(data->mlx_ptr, data->player_r);
	mlx_destroy_image(data->mlx_ptr, data->player_r1);
	mlx_destroy_image(data->mlx_ptr, data->player_l);
	mlx_destroy_image(data->mlx_ptr, data->player_l1);
	mlx_destroy_image(data->mlx_ptr, data->player_u);
	mlx_destroy_image(data->mlx_ptr, data->player_u1);
	mlx_destroy_image(data->mlx_ptr, data->player_d);
	mlx_destroy_image(data->mlx_ptr, data->player_d1);
	mlx_destroy_image(data->mlx_ptr, data->exit);
	mlx_destroy_image(data->mlx_ptr, data->collect);
	mlx_destroy_image(data->mlx_ptr, data->mob);
	mlx_destroy_image(data->mlx_ptr, data->step);
	mlx_destroy_image(data->mlx_ptr, data->step_wall);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
}

int	ft_quit(t_data *data)
{
	int	i;

	if (data->game == -1)
		exit(0);
	if (data->game != 0)
	{
		ft_destroy(data);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	free(data->map_str);
	exit(0);
}

void	ft_win(t_data *data)
{
	ft_printf("Congrats, you win in %d steps\n", data->count);
	ft_quit(data);
}

void	ft_lose(t_data *data)
{
	ft_printf("LOL, you lose after %d steps\n", data->count);
	ft_printf("Try again loser\n");
	ft_quit(data);
}
