/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahsoka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 23:08:11 by bahsoka           #+#    #+#             */
/*   Updated: 2021/10/08 23:08:13 by bahsoka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	changePlayerPosX(t_map *map, int newPos)
{
	if (map->exitBlock == 1)
	{
		map->map[map->posY][map->posX] = 'E';
		map->exitBlock = 0;
		setExit(map, map->posX, map->posY);
	}
	else
		map->map[map->posY][map->posX] = '0';
	if (map->map[map->posY][newPos] == 'E')
		map->exitBlock = 1;
	map->posX = newPos;
	if (map->map[map->posY][map->posX] == 'V')
		quitGame(map);
	map->map[map->posY][map->posX] = 'P';
	changeCounter(map);
	printf("Moves: %d\n", map->moves);
}

void	moveUp(t_map *map)
{
	if (map->map[map->posY - 1][map->posX] == '1')
		return ;
	else if (map->map[map->posY - 1][map->posX] == '0'\
			|| map->map[map->posY - 1][map->posX] == 'C' \
			|| map->map[map->posY - 1][map->posX] == 'E')
	{
		if (map->map[map->posY - 1][map->posX] == 'C')
		{
			map->coins--;
			mlx_put_image_to_window(map->mlx, map->win, map->bg, map->posX \
			* map->blockSize, (map->posY * map->blockSize) - map->blockSize);
		}
		mlx_put_image_to_window(map->mlx, map->win, map->pl_up, map->posX \
		* map->blockSize, (map->posY * map->blockSize) - map->blockSize);
		mlx_put_image_to_window(map->mlx, map->win, map->bg, \
		map->posX * map->blockSize, map->posY * map->blockSize);
		if (map->map[map->posY - 1][map->posX] == 'E' && map->coins == 0)
			quitGame(map);
	}
	changePlayerPosY(map, map->posY - 1);
}

void	moveLeft(t_map *map)
{
	if (map->map[map->posY][map->posX - 1] == '1')
		return ;
	else if (map->map[map->posY][map->posX - 1] == '0' \
			|| map->map[map->posY][map->posX - 1] == 'C' \
			|| map->map[map->posY][map->posX - 1] == 'E')
	{
		if (map->map[map->posY][map->posX - 1] == 'C')
		{
			map->coins--;
			mlx_put_image_to_window(map->mlx, map->win, map->bg, (map->posX \
			* map->blockSize) - map->blockSize, map->posY * map->blockSize);
		}
		mlx_put_image_to_window(map->mlx, map->win, map->pl_left, (map->posX \
		* map->blockSize) - map->blockSize, map->posY * map->blockSize);
		mlx_put_image_to_window(map->mlx, map->win, map->bg, \
		map->posX * map->blockSize, map->posY * map->blockSize);
		if (map->map[map->posY][map->posX - 1] == 'E' && map->coins == 0)
			quitGame(map);
	}
	changePlayerPosX(map, map->posX - 1);
}

void	moveDown(t_map *map)
{
	if (map->map[map->posY + 1][map->posX] == '1')
		return ;
	else if (map->map[map->posY + 1][map->posX] == '0' \
			|| map->map[map->posY + 1][map->posX] == 'C' \
			|| map->map[map->posY + 1][map->posX] == 'E')
	{
		if (map->map[map->posY + 1][map->posX] == 'C')
		{
			map->coins--;
			mlx_put_image_to_window(map->mlx, map->win, map->bg, map->posX \
			* map->blockSize, (map->posY * map->blockSize) + map->blockSize);
		}
		mlx_put_image_to_window(map->mlx, map->win, map->pl_front, map->posX \
		* map->blockSize, (map->posY * map->blockSize) + map->blockSize);
		mlx_put_image_to_window(map->mlx, map->win, map->bg, \
		map->posX * map->blockSize, map->posY * map->blockSize);
		if (map->map[map->posY + 1][map->posX] == 'E' && map->coins == 0)
			quitGame(map);
	}
	changePlayerPosY(map, map->posY + 1);
}

void	moveRight(t_map *map)
{
	if (map->map[map->posY][map->posX + 1] == '1')
		return ;
	else if (map->map[map->posY][map->posX + 1] == '0' \
			|| map->map[map->posY][map->posX + 1] == 'C' \
			|| map->map[map->posY][map->posX + 1] == 'E')
	{
		if (map->map[map->posY][map->posX + 1] == 'C')
		{
			map->coins--;
			mlx_put_image_to_window(map->mlx, map->win, map->bg, (map->posX \
			* map->blockSize) + map->blockSize, map->posY * map->blockSize);
		}
		mlx_put_image_to_window(map->mlx, map->win, map->pl_right, (map->posX \
		* map->blockSize) + map->blockSize, map->posY * map->blockSize);
		mlx_put_image_to_window(map->mlx, map->win, map->bg, \
		map->posX * map->blockSize, map->posY * map->blockSize);
		if (map->map[map->posY][map->posX + 1] == 'E' && map->coins == 0)
			quitGame(map);
	}
	changePlayerPosX(map, map->posX + 1);
}
