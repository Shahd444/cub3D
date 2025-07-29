/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:35:04 by falhaimo          #+#    #+#             */
/*   Updated: 2025/05/28 08:37:40 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_img	*load_texture(t_data *data, const char *texture_path)
{
	t_img	*texture;

	texture = malloc(sizeof(t_img));
	if (!texture)
		exit(1);
	texture->ptr = mlx_xpm_file_to_image(data->mlx, (char *)texture_path,
			&texture->width, &texture->height);
	if (!texture->ptr)
	{
		free(texture);
		return (NULL);
	}
	texture->addr = mlx_get_data_addr(texture->ptr, &texture->bits_per_pixel,
			&texture->line_length, &texture->endian);
	return (texture);
}

void	load_textures(t_data *data, t_textures *tex)
{
	tex->north = load_texture(data, data->north_texture);
	tex->south = load_texture(data, data->south_texture);
	tex->west = load_texture(data, data->west_texture);
	tex->east = load_texture(data, data->east_texture);
	tex->floor = load_texture(data, FLOOR_TEXTURE_PATH);
	tex->door_closed = load_texture(data, DOOR_TEXTURE_PATH);
	tex->door_open = load_texture(data, DOOR_OPEN_TEXTURE_PATH);
	if (!tex->north || !tex->south || !tex->west
		|| !tex->east || !tex->floor || !tex->door_closed
		|| !tex->door_open)
	{
		write(2, "Error\nloading textures\n", 23);
		close_window(data);
	}
}
