#include "so_long.h"

void    moveUp(t_map *map)
{
    if(map->map[map->posY - 1][map->posX] == '1')
        return ;
    else if(map->map[map->posY - 1][map->posX] == '0' || map->map[map->posY - 1][map->posX] == 'C' \
            || map->map[map->posY - 1][map->posX] == 'E')
    {
        if(map->map[map->posY - 1][map->posX] == 'C')
        {
            map->coins--;
            mlx_put_image_to_window(map->mlx, map->win, map->bg, map->posX * map->blockSize, (map->posY * map->blockSize) - map->blockSize);
        }
        mlx_put_image_to_window(map->mlx, map->win, map->pl_up, map->posX * map->blockSize, (map->posY * map->blockSize) - map->blockSize);
        mlx_put_image_to_window(map->mlx, map->win, map->bg, map->posX * map->blockSize, map->posY * map->blockSize);
        if(map->map[map->posY - 1][map->posX] == 'E' && map->coins == 0)
            quitGame(map);
    }
    map->map[map->posY][map->posX] = '0';
    map->posY -= 1;
    map->map[map->posY][map->posX] = 'P';
}

void    moveLeft(t_map *map)
{
    if(map->map[map->posY][map->posX - 1] == '1')
        return ;
    else if(map->map[map->posY][map->posX - 1] == '0' || map->map[map->posY][map->posX - 1] == 'C' \
            || map->map[map->posY][map->posX - 1] == 'E')
    {
        if(map->map[map->posY][map->posX - 1] == 'C')
        {
            map->coins--;
            mlx_put_image_to_window(map->mlx, map->win, map->bg, (map->posX * map->blockSize) - map->blockSize, map->posY * map->blockSize);
        }
        mlx_put_image_to_window(map->mlx, map->win, map->pl_left, (map->posX * map->blockSize) - map->blockSize, map->posY * map->blockSize);
        mlx_put_image_to_window(map->mlx, map->win, map->bg, map->posX * map->blockSize, map->posY * map->blockSize);
        if(map->map[map->posY][map->posX - 1] == 'E' && map->coins == 0)
            quitGame(map);
    }
    map->map[map->posY][map->posX] = '0';
    map->posX -= 1;
    map->map[map->posY][map->posX] = 'P';
}

void    moveDown(t_map *map)
{
    if(map->map[map->posY + 1][map->posX] == '1')
        return ;
    else if(map->map[map->posY + 1][map->posX] == '0' || map->map[map->posY + 1][map->posX] == 'C' \
            || map->map[map->posY + 1][map->posX] == 'E')
    {
        if(map->map[map->posY + 1][map->posX] == 'C')
        {
            map->coins--;
            mlx_put_image_to_window(map->mlx, map->win, map->bg, map->posX * map->blockSize, (map->posY * map->blockSize) + map->blockSize);
        }
        mlx_put_image_to_window(map->mlx, map->win, map->pl_front, map->posX * map->blockSize, (map->posY * map->blockSize) + map->blockSize);
        mlx_put_image_to_window(map->mlx, map->win, map->bg, map->posX * map->blockSize, map->posY * map->blockSize);
        if(map->map[map->posY + 1][map->posX] == 'E' && map->coins == 0)
            quitGame(map);
    }
    map->map[map->posY][map->posX] = '0';
    map->posY += 1;
    map->map[map->posY][map->posX] = 'P';
}

void    moveRight(t_map *map)
{
    if(map->map[map->posY][map->posX + 1] == '1')
        return ;
    else if(map->map[map->posY][map->posX + 1] == '0' || map->map[map->posY][map->posX + 1] == 'C' \
            || map->map[map->posY][map->posX + 1] == 'E')
    {
        if(map->map[map->posY][map->posX + 1] == 'C')
        {
            map->coins--;
            mlx_put_image_to_window(map->mlx, map->win, map->bg, (map->posX * map->blockSize) + map->blockSize, map->posY * map->blockSize);
        }
        mlx_put_image_to_window(map->mlx, map->win, map->pl_right, (map->posX * map->blockSize) + map->blockSize, map->posY * map->blockSize);
        mlx_put_image_to_window(map->mlx, map->win, map->bg, map->posX * map->blockSize, map->posY * map->blockSize);
        if(map->map[map->posY][map->posX + 1] == 'E' && map->coins == 0)
            quitGame(map);
    }
    map->map[map->posY][map->posX] = '0';
    map->posX += 1;
    map->map[map->posY][map->posX] = 'P';
}