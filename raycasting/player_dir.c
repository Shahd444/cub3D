/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawish <sshawish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 09:51:21 by falhaimo          #+#    #+#             */
/*   Updated: 2025/05/26 13:00:21 by sshawish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	set_player_direction_north(t_data *data)
{
	data->player.dir_x = 0.0;
	data->player.dir_y = -1.0;
	data->player.plane_x = 0.66;
	data->player.plane_y = 0.0;
}

void	set_player_direction_south(t_data *data)
{
	data->player.dir_x = 0.0;
	data->player.dir_y = 1.0;
	data->player.plane_x = -0.66;
	data->player.plane_y = 0.0;
}

void	set_player_direction_east(t_data *data)
{
	data->player.dir_x = 1.0;
	data->player.dir_y = 0.0;
	data->player.plane_x = 0.0;
	data->player.plane_y = 0.66;
}

void	set_player_direction_west(t_data *data)
{
	data->player.dir_x = -1.0;
	data->player.dir_y = 0.0;
	data->player.plane_x = 0.0;
	data->player.plane_y = -0.66;
}

void	set_player_direction(t_data *data, char direction)
{
	if (direction == 'N')
		set_player_direction_north(data);
	else if (direction == 'S')
		set_player_direction_south(data);
	else if (direction == 'E')
		set_player_direction_east(data);
	else if (direction == 'W')
		set_player_direction_west(data);
}
