/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawish <sshawish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 09:46:32 by falhaimo          #+#    #+#             */
/*   Updated: 2025/05/26 13:00:26 by sshawish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	add_to_map(t_data *data, char *line)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * (data->map_size + 2));
	if (!map)
		exit(1);
	while (i < data->map_size)
	{
		map[i] = data->map[i];
		i++;
	}
	map[i++] = ft_strdup(line);
	map[i] = NULL;
	free(data->map);
	data->map = map;
	data->map_size++;
}

void	advance_dda_step(t_ray *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
}

void	perform_dda(t_data *data, t_ray *ray)
{
	char	tile;

	while (!ray->hit)
	{
		advance_dda_step(ray);
		if (ray->map_y < 0 || ray->map_y >= data->map_size || ray->map_x < 0
			|| ray->map_x >= (int)ft_strlen(data->map[ray->map_y]))
			break ;
		tile = data->map[ray->map_y][ray->map_x];
		if (tile == '1')
		{
			ray->hit = 1;
			ray->hit_door = 0;
		}
		if (tile == 'D' || tile == 'O')
		{
			ray->hit = 1;
			ray->hit_door = 1;
		}
	}
}
