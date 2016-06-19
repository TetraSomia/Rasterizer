/*
** main.c for rt in /home/josso/en_cours/rt
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jan 29 18:33:22 2016 Arthur Josso
** Last update Thu May 19 18:03:23 2016 Arthur Josso
*/

#include "rt.h"
#include "keys.h"

t_bunny_response        mainloop(void *pt_data)
{
  t_data		*data;
  t_bunny_position	origin;

  origin.x = 0;
  origin.y = 0;
  data = (t_data*)pt_data;
  put_in_black(data->pix);
  gen_scene(data);
  manage_keys(data);
  bunny_blit(&data->win->buffer, &data->pix->clipable, &origin);
  bunny_display(data->win);
  return (GO_ON);
}

int		main(int ac, char **av)
{
  t_data	data;

  bunny_set_maximum_ram(1e9);
  if (ac < 2 || init(&data, av[1]) == ERROR)
    return (ERROR);
  bunny_set_key_response(&update_keys);
  bunny_set_loop_main_function(mainloop);
  bunny_loop(data.win, FPS, &data);
  exit_prog(&data);
  return (SUCCESS);
}
