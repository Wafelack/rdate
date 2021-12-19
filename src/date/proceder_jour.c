#include <date/date.h>

uint64_t
proceder_jour (self, s)
  struct date *self;
  uint64_t s;
{
  if (s >= SPJ)
    {
      jour_suivant (self);
      s -= SPJ;
    }
  return s;
}
