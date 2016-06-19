/*
** tekline.c for fdf in /home/josso_a/rendu/info/gfx_fdf1/src
** 
** Made by josso_a
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Nov 10 14:02:07 2015 josso_a
** Last update Wed May 11 16:17:27 2016 Arthur Josso
*/

#include <lapin.h>
#include "rt.h"

typedef struct s_line
{
  float		x1;
  float		y1;
  float		x2;
  float		y2;
  float                 x;
  float                 y;
  float                 coeff;
  t_bunny_position      act;
  t_bunny_position      pos[2];
} t_line;

void			swap_pos2(t_bunny_position *pos,
				 t_bunny_position *coord,
				 int re)
{
  t_bunny_position      buff;

  if (!re)
    {
      if (coord[0].x > coord[1].x)
        {
          pos[1] = coord[0];
          pos[0] = coord[1];
        }
      else
        {
          pos[0] = coord[0];
          pos[1] = coord[1];
        }
    }
  else
    {
      buff = pos[1];
      pos[1] = pos[0];
      pos[0] = buff;
    }
}

void    sub_setline2(t_line *l,
                    t_bunny_pixelarray *pix,
                    t_bunny_position *coord,
                    t_color *color)
{
  if (l->coeff < -1)
    swap_pos2(l->pos, coord, 1);
  l->x = l->pos[0].x;
  l->y = l->pos[0].y;
  if (l->coeff > 1 || l->coeff < -1)
    while (l->y <= l->pos[1].y)
      {
        l->act.x = l->x + 0.5;
        l->act.y = l->y + 0.5;
        tekpixel(pix, &(l->act), color);
        l->x += 1 / l->coeff;
        l->y += 1;
      }
  else
    while (l->x <= l->pos[1].x)
      {
        l->act.x = l->x + 0.5;
        l->act.y = l->y + 0.5;
        tekpixel(pix, &(l->act), color);
        l->x += 1;
        l->y += l->coeff;
      }
}

void	       	tekline(t_bunny_pixelarray *pix,
			t_bunny_position *coord,
			t_color *color)
{
  t_line	l;

  l.x1 = (float)coord[0].x;
  l.y1 = (float)coord[0].y;
  l.x2 = (float)coord[1].x;
  l.y2 = (float)coord[1].y;
  swap_pos2(l.pos, coord, 0);
  if (l.pos[0].x == l.pos[1].x)
    {
      if (l.pos[0].y > l.pos[1].y)
        swap_pos2(l.pos, coord, 1);
      while (l.pos[0].y < l.pos[1].y)
        {
          tekpixel(pix, &(l.pos[0]), color);
          l.pos[0].y += 1;
        }
    }
  else
    {
      l.coeff = (((float)l.pos[1].y - (float)l.pos[0].y) /
                 ((float)l.pos[1].x - (float)l.pos[0].x));
      sub_setline2(&l, pix, coord, color);
    }
}
