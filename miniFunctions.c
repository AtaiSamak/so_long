#include "so_long.h"

void	freeMapStruct(t_map *map)
{
	int i;

	i = 0;
	while(i < map->height)
		free(map->map[i++]);
	free(map->map);
}

void	displayConsole(t_map *map)
{
	int i;

	i = 0;
	while(i < map->height)
	{
		printf("%s\n", map->map[i]);
		i++;
	}
}