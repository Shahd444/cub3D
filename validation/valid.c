/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawish <sshawish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:56:06 by falhaimo          #+#    #+#             */
/*   Updated: 2025/05/26 13:00:44 by sshawish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	is_wall(char **map)
{
	int	i;
	int	len;
	int	last;

	i = 0;
	if (!map || !map[0])
		return (0);
	if (!check_walls(map[0]))
		return (0);
	while (map[i])
		i++;
	last = i - 1;
	if (!check_walls(map[last]))
		return (0);
	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (map[i][0] != '1' || len == 0)
			return (0);
		if (map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	valid_char(char	**map)
{
	int		i;
	int		j;
	int		player;
	char	c;

	i = 0;
	player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			c = map[i][j];
			if (c != '1' && c != '0' && c != 'N' && c != 'S'
				&& c != 'E' && c != 'W' && c != ' ' && c != 'D' && c != 'O')
				return (0);
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		return (0);
	return (1);
}

int	is_closed(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] && map[i + 1] && (ft_strlen(map[i]) == ft_strlen(map[i + 1])))
		i++;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] == '0' || map[i][j] == ' ')
				&& (map[i + 1][j] == '\0' || map[i - 1][j] == '\0'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_door(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'D' && map[i][j - 1] != '1'
				&& map[i][j + 1] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_map(t_data *data)
{
	if (!is_wall(data->map))
	{
		ft_putstr_fd("Error\nMap is not surrounded by walls\n", 2);
		return (0);
	}
	if (!valid_char(data->map))
	{
		ft_putstr_fd("Error\nInvalid character in map\n", 2);
		return (0);
	}
	if (!is_closed(data->map))
	{
		ft_putstr_fd("Error\nMap is not closed\n", 2);
		return (0);
	}
	if (!check_door(data->map))
	{
		ft_putstr_fd("Error\nDoor is not sorrounded by walls\n", 2);
		return (0);
	}
	return (1);
}
