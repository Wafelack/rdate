#include <date/date.h>

struct date
date_par_defaut (void)
{
  struct date date;

  date.jour   = 11;
  date.mois   = NIVOSE;
  date.an     = 178;
  date.heure   = 0;
  date.minute  = 0;
  date.seconde = 0;
  date.sextile = false;
  
  return date;
}
