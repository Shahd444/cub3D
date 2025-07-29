/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:49:31 by falhaimo          #+#    #+#             */
/*   Updated: 2025/05/28 08:36:41 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	validate_color_range(char **range, t_data *data)
{
	data->red = ft_atoi(range[0]);
	data->green = ft_atoi(range[1]);
	data->blue = ft_atoi(range[2]);
	if (data->red < 0 || data->red > 255 || data->green < 0
		|| data->green > 255 || data->blue < 0 || data->blue > 255)
	{
		ft_putstr_fd("Error\ninvalid color value\n", 2);
		return (1);
	}
	return (0);
}

int	validate_color_format(char *line, char ***range)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i++] == ',')
			count++;
		if (ft_isalpha(line[i]))
			return (1);
	}
	if (count != 2)
	{
		ft_putstr_fd("Error\ninvalid color format\n", 2);
		return (1);
	}
	*range = ft_split(line, ',');
	if (!*range || !(*range)[0] || !(*range)[1] || !(*range)[2] || (*range)[3])
	{
		ft_putstr_fd("Error\ninvalid color format\n", 2);
		free_map(*range);
		return (1);
	}
	return (0);
}

int	parse_color(char *line, int *color, t_data *data)
{
	char	**range;

	if (validate_color_format(line, &range))
		return (1);
	if (validate_color_range(range, data))
	{
		free_map(range);
		return (1);
	}
	*color = (data->red << 16) | (data->green << 8) | data->blue;
	free_map(range);
	return (0);
}
