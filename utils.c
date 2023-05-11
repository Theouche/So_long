/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:10:20 by tlorne            #+#    #+#             */
/*   Updated: 2023/05/11 10:21:51 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return (NULL);
	while (big[i])
	{
		j = 0;
		while (big[i + j] == little[j])
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

void	ft_count(t_data *data, char c)
{
	if (c == 'C')
		data->env.count_c++;
	if (c == 'E')
		data->env.count_e++;
	if (c == 'P')
		data->env.count_p++;
}

int	check_char(char c)
{
	if (c == 'E' || c == 'C' || c == 'P' || c == 'M' || c == '1' || c == '0')
		return (1);
	else
		return (0);
}

void	ft_error(t_data *data)
{
	ft_printf("ERROR\nWrong map (Too many E or P or not enough C)\n");
	ft_quit(data);
}
