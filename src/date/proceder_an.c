#include <date.h>

uint64_t
proceder_an (self, s)
  struct date *self;
  uint64_t s;
{
  uint64_t a_soustraire;

  a_soustraire = (self->sextile ? 366 : 365) * SPJ;
  if (s >= a_soustraire)
    {
      annee_suivante (self);
      s -= a_soustraire;
    }
  return s;
}
