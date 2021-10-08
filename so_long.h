/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahsoka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 23:18:26 by bahsoka           #+#    #+#             */
/*   Updated: 2021/10/08 23:18:28 by bahsoka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 10000

# include "stdio.h"
# include "stdlib.h"
# include "fcntl.h"
# include "unistd.h"
# include "mlx.h"

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		i;
	int		j;
	int		posX;
	int		posY;
	int		coins;
	int		exitBlock;

	void	*player;
	void	*exit;
	void	*coll;
	void	*wall;
	void	*bg;
	void	*pl_front;
	void	*pl_up;
	void	*pl_left;
	void	*pl_right;
	int		moves;

	void	*enemy;
	int		enemyExist;
	int		ePosY;
	int		ePosX;

	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	int		blockSize;
}				t_map;

void	setWidth(char *temp_map, t_map *map);
void	setHeight(char *temp_map, t_map *map);
int		allocateMem(t_map *map);
int		writeMapToArr(char *temp_map, t_map *map);
int		checkMapSizes(char *temp_map, t_map *map);
void	freeMapStruct(t_map *map);
void	displayConsole(t_map *map);
int		workMap(t_map *map);
int		checkPresItems(t_map *map);
int		checkMapWalls(t_map *map);
int		checkMapItems(t_map *map);
void	setItems(t_map *map);
void	putItem(t_map *map, int y, int x, char type);
void	initItems(t_map *map);
int		openWindow(t_map *map);
void	moveUp(t_map *map);
int		quitGame(t_map *map);
void	moveLeft(t_map *map);
void	moveDown(t_map *map);
void	moveRight(t_map *map);
char	*ft_itoa(int n);
char	whereMoveEnemy(t_map *map);
void	moveEnemy(t_map *map, int y, int x);
void	enemyActs(t_map *map);
int		enemyExist(t_map *map);
int		moreOneEnemy(t_map *map);
void	changePlayerPosY(t_map *map, int newPos);
void	changeCounter(t_map *map);
void	setExit(t_map *map, int x, int y);

#endif
