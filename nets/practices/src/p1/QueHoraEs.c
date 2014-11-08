/**
 * @file    QueHoraEs.c
 * @brief   Brief description.
 *
 * @author  Raul Perula-Martinez <raules@gmail.com>
 * @date    2014-11
 *
 * @license GPL v3
 * @version 1.0.0
 */
 
/* Programa que obtiene la hora del sistema */
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>


int main (){
  /* Utiliza las estructuras de datos timeval y timezone que están definidas en
   * sys/time.h */

  struct timeval tv;
  struct timezone tz;
  unsigned int s, m, h;

  gettimeofday (&tv, &tz);
  s = tv.tv_sec % 60;
  m = (tv.tv_sec / 60) % 60;
  h = (tv.tv_sec / 3600) % 24;
  /* La hora UTC - Hora Universal Coordinada - coincide con la hora oficial
   * española +1 en invierno, y +2 en verano */
  printf ("La hora UTC es: %02d:%02d:%02d.%05d\n", h, m, s, tv.tv_usec / 10);

  return h;
}
