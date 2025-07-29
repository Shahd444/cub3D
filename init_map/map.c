/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawish <sshawish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:12:21 by falhaimo          #+#    #+#             */
/*   Updated: 2025/05/26 12:59:57 by sshawish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	parse_texture(char *line, char **texture)
{
	while (*line == ' ')
		line++;
	*texture = ft_strdup(line);
	if (!*texture)
		return (1);
	return (0);
}

int	parse_config_line(char *line, t_data *data)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	line += i;
	if (ft_strncmp(line, "NO ", 3) == 0 && !data->north_texture)
		return (parse_texture(line + 3, &data->north_texture));
	else if (ft_strncmp(line, "SO ", 3) == 0 && !data->south_texture)
		return (parse_texture(line + 3, &data->south_texture));
	else if (ft_strncmp(line, "WE ", 3) == 0 && !data->west_texture)
		return (parse_texture(line + 3, &data->west_texture));
	else if (ft_strncmp(line, "EA ", 3) == 0 && !data->east_texture)
		return (parse_texture(line + 3, &data->east_texture));
	else if (ft_strncmp(line, "F", 1) == 0 && data->floor_color == -1)
		return (parse_color(line + 2, &data->floor_color, data));
	else if (ft_strncmp(line, "C", 1) == 0 && data->ceiling_color == -1)
		return (parse_color(line + 2, &data->ceiling_color, data));
	return (-1);
}

int	handle_map_line(char *line, t_data *data)
{
	if (line[0] == '\0')
		return (0);
	else if (line[0] == '1' || line[0] == ' ')
	{
		add_to_map(data, line);
		return (0);
	}
	else
	{
		ft_putstr_fd("Error\nInvalid content after map started\n", 2);
		return (1);
	}
}

int	parse_line(char *line, t_data *data, int *map_start)
{
	int	result;

	if (*map_start)
		return (handle_map_line(line, data));
	result = parse_config_line(line, data);
	if (result == 1)
		return (1);
	else if (result == 0)
		return (0);
	else if (line[0] == '1' || line[0] == ' ')
	{
		*map_start = 1;
		add_to_map(data, line);
	}
	else if (line[0] != '\0')
	{
		ft_putstr_fd("Error\nInvalid identifier in file\n", 2);
		return (1);
	}
	return (0);
}
