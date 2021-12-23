#include <date.h>

uint64_t
proceder_heure (self, s)
  struct date *self;
  uint64_t s;
{
  if (s >= SPH)
    {
      heure_suivante (self);
      s -= SPH;
    }
  return s;
}
