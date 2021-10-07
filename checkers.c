#include "so_long.h"

int		checkMapSizes(char *temp_map,t_map *map)
{
	int		i;
	int		width;

	i = 0;
	width = 0;
	while(temp_map[i] != '\0')
	{
		if(temp_map[i] == '\n')
		{
			if(width != map->width)
				return(-1);
			width = 0;
			i++;
		}else {
			i++;
			width++;
		}
	}
	if(width != map->width)
		return(-1);
	return(1);
}

int     checkMapItems(t_map *map)
{
    int i;
    int j;

    i = 0;
    while(i < map->height)
    {
        j = 0;
        while(map->map[i][j] != '\0')
        {
            if(map->map[i][j] != '0' && map->map[i][j] != '1' \
            && map->map[i][j] != 'C' && map->map[i][j] != 'E' \
            && map->map[i][j] != 'P')
                return(-1);
            j++;
        }
        i++;
    }
    return(1);
}

int     checkMapWalls(t_map *map)
{
    int j;

    j = -1;
    while(map->map[0][++j] != '\0')
        if(map->map[0][j] != '1')
            return(-1);
    j = -1;
    while(map->map[map->height - 1][++j] != '\0')
        if(map->map[map->height - 1][j] != '1')
            return(-1);
    j = -1;
    while(++j < map->height)
        if(map->map[j][0] != '1')
            return(-1);
    j = -1;
    while(++j < map->height)
        if(map->map[j][map->width - 1] != '1')
            return(-1);
    return(1);
}

int     checkPresItems(t_map *map)
{
    int     pos;
    int     exit;
    int     coll;

    map->i = -1;
    pos = 0;
    exit = 0;
    coll = 0;
    while(++map->i < map->height)
    {
        map->j = -1;
        while(++map->j < map->width)
        {
            if(map->map[map->i][map->j] == 'P')
                pos++;
            if(map->map[map->i][map->j] == 'C')
                coll++;
            if(map->map[map->i][map->j] == 'E')
                exit++;
        }
    }
    if(pos != 1 || exit == 0 || coll == 0)
        return(-1);
    map->coins = coll;
    return(1);
}