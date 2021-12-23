#include <date.h>
#include <stdio.h>

struct date
depuis_secondes (s)
  uint64_t s;
{
  struct date   date;
  uint64_t      d;

  date = date_par_defaut ();

  d = proceder_an(&date, s);
  while (d != s)
    {
      s = d;
      d = proceder_an (&date, s);
    }

  s = d;
  d = proceder_mois (&date, s);
  while (d != s)
    {
      s = d;
      d = proceder_mois (&date, s);
    }
  
  s = d;
  d = proceder_jour (&date, s);
  while (d != s)
    {
      s = d;
      d = proceder_jour (&date, s);
    }
  
  s = d;
  d = proceder_heure (&date, s);
  while (d != s)
    {
      s = d;
      d = proceder_heure (&date, s);
    }
  
  s = d;
  d = proceder_minute (&date, s);
  while (d != s)
    {
      s = d;
      d = proceder_minute (&date, s);
    }

  s = d;
  while (s > 0)
    {
      s--;
      seconde_suivante (&date);
    }

  return date;
}
