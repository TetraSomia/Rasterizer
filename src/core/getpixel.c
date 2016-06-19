/*
** my_getpixel.c for gui in /home/josso/rendu/gfx/gfx_tekgui
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Feb  4 20:08:01 2016 Arthur Josso
** Last update Wed May 18 18:01:19 2016 Arthur Josso
*/

#include "core.h"

t_color		get_pixel(t_bunny_pixelarray *pix, t_vec *pos)
{
  t_color       color;

  if (pos->x >= 0 && pos->x < pix->clipable.clip_width &&
      pos->y >= 0 && pos->y < pix->clipable.clip_height)
    color.full = ((unsigned int*)pix->pixels)
      [(int)pos->y * pix->clipable.clip_width + (int)pos->x];
  else
    color.full = 0;
  return (color);
}
