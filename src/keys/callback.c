/*
** callback.c for callback in /home/alies_a/rendu/gfx_raytracer2/src/keys
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Apr 20 14:07:00 2016 alies_a
** Last update Sat May 21 16:25:18 2016 Arthur Josso
*/

#include "core.h"
#include "keys.h"

static t_key_callback	g_callbacks[] = {
  {BKS_A, &m1, 0},
  {BKS_D, &m2, 0},
  {BKS_S, &m3, 0},
  {BKS_W, &m4, 0},
  {BKS_R, &m5, 0},
  {BKS_F, &m6, 0},
  {BKS_UP, &ma, 0},
  {BKS_DOWN, &mb, 0},
  {BKS_PAGEUP, &mc, 0},
  {BKS_PAGEDOWN, &md, 0},
  {BKS_LEFT, &me, 0},
  {BKS_RIGHT, &mf, 0},
  {BKS_DASH, &z2, 0},
  {BKS_EQUAL, &z1, 0},
  {BKS_ESCAPE, &key_esc, 1},
  {BKS_UNKNOWN, NULL, 0}
};

t_bunny_response	update_keys(t_bunny_event_state state,
				    t_bunny_keysym keysym,
				    void *pt_data)
{
  int			x;

  (void)keysym;
  ((t_data*)pt_data)->keys = bunny_get_keyboard();
  x = 0;
  while (g_callbacks[x].callback != NULL)
    {
      if (g_callbacks[x].instant &&
	  keysym == g_callbacks[x].type && state == GO_DOWN)
	{
	  if (g_callbacks[x].callback((t_data*)pt_data))
	    return (EXIT_ON_SUCCESS);
	}
      x += 1;
    }
  return (GO_ON);
}

void		manage_keys(t_data *data)
{
  int		x;

  if (data->keys == NULL)
    return ;
  x = 0;
  while (g_callbacks[x].callback != NULL)
    {
      if (!g_callbacks[x].instant && data->keys[g_callbacks[x].type])
	g_callbacks[x].callback(data);
      x += 1;
    }
  return ;
}
