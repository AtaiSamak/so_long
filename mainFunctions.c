#include "so_long.h"

void     findPlayerPos(t_map *map)
{
    int     i;
    int     j;

    i = 0;
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
    displayConsole(map);
	freeMapStruct(map);
    return(1);
}