/*
** height.c for height in /home/alies_a/rendu/gfx_raytracer2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Apr 20 14:36:25 2016 alies_a
** Last update Wed Apr 20 16:41:12 2016 alies_a
*/

#include "rt.h"
#include "core.h"

int     key_up(t_data *data)
{
  (data->obj.cam).pos.z += MOVE;
  return (0);
}

int     key_down(t_data *data)
{
  (data->obj.cam).pos.z -= MOVE;
  return (0);
}

