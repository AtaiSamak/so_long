#include "so_long.h"

void    setExit(t_map *map, int x, int y)
{
    mlx_put_image_to_window(map->mlx, map->win, map->exit, x * map->blockSize, y * map->blockSize);
}

void    changeCounter(t_map *map)
{
    char *moves;

    map->moves++;
    moves = ft_itoa(map->moves);
    mlx_put_image_to_window(map->mlx, map->win, map->wall, 0, 0);
    mlx_string_put(map->mlx, map->win, 25, 25, 255255255, moves);
    free(moves);
}

void    changePlayerPosY(t_map *map, int newPos)
{
    if(map->exitBlock == 1)
    {
        map->map[map->posY][map->posX] = 'E';
        map->exitBlock = 0;
        setExit(map, map->posX, map->posY);
    }
    else
        map->map[map->posY][map->posX] = '0';
    if(map->map[newPos][map->posX] == 'E')
        map->exitBlock = 1;
    map->posY = newPos;
    if(map->map[map->posY][map->posX] == 'V')
        quitGame(map);
    map->map[map->posY][map->posX] = 'P';
    changeCounter(map);
}

void    changePlayerPosX(t_map *map, int newPos)
{
    if(map->exitBlock == 1)
    {
        map->map[map->posY][map->posX] = 'E';
        map->exitBlock = 0;
        setExit(map, map->posX, map->posY);
    }
    else
        map->map[map->posY][map->posX] = '0';
    if(map->map[map->posY][newPos] == 'E')
        map->exitBlock = 1;
    map->posX = newPos;
    if(map->map[map->posY][map->posX] == 'V')
        quitGame(map);
    map->map[map->posY][map->posX] = 'P';
    changeCounter(map);
}

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
    changePlayerPosY(map, map->posY - 1);
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
    changePlayerPosX(map, map->posX - 1);
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
    changePlayerPosY(map, map->posY + 1);
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
    changePlayerPosX(map, map->posX + 1);
}