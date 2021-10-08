#include "so_long.h"

char     whereMoveEnemy(t_map *map)
{
    if(map->posY > map->ePosY && (map->map[map->ePosY + 1][map->ePosX] == '0' || \
    map->map[map->ePosY + 1][map->ePosX] == 'P'))
        return ('S');
    else if(map->posY < map->ePosY && (map->map[map->ePosY - 1][map->ePosX] == '0' || \
    map->map[map->ePosY - 1][map->ePosX] == 'P'))
        return ('W');
    else if(map->posX > map->ePosX && (map->map[map->ePosY][map->ePosX + 1] == '0' || \
    map->map[map->ePosY][map->ePosX + 1] == 'P'))
        return ('D');
    else if(map->posX < map->ePosX && (map->map[map->ePosY][map->ePosX - 1] == '0' || \
    map->map[map->ePosY][map->ePosX - 1] == 'P'))
        return ('A');
    else
        return ('N');
}

void    moveEnemy(t_map *map, int y, int x)
{
    map->map[map->ePosY][map->ePosX] = '0';
    mlx_put_image_to_window(map->mlx, map->win, map->bg, map->ePosX * map->blockSize, map->ePosY * map->blockSize);
    map->ePosX = x;
    map->ePosY = y;
    if(map->map[map->ePosY][map->ePosX] == 'P')
        quitGame(map);
    map->map[map->ePosY][map->ePosX] = 'V';
    mlx_put_image_to_window(map->mlx, map->win, map->enemy, map->ePosX * map->blockSize, map->ePosY * map->blockSize);
}

void    enemyActs(t_map *map)
{
    char move;

    move = whereMoveEnemy(map);
    if(move == 'W')
        moveEnemy(map, map->ePosY - 1, map->ePosX);
    else if(move == 'S')
        moveEnemy(map, map->ePosY + 1, map->ePosX);
    else if(move == 'D')
        moveEnemy(map, map->ePosY, map->ePosX + 1);
    else if(move == 'A')
        moveEnemy(map, map->ePosY, map->ePosX - 1);
    else
        return ;
}

int     enemyExist(t_map *map)
{
    map->i = -1;
    map->enemyExist = 0;
    while(++map->i < map->height)
    {
        map->j = -1;
        while(++map->j < map->width)
            if(map->map[map->i][map->j] == 'V')
            {
                map->ePosY = map->i;
                map->ePosX = map->j;
                return (1);
            }
    }
    return(0);
}

int     moreOneEnemy(t_map *map)
{
    int enemies;

    enemies = 0;
    map->i = -1;
    while(++map->i < map->height)
    {
        map->j = -1;
        while(++map->j < map->width)
        {
            if(map->map[map->i][map->j] == 'V')
                enemies++;
        }
    }
    if(enemies > 1)
        return 1;
    return (0);
}