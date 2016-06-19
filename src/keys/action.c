/*
** callback.c for callback in /home/alies_a/rendu/gfx_raytracer2/src/keys
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Apr 20 14:07:00 2016 alies_a
** Last update Wed May 11 17:57:50 2016 Arthur Josso
*/

#include "core.h"
#include "keys.h"

#define MOVE_SPEED (0.1 / data->obj.mesh[0].meta.scale.x)

int	m1(t_data *data)
{
  if (data->obj.nb.mesh > 0)
    data->obj.mesh[0].meta.pos.x += MOVE_SPEED;
  return (0);
}

int	m2(t_data *data)
{
  if (data->obj.nb.mesh > 0)
    data->obj.mesh[0].meta.pos.x -= MOVE_SPEED;
  return (0);
}

int	m3(t_data *data)
{
  if (data->obj.nb.mesh > 0)
    data->obj.mesh[0].meta.pos.y += MOVE_SPEED;
  return (0);
}

int	m4(t_data *data)
{
  if (data->obj.nb.mesh > 0)
    data->obj.mesh[0].meta.pos.y -= MOVE_SPEED;
  return (0);
}

int	m5(t_data *data)
{
  if (data->obj.nb.mesh > 0)
    data->obj.mesh[0].meta.pos.z += MOVE_SPEED;
  return (0);
}

int	m6(t_data *data)
{
  if (data->obj.nb.mesh > 0)
    data->obj.mesh[0].meta.pos.z -= MOVE_SPEED;
  return (0);
}

int     ma(t_data *data)
{
  if (data->obj.nb.mesh > 0)
    data->obj.mesh[0].meta.rot.x += 0.1;
  return (0);
}

int     mb(t_data *data)
{
  if (data->obj.nb.mesh > 0)
    data->obj.mesh[0].meta.rot.x -= 0.1;
  return (0);
}

int     mc(t_data *data)
{
  if (data->obj.nb.mesh > 0)
    data->obj.mesh[0].meta.rot.y += 0.1;
  return (0);
}

int     md(t_data *data)
{
  if (data->obj.nb.mesh > 0)
    data->obj.mesh[0].meta.rot.y -= 0.1;
  return (0);
}

int     me(t_data *data)
{
  if (data->obj.nb.mesh > 0)
    data->obj.mesh[0].meta.rot.z += 0.1;
  return (0);
}

int     mf(t_data *data)
{
  if (data->obj.nb.mesh > 0)
    data->obj.mesh[0].meta.rot.z -= 0.1;
  return (0);
}

int	z1(t_data *data)
{
  if (data->obj.nb.mesh > 0 && data->obj.mesh[0].meta.scale.x < 1)
    {
      data->obj.mesh[0].meta.scale.x += 0.01;
      data->obj.mesh[0].meta.scale.y += 0.01;
      data->obj.mesh[0].meta.scale.z += 0.01;
    }
  return (0);
}

int	z2(t_data *data)
{
  if (data->obj.nb.mesh > 0 && data->obj.mesh[0].meta.scale.x > 0.02)
    {
      data->obj.mesh[0].meta.scale.x -= 0.01;
      data->obj.mesh[0].meta.scale.y -= 0.01;
      data->obj.mesh[0].meta.scale.z -= 0.01;
    }
  return (0);
}
