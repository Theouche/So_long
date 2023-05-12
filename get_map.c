/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:47:53 by tlorne            #+#    #+#             */
/*   Updated: 2023/05/12 16:20:13 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_len_doc(char *filename)
{
	int		fd;
	int		size;
	char	*temp;
	int		res;

	fd = open(filename, O_RDWR);
	temp = malloc(sizeof(char) * 100);
	size = 0;
	res = 1;
	while (res != 0)
	{
		res = read(fd, temp, 100);
		size += res;
	}
	close(fd);
	free(temp);
	return (size);
}

char	*ft_read(int fd, char *filename)
{
	int		size;
	char	*buff;

	size = ft_len_doc(filename);
	if (size <= 1)
		return (NULL);
	buff = malloc(sizeof(char) * size + 1);
	read(fd, buff, size);
	buff[size] = '\0';
	return (buff);
}

int	get_map(t_data *data, char *filename)
{
	int	fd;

	if (!ft_strstr(filename, ".ber"))
	{
		ft_printf("Error\nWrong Map name (.ber).\n");
		return (0);
	}
	fd = open(filename, O_RDWR);
	if (fd == -1)
	{
		ft_printf("ERROR\nOpen failed\n");
		return (0);
	}
	data->map_str = ft_read(fd, filename);
	close(fd);
	if (!data->map_str)
	{
		free(data->map_str);
		return (0);
	}
	data->map = ft_split(data->map_str, '\n');
	return (1);
}

int	get_map_n_check(t_data *data, int argc, char **argv)
{
	if (argc == 1 || argc > 2)
	{
		if (argc == 1)
			ft_printf("Error\nMap name is missing\n");
		if (argc > 2)
			ft_printf("Error\nOnly one map name is expected\n");
		data->game = -1;
		return (0);
	}
	if (!get_map(data, argv[1]))
	{
		data->game = -1;
		return (0);
	}
	if (!check_map(data))
		return (0);
	return (1);
}
