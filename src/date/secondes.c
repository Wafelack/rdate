#include <date.h>
#include <math.h>
#include <stdio.h>

struct date
depuis_secondes (s)
  uint64_t s;
{
  struct date   date;
  uint64_t      d = 0;
  double        is;
  
  /* Convertir les secondes du calendrier Grégorien en secondes du calendrier
   * Républicain.
   */
  is = (double) s / ((double) 60 * 60 * 24); /* Secondes par jour grégorien */
  is *= (double) SPJ; /* Secondes par jour républicain */
  s = d = (uint64_t) round (is);

  date = date_par_defaut ();

  do
    {
      s = d;
      d = proceder_an (&date, s);
    }
  while (d != s);

  do
    {
      s = d;
      d = proceder_mois (&date, s);
    }
  while (d != s);
  
  do
    {
      s = d;
      d = proceder_jour (&date, s);
    }
  while (d != s);
  

  do
    {
      s = d;
      d = proceder_heure (&date, s);
    }
  while (d != s);

   do
    {
      s = d;
      d = proceder_minute (&date, s);
    }
  while (d != s);

  while (s > 0)
    {
      s--;
      seconde_suivante (&date);
    }

  return date;
}
