#include <date/date.h>

uint64_t
proceder_mois (self, s)
  struct date *self;
  uint64_t s;
{
  uint64_t a_soustraire;

  a_soustraire = ((self->mois == SANCULOTTIDES) ? (self->sextile ? 6 : 5) : 30) * SPJ;
  if (s >= a_soustraire)
    {
      mois_suivant (self);
      s -= a_soustraire;
    }
  return s;
}
