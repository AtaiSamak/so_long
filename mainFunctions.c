#include "so_long.h"

void     findPlayerPos(t_map *map)
{
    int     i;
    int     j;

    i = 0;
    map->posY = 0;
    map->posX = 0;
    while(++i < map->height)
    {
        j = 0;
        while(++j < map->width)
        {
            if(map->map[i][j] == 'P')
            {
                map->posY = i;
                map->posX = j;
                return ;
            }
        }
    }
    return ;
}

int    quitGame(t_map *map)
{
    mlx_destroy_window(map->mlx, map->win);
    freeMapStruct(map);
    exit(1);
}

int    playerActs(int keycode, t_map *map)
{
    printf("key = %d\n", keycode);
    if(keycode == 13)
        moveUp(map);
    else if(keycode == 0)
        moveLeft(map);
    else if(keycode == 1)
        moveDown(map);
    else if(keycode == 2)
        moveRight(map);
    else if(keycode == 53)
        quitGame(map);
    displayConsole(map);
    return(1);
}

int     workMap(t_map *map)
{
    if(checkMapItems(map) == -1)
    {
        printf("Error map items\n");
        return(-1);
    }
    if(checkMapWalls(map) == -1)
    {
        printf("Error map walls\n");
        return(-1);
    }
    if(checkPresItems(map) == -1)
    {
        printf("Error presence items\n");
        return(-1);
    }
    findPlayerPos(map);
    openWindow(map);
    initItems(map);
    setItems(map);
    mlx_key_hook(map->win, playerActs, map);
    mlx_hook(map->win, 17, 0, quitGame, map);
    mlx_loop(map->mlx);
    displayConsole(map);
	freeMapStruct(map);
    return(1);
}