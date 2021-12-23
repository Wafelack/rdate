#include <date.h>

void
mois_suivant (self)
  struct date *self;
{
  if (self->mois == SANCULOTTIDES)
    annee_suivante (self);
  self->mois = ((self->mois + 1) % MOIS);
}
