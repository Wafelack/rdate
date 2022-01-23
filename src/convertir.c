#include <time.h>
#include <convertir.h>

# include <stdio.h>
# include <string.h>

int
depuis_gregorien (date, fmt, ptr)
  const char  *date;
  const char  *fmt;
  struct date *ptr;
{
  struct tm representation;
  time_t tuc;
  char *erreur;

  memset (&representation, 0, sizeof (representation));

  erreur = strptime (date, fmt, &representation);
  if (erreur == NULL)
    return -1;

  tuc = timegm (&representation);
  
  *ptr = depuis_secondes (tuc);

  return 0;
}
