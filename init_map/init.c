/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:13:46 by sshawish          #+#    #+#             */
/*   Updated: 2025/05/28 08:37:30 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		ft_printf("Error\nfailed to initialize mlx\n");
		exit(1);
	}
	data->window = mlx_new_window(data->mlx, 800, 800, "cub3D");
	if (data->window == NULL)
	{
		ft_printf("Error\nfailed to create window\n");
		exit(1);
	}
}

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->window = NULL;
	data->textures = NULL;
	data->img.ptr = NULL;
	data->img.addr = NULL;
	data->north_texture = NULL;
	data->south_texture = NULL;
	data->west_texture = NULL;
	data->east_texture = NULL;
	data->floor_color = -1;
	data->ceiling_color = -1;
	data->map = NULL;
	data->map_size = 0;
	data->mouse_x = 0;
	data->tex_flag = 0;
}

void	init_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
			|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				data->player.pos_y = i + 0.5;
				data->player.pos_x = j + 0.5;
				set_player_direction(data, data->map[i][j]);
				data->map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}
