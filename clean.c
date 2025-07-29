/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:00:46 by falhaimo          #+#    #+#             */
/*   Updated: 2025/05/28 08:32:30 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void	print_map(char **map)
// {
// 	int	i;

// 	i = 0;
// 	while (map[i])
// 	{
// 		ft_putstr_fd(map[i], 1);
// 		ft_putchar_fd('\n', 1);
// 		i++;
// 	}
// }

// void	print_all(t_data *data)
// {
// 	print_map(data->map);
// 	printf("North Texture:%s\n", data->north_texture);
// 	printf("South Texture:%s\n", data->south_texture);
// 	printf("West Texture:%s\n", data->west_texture);
// 	printf("East Texture:%s\n", data->east_texture);
// 	printf("Floor Color: %d\n", data->floor_color);
// 	printf("Ceiling Color: %d\n", data->ceiling_color);
// }

void	free_tex(t_textures *textures)
{
	if (textures->north)
		free(textures->north);
	if (textures->south)
		free(textures->south);
	if (textures->west)
		free(textures->west);
	if (textures->east)
		free(textures->east);
	if (textures->floor)
		free(textures->floor);
	if (textures->door_closed)
		free(textures->door_closed);
	if (textures->door_open)
		free(textures->door_open);
}

void	free_textures(t_data *data)
{
	t_textures	*textures;

	textures = data->textures;
	if (!textures)
		return ;
	if (textures->north)
		mlx_destroy_image(data->mlx, textures->north->ptr);
	if (textures->south)
		mlx_destroy_image(data->mlx, textures->south->ptr);
	if (textures->west)
		mlx_destroy_image(data->mlx, textures->west->ptr);
	if (textures->east)
		mlx_destroy_image(data->mlx, textures->east->ptr);
	if (textures->floor)
		mlx_destroy_image(data->mlx, textures->floor->ptr);
	if (textures->door_closed)
		mlx_destroy_image(data->mlx, textures->door_closed->ptr);
	if (textures->door_open)
		mlx_destroy_image(data->mlx, textures->door_open->ptr);
	free_tex(textures);
	free(textures);
}

void	free_data(t_data *data)
{
	if (data->map)
		free_map(data->map);
	if (data->north_texture)
		free(data->north_texture);
	if (data->south_texture)
		free(data->south_texture);
	if (data->west_texture)
		free(data->west_texture);
	if (data->east_texture)
		free(data->east_texture);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	close_window(t_data *data)
{
	if (data->textures)
		free_textures(data);
	if (data->mlx)
	{
		if (data->img.ptr)
			mlx_destroy_image(data->mlx, data->img.ptr);
		if (data->window)
			mlx_destroy_window(data->mlx, data->window);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free_data(data);
	exit(0);
	return (0);
}
