#include <date/date.h>

void
jour_suivant (self)
  struct date *self;
{
  if ((self->mois == SANCULOTTIDES && (self->jour >= (self->sextile ? 6 : 5)))
      || self->jour >= 30)
    {
      mois_suivant (self);
      self->jour = 1;
    }
  else
    self->jour++; 
}
