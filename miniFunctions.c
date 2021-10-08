/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniFunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahsoka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 22:53:28 by bahsoka           #+#    #+#             */
/*   Updated: 2021/10/08 22:53:30 by bahsoka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freeMapStruct(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->height)
		free(map->map[i++]);
	free(map->map);
}

void	displayConsole(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->height)
	{
		printf("%s\n", map->map[i]);
		i++;
	}
}

void	setExit(t_map *map, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->win, \
	map->exit, x * map->blockSize, y * map->blockSize);
}

void	changeCounter(t_map *map)
{
	char	*moves;

	map->moves++;
	moves = ft_itoa(map->moves);
	mlx_put_image_to_window(map->mlx, map->win, map->wall, 0, 0);
	mlx_string_put(map->mlx, map->win, 25, 25, 255255255, moves);
	free(moves);
}

void	changePlayerPosY(t_map *map, int newPos)
{
	if (map->exitBlock == 1)
	{
		map->map[map->posY][map->posX] = 'E';
		map->exitBlock = 0;
		setExit(map, map->posX, map->posY);
	}
	else
		map->map[map->posY][map->posX] = '0';
	if (map->map[newPos][map->posX] == 'E')
		map->exitBlock = 1;
	map->posY = newPos;
	if (map->map[map->posY][map->posX] == 'V')
		quitGame(map);
	map->map[map->posY][map->posX] = 'P';
	changeCounter(map);
	printf("Moves: %d\n", map->moves);
}
